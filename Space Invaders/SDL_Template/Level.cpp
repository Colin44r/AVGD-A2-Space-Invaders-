#include "Level.h"

void Level::HandleStartLabels() {
	mLabelTimer += mTimer->DeltaTime();
	if (mLabelTimer >= mStageLabelOffScreen) {
		if (mStage > 1) {
			StartStage();
		}
		else {
			if (mLabelTimer >= mReadyLabelOffScreen) {
				StartStage();
				mPlayer->Active(true);
				mPlayer->Visible(true);
			}
		}
	}
}

void Level::HandleCollisions() {
	if (!mPlayerHit) {
		if (InputManager::Instance()->KeyPressed(SDL_SCANCODE_X)) {
			mPlayer->WasHit();
			mSideBar->SetLives(mPlayer->Lives());

			mPlayerHit = true;
			mRespawnTimer = 0.0f;
			mPlayer->Active(false);
		}
	}
}

void Level::HandlePlayerDeath() {
	if (!mPlayer->IsAnimating()) {
		if (mPlayer->Lives() > 0) {
			if (mRespawnTimer == 0.0f) {
				mPlayer->Visible(false);
			}

			mRespawnTimer += mTimer->DeltaTime();
			if (mRespawnTimer >= mRespawnDelay) {
				mPlayer->Active(true);
				mPlayer->Visible(true);
				mPlayerHit = false;
			}
		}
		else {
			if (mGameOverTimer == 0.0f) {
				mPlayer->Visible(false);
			}
			mGameOverTimer += mTimer->DeltaTime();
			if (mGameOverTimer >= mGameOverDelay) {
				mCurrentState = GameOver;
			}
		}
	}
}

void Level::StartStage() {
	mStageStarted = true;
}

Level::Level(int stage, PlaySideBar* sideBar, Player* player) {
	mTimer = Timer::Instance();
	mSideBar = sideBar;
	mSideBar->SetLevel(stage);

	mStage = stage;
	mStageStarted = false;

	mLabelTimer = 0.0f;

	mStageLabel = new Texture("STAGE", "emulogic.ttf", 32, { 75, 75, 200 });
	mStageLabel->Parent(this);
	mStageLabel->Position(Graphics::SCREEN_WIDTH * 0.35f, Graphics::SCREEN_HEIGHT * 0.5f);

	mStageNumber = new Scoreboard({ 75, 75, 200 });
	mStageNumber->Score(mStage);
	mStageNumber->Parent(this);
	mStageNumber->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f);

	mStageLabelOnScreen = 0.0f;
	mStageLabelOffScreen = 1.5f;

	mReadyLabel = new Texture("READY", "emulogic.ttf", 32, { 150, 0, 0 });
	mReadyLabel->Parent(this);
	mReadyLabel->Position(Graphics::SCREEN_WIDTH * 0.4f, Graphics::SCREEN_HEIGHT * 0.5f);

	mReadyLabelOnScreen = mStageLabelOffScreen;
	mReadyLabelOffScreen = mReadyLabelOnScreen + 3.0f;

	mPlayer = player;
	mPlayerHit = false;
	mRespawnDelay = 3.0f;
	mRespawnTimer = 0.0f;
	mRespawnLabelOnScreen = 2.0f;

	mGameOverLabel = new Texture("GAME OVER", "emulogic.ttf", 32, { 150, 0, 0 });
	mGameOverLabel->Parent(this);
	mGameOverLabel->Position(Graphics::SCREEN_WIDTH * 0.4f, Graphics::SCREEN_HEIGHT * 0.5f);

	mGameOverDelay = 6.0f;
	mGameOverTimer = 0.0f;
	mGameOverLabelOnScreen = 1.0f;

	mCurrentState = Running;

	std::string fullPath = SDL_GetBasePath();
	fullPath.append("Data/Level1.xml");
	mSpawningPatterns.LoadFile(fullPath.c_str());

	mChallengeStage = mSpawningPatterns.FirstChildElement("Level")->FirstChildElement()->BoolAttribute("value");

	if (!mChallengeStage) {
		mFormation = new Formation();
		mFormation->Position(Graphics::SCREEN_WIDTH * 0.4f, 150.0f);
		mFormation->Parent(this);
		Enemy::SetFormation(mFormation);

		for (Butterfly* b : mFormationButterflies) {
			b = nullptr;
		}
	}

	mCurrentFlyInPriority = 0;
	mCurrentFlyInIndex = 0;
	mSpawnDelay = 0.2f;
	mSpawnTimer = 0.0f;
	mSpawningFinished = false;

	mDivingButterfly = nullptr;
	mSkipFirstButterfly = false;
	mButterflyDiveDelay = 1.0f;
	mButterflyDiveTimer = 0.0f;
}

Level::~Level() {
	mTimer = nullptr;
	mSideBar = nullptr;

	delete mStageLabel;
	mStageLabel = nullptr;
	delete mStageNumber;
	mStageNumber = nullptr;
	delete mReadyLabel;
	mReadyLabel = nullptr;

	mPlayer = nullptr;

	delete mGameOverLabel;
	mGameOverLabel = nullptr;

	for (auto e : mEnemies) {
		delete e;
	}
	mEnemies.clear();

	for (Butterfly* b : mFormationButterflies) {
		delete b;
		b = nullptr;
	}
}

bool Level::EnemyFyingIn() {
	for (Butterfly* b : mFormationButterflies) {
		if (b != nullptr && b->CurrentState() == Enemy::FlyIn) {
			return true;
		}
	}

	return false;
}

Level::LevelStates Level::State() {
	return mCurrentState;
}

void Level::HandleEnemySpawning() {
	mSpawnTimer += mTimer->DeltaTime();

	if (mSpawnTimer >= mSpawnDelay) {
		XMLElement* element = mSpawningPatterns.FirstChildElement("Level")->FirstChild()->NextSiblingElement();

		bool spawned = false;
		bool priorityFound = false;

		while (element != nullptr) {
			int priority = element->IntAttribute("priority");

			if (mCurrentFlyInPriority == priority) {
				priorityFound = true;
				int path = element->IntAttribute("path");
				XMLElement* child = element->FirstChildElement();

				for (int i = 0; i < mCurrentFlyInIndex && child != nullptr; i++) {
					child = child->NextSiblingElement();
				}

				if (child != nullptr) {
					std::string type = child->Attribute("type");
					int index = child->IntAttribute("index");

					if (type.compare("Butterfly") == 0) {
						if (!mChallengeStage) {
							mFormationButterflies[index] = new Butterfly(path, index, false);
							mButterflyCount++;
						}
						else {
							mEnemies.push_back(new Butterfly(path, index, false));
						}
					}

					spawned = true;
				}
			}

			element = element->NextSiblingElement();
		}

		if (!priorityFound) {
			//no priorities found means no more spawn elements
			mSpawningFinished = true;
		}
		else {
			if (!spawned) {
				//You have spawn elements waiting but you didn't spawn anything!
				if (!EnemyFyingIn()) {
					mCurrentFlyInPriority += 1;
					mCurrentFlyInIndex = 0;
				}
			}
			else {
				//You haven't finished spawning this element's enemies, next index!
				mCurrentFlyInIndex += 1;
			}
		}
		mSpawnTimer = 0.0f;
	}
}

void Level::HandleEnemyFormation() {
	mFormation->Update();

	for (Butterfly* b : mFormationButterflies) {
		if (b != nullptr) {
			b->Update();
		}
	}

	if (!mFormation->Locked()) {
		if (mButterflyCount == MAX_BUTTERFLIES) {
			if (!EnemyFyingIn()) {
				mFormation->Lock();
			}
		}
	}
	else {
		HandleEnemyDiving();
	}
}

void Level::HandleEnemyDiving() {
	if (mDivingButterfly == nullptr) {
		mButterflyDiveTimer += mTimer->DeltaTime();

		if (mButterflyDiveTimer >= mButterflyDiveDelay) {
			bool skipped = false;

			//Look for a butterfly
			for (int i = MAX_BUTTERFLIES - 1; i >= 0; i--) {
				if (mFormationButterflies[i] != nullptr &&
					mFormationButterflies[i]->CurrentState() == Enemy::InFormation) {
					if (!mSkipFirstButterfly || (mSkipFirstButterfly && skipped)) {
						mDivingButterfly = mFormationButterflies[i];
						mDivingButterfly->Dive();
						mSkipFirstButterfly = !mSkipFirstButterfly;
						break;
					}
				}
				skipped = true;
			}

			mButterflyDiveTimer = 0.0f;
		}
	}
	else {
		if (mDivingButterfly->CurrentState() != Enemy::Diving) {
			mDivingButterfly = nullptr;
		}
	}

	//if (mFormation->Locked()) {
	//	if (InputManager::Instance()->KeyPressed(SDL_SCANCODE_B)) {
	//		for (auto e : mEnemies) {
	//			if (e->Type() == Enemy::Butterfly &&
	//				e->CurrentState() == Enemy::InFormation) {
	//				e->Dive();
	//				break;
	//			}
	//		}
	//	}
	//}
}



void Level::Update() {
	if (!mStageStarted) {
		HandleStartLabels();
	}
	else {
		if (!mSpawningFinished) {
			HandleEnemySpawning();
		}

		if (!mChallengeStage) {
			HandleEnemyFormation();
		}
		else {
			for (auto e : mEnemies) {
				e->Update();
			}
		}

		//HandleEnemyDiving();

		HandleCollisions();

		if (mPlayerHit) {
			HandlePlayerDeath();
		}
		else {
			if (InputManager::Instance()->KeyPressed(SDL_SCANCODE_N)) {
				mCurrentState = Finished;
			}
		}
	}
}

void Level::Render() {
	if (!mStageStarted) {
		if (mLabelTimer > mStageLabelOnScreen && mLabelTimer < mStageLabelOffScreen) {
			mStageLabel->Render();
			mStageNumber->Render();
		}
		else if (mLabelTimer > mReadyLabelOnScreen && mLabelTimer < mReadyLabelOffScreen) {
			mReadyLabel->Render();
		}
	}
	else {
		if (!mChallengeStage) {
			for (Butterfly* b : mFormationButterflies) {
				if (b != nullptr) {
					b->Render();
				}
			}
		}
		else {
			for (auto e : mEnemies) {
				e->Render();
			}
		}

		if (mPlayerHit) {
			if (mRespawnTimer >= mRespawnLabelOnScreen) {
				mReadyLabel->Render();
			}

			if (mGameOverTimer >= mGameOverLabelOnScreen) {
				mGameOverLabel->Render();
			}
		}
	}
}