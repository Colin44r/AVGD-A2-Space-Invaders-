#include "PlayScreen.h"

PlayScreen::PlayScreen(PlaySideBar*PlaySideBarPS) {
	mTimer = Timer::Instance();
	mAudio = AudioManager::Instance();
	mInputManager = InputManager::Instance();

	mSideBar = PlaySideBarPS;
	

	mStartLabel = new Texture("1 PLAYER", "emulogic.ttf", 32, { 230, 230, 230 });
	mStartLabel->Parent(this);
	mStartLabel->Position(Graphics::SCREEN_WIDTH * 0.4, Graphics::SCREEN_HEIGHT * 0.5f);
	mGreenSkull4 = new Texture("GeneralSprite.png", 9, 0, 8, 8);

	mTopSprites = new GameEntity();

	mTopSprites->Parent(this);
	mGreenSkull4->Parent(mTopSprites);

	mGreenSkull4->Position(0.0f, 170.0f);




	mLevel = nullptr;
	mLevelStartDelay = 1.0f;
	mLevelStarted = false;
	mPlayer = nullptr;
	

	Enemy::CreatePaths();
	Butterfly::CreateDivePaths();

}


PlayScreen::~PlayScreen() {
	mTimer = nullptr;
	mAudio = nullptr;


	delete mSideBar;
	mSideBar = nullptr;
	delete mStartLabel;
	mStartLabel = nullptr;
	delete mLevel;
	mLevel = nullptr;
	delete mPlayer;
	mPlayer = nullptr;
	delete mGreenSkull4;
	mGreenSkull4 = nullptr;
	delete mTopSprites;
	mTopSprites = nullptr;
}

void PlayScreen::Update() {
	if (mInputManager->KeyPressed(SDL_SCANCODE_Y)) {

		mPlayer->AddScore(100);
		std::cout << mPlayer->Score();
		mSideBar->SetPlayerScore(mPlayer->Score());

	}
	

	if (mInputManager->KeyPressed(SDL_SCANCODE_G)) {

		mPlayer->MinusLives(1);
		std::cout << mPlayer->Lives();
		mSideBar->SetLives(mPlayer->Lives());

	}


	if (mInputManager->KeyPressed(SDL_SCANCODE_H)) {

		mLevel->HandlePlayerDeath();
	
		// This is where the player will be told what to do when they die. aka general spirte sheet death
	}


	if (mGameStarted) {
		mPlayer->Update();
	

		if (!mLevelStarted) {
			mLevelStartTimer += mTimer->DeltaTime();
			if (mLevelStartTimer >= mLevelStartDelay) {
				StartNextLevel();
			}
		}
		else {
			mLevel->Update();
			if (mLevel->State() == Level::Finished) {
				mLevelStarted = false;
			}
		}

		if (mCurrentStage > 0) {
			mSideBar->Update();
		}
	}
	//else {
	//	if (!Mix_PlayingMusic()) {
	//		mGameStarted = true;
	//	}
	//}
}

void PlayScreen::Render() {
	if (!mGameStarted) {
		mStartLabel->Render();
	}

	if (mGameStarted) {

		if (mLevelStarted) {
			mLevel->Render();
		}

		mPlayer->Render();
	}

	mSideBar->Render();
	mGreenSkull4->Render();
}

void PlayScreen::StartNewGame() {
	delete mPlayer;
	mPlayer = new Player();
	mPlayer->Parent(this);
	mPlayer->Position(Graphics::SCREEN_WIDTH * 0.4, Graphics::SCREEN_HEIGHT * 0.8f);
	mPlayer->Active(false);

	//mSideBar->SetHighScore(30000);
	//mSideBar->SetShip(mPlayer->Lives());
	//mSideBar->SetPlayerScore(mPlayer->Score());
	//mSideBar->SetLevel(0);
	mGameStarted = false;
	mLevelStarted = false;
	mLevelStartTimer = 0;
	//mCurrentStage = 0;
	//mAudio->PlayMusic("", 0);
}

void PlayScreen::StartNextLevel() {
	//mCurrentStage += 1;
	mLevelStartTimer = 0.0f;
	mLevelStarted = true;

	delete mLevel;
	mLevel = new Level(mCurrentStage, mSideBar, mPlayer);
}

bool PlayScreen::GameOver() {
	return !mLevelStarted ? false : (mLevel->State() == Level::GameOver);
}