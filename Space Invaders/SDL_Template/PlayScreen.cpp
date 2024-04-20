#include "PlayScreen.h"

PlayScreen::PlayScreen(PlaySideBar*PlaySideBarPS) {
	mTimer = Timer::Instance();
	mAudio = AudioManager::Instance();
	mInputManager = InputManager::Instance();

	mSideBar = PlaySideBarPS;
	

	mStartLabel = new Texture("1 PLAYER", "emulogic.ttf", 32, { 230, 230, 230 });
	mStartLabel->Parent(this);
	mStartLabel->Position(Graphics::SCREEN_WIDTH * 0.4, Graphics::SCREEN_HEIGHT * 0.5f);
	mGreenSkull1 = new Texture("GeneralSprite.png", 120, 72, 8, 8);
	mGreenSkull2 = new Texture("GeneralSprite.png", 120, 72, 8, 8);
	mGreenSkull3 = new Texture("GeneralSprite.png", 120, 72, 8, 8);
	mGreenSkull4 = new Texture("GeneralSprite.png", 120, 72, 8, 8);
	mGreenSkull5 = new Texture("GeneralSprite.png", 120, 72, 8, 8);
	mGreenSkull6 = new Texture("GeneralSprite.png", 120, 72, 8, 8);
	mGreenSkull7 = new Texture("GeneralSprite.png", 120, 72, 8, 8);
	mGreenSkull8 = new Texture("GeneralSprite.png", 120, 72, 8, 8);
	mGreenSkull9 = new Texture("GeneralSprite.png", 120, 72, 8, 8);
	mGreenSkull10 = new Texture("GeneralSprite.png", 120, 72, 8, 8);
	mGreenSkull11 = new Texture("GeneralSprite.png", 120, 72, 8, 8);
	mRow2GreenSkull1 = new Texture("GeneralSprite.png", 9, 0, 8, 8);
	mRow2GreenSkull2 = new Texture("GeneralSprite.png", 9, 0, 8, 8);
	mRow2GreenSkull3 = new Texture("GeneralSprite.png", 9, 0, 8, 8);
	mRow2GreenSkull4 = new Texture("GeneralSprite.png", 9, 0, 8, 8);
	mRow2GreenSkull5 = new Texture("GeneralSprite.png", 9, 0, 8, 8);
	mRow2GreenSkull6 = new Texture("GeneralSprite.png", 9, 0, 8, 8);
	mRow2GreenSkull7 = new Texture("GeneralSprite.png", 9, 0, 8, 8);
	mRow2GreenSkull8 = new Texture("GeneralSprite.png", 9, 0, 8, 8);
	mRow2GreenSkull9 = new Texture("GeneralSprite.png", 9, 0, 8, 8);
	mRow2GreenSkull10 = new Texture("GeneralSprite.png", 9, 0, 8, 8);
	mRow2GreenSkull11 = new Texture("GeneralSprite.png", 9, 0, 8, 8);
	mBlueSkull1 = new Texture("GeneralSprite.png", 0, 45, 8, 8);
	mBlueSkull2 = new Texture("GeneralSprite.png", 0, 45, 8, 8);
	mBlueSkull3 = new Texture("GeneralSprite.png", 0, 45, 8, 8);
	mBlueSkull4 = new Texture("GeneralSprite.png", 0, 45, 8, 8);
	mBlueSkull5 = new Texture("GeneralSprite.png", 0, 45, 8, 8);
	mBlueSkull6 = new Texture("GeneralSprite.png", 0, 45, 8, 8);
	mBlueSkull7 = new Texture("GeneralSprite.png", 0, 45, 8, 8);
	mBlueSkull8 = new Texture("GeneralSprite.png", 0, 45, 8, 8);
	mBlueSkull9 = new Texture("GeneralSprite.png", 0, 45, 8, 8);
	mBlueSkull10 = new Texture("GeneralSprite.png", 0, 45, 8, 8);
	mBlueSkull11= new Texture("GeneralSprite.png", 0, 45, 8, 8);
	mRow2BlueSkull1 = new Texture("GeneralSprite.png", 0, 36, 8, 8);
	mRow2BlueSkull2 = new Texture("GeneralSprite.png", 0, 36, 8, 8);
	mRow2BlueSkull3 = new Texture("GeneralSprite.png", 0, 36, 8, 8);
	mRow2BlueSkull4 = new Texture("GeneralSprite.png", 0, 36, 8, 8);
	mRow2BlueSkull5 = new Texture("GeneralSprite.png", 0, 36, 8, 8);
	mRow2BlueSkull6 = new Texture("GeneralSprite.png", 0, 36, 8, 8);
	mRow2BlueSkull7 = new Texture("GeneralSprite.png", 0, 36, 8, 8);
	mRow2BlueSkull8 = new Texture("GeneralSprite.png", 0, 36, 8, 8);
	mRow2BlueSkull9 = new Texture("GeneralSprite.png", 0, 36, 8, 8);
	mRow2BlueSkull10 = new Texture("GeneralSprite.png", 0, 36, 8, 8);
	mRow2BlueSkull11 = new Texture("GeneralSprite.png", 0, 36, 8, 8);
	mPinkSkull1 = new Texture("GeneralSprite.png", 9, 72, 8, 8);
	mPinkSkull2 = new Texture("GeneralSprite.png", 9, 72, 8, 8);
	mPinkSkull3 = new Texture("GeneralSprite.png", 9, 72, 8, 8);
	mPinkSkull4 = new Texture("GeneralSprite.png", 9, 72, 8, 8);
	mPinkSkull5 = new Texture("GeneralSprite.png", 9, 72, 8, 8);
	mPinkSkull6 = new Texture("GeneralSprite.png", 9, 72, 8, 8);
	mPinkSkull7 = new Texture("GeneralSprite.png", 9, 72, 8, 8);
	mPinkSkull8 = new Texture("GeneralSprite.png", 9, 72, 8, 8);
	mPinkSkull9 = new Texture("GeneralSprite.png", 9, 72, 8, 8);
	mPinkSkull10 = new Texture("GeneralSprite.png", 9, 72, 8, 8);
	mPinkSkull11 = new Texture("GeneralSprite.png", 9, 72, 8, 8);
	mRedBlockade1 = new Texture("GeneralSprite.png", 112, 126, 24, 24);
	mRedBlockade2 = new Texture("GeneralSprite.png", 112, 126, 24, 24);
	mRedBlockade3 = new Texture("GeneralSprite.png", 112, 126, 24, 24);
	mRedBlockade4 = new Texture("GeneralSprite.png", 112, 126, 24, 24);
	















	mTopSprites = new GameEntity();

	mTopSprites->Parent(this);
	mGreenSkull1->Parent(mTopSprites);
	mGreenSkull2->Parent(mTopSprites);
	mGreenSkull3->Parent(mTopSprites);
	mGreenSkull4->Parent(mTopSprites);
	mGreenSkull5->Parent(mTopSprites);
	mGreenSkull6->Parent(mTopSprites);
	mGreenSkull7->Parent(mTopSprites);
	mGreenSkull8->Parent(mTopSprites);
	mGreenSkull9->Parent(mTopSprites);
	mGreenSkull10->Parent(mTopSprites);
	mGreenSkull11->Parent(mTopSprites);
	mRow2GreenSkull1->Parent(mTopSprites);
	mRow2GreenSkull2->Parent(mTopSprites);
	mRow2GreenSkull3->Parent(mTopSprites);
	mRow2GreenSkull4->Parent(mTopSprites);
	mRow2GreenSkull5->Parent(mTopSprites);
	mRow2GreenSkull6->Parent(mTopSprites);
	mRow2GreenSkull7->Parent(mTopSprites);
	mRow2GreenSkull8->Parent(mTopSprites);
	mRow2GreenSkull9->Parent(mTopSprites);
	mRow2GreenSkull10->Parent(mTopSprites);
	mRow2GreenSkull11->Parent(mTopSprites);
	mBlueSkull1->Parent(mTopSprites);
	mBlueSkull2->Parent(mTopSprites);
	mBlueSkull3->Parent(mTopSprites);
	mBlueSkull4->Parent(mTopSprites);
	mBlueSkull5->Parent(mTopSprites);
	mBlueSkull6->Parent(mTopSprites);
	mBlueSkull7->Parent(mTopSprites);
	mBlueSkull8->Parent(mTopSprites);
	mBlueSkull9->Parent(mTopSprites);
	mBlueSkull10->Parent(mTopSprites);
	mBlueSkull11->Parent(mTopSprites);
	mRow2BlueSkull1->Parent(mTopSprites);
	mRow2BlueSkull2->Parent(mTopSprites);
	mRow2BlueSkull3->Parent(mTopSprites);
	mRow2BlueSkull4->Parent(mTopSprites);
	mRow2BlueSkull5->Parent(mTopSprites);
	mRow2BlueSkull6->Parent(mTopSprites);
	mRow2BlueSkull7->Parent(mTopSprites);
	mRow2BlueSkull8->Parent(mTopSprites);
	mRow2BlueSkull9->Parent(mTopSprites);
	mRow2BlueSkull10->Parent(mTopSprites);
	mRow2BlueSkull11->Parent(mTopSprites);
	mPinkSkull1->Parent(mTopSprites);
	mPinkSkull2->Parent(mTopSprites);
	mPinkSkull3->Parent(mTopSprites);
	mPinkSkull4->Parent(mTopSprites);
	mPinkSkull5->Parent(mTopSprites);
	mPinkSkull6->Parent(mTopSprites);
	mPinkSkull7->Parent(mTopSprites);
	mPinkSkull8->Parent(mTopSprites);
	mPinkSkull9->Parent(mTopSprites);
	mPinkSkull10->Parent(mTopSprites);
	mPinkSkull11->Parent(mTopSprites);
	mRedBlockade1->Parent(mTopSprites);
	mRedBlockade2->Parent(mTopSprites);
	mRedBlockade3->Parent(mTopSprites);
	mRedBlockade4->Parent(mTopSprites);

	mGreenSkull1->Scale(Vector2(3.75f, 3.15f));
	mGreenSkull2->Scale(Vector2(3.75f, 3.15f));
	mGreenSkull3->Scale(Vector2(3.75f, 3.15f));
	mGreenSkull4->Scale(Vector2(3.75f, 3.15f));
	mGreenSkull5->Scale(Vector2(3.75f, 3.15f));
	mGreenSkull6->Scale(Vector2(3.75f, 3.15f));
	mGreenSkull7->Scale(Vector2(3.75f, 3.15f));
	mGreenSkull8->Scale(Vector2(3.75f, 3.15f));
	mGreenSkull9->Scale(Vector2(3.75f, 3.15f));
	mGreenSkull10->Scale(Vector2(3.75f, 3.15f));
	mGreenSkull11->Scale(Vector2(3.75f, 3.15f));
	mRow2GreenSkull1->Scale(Vector2(3.75f, 3.15f));
	mRow2GreenSkull2->Scale(Vector2(3.75f, 3.15f));
	mRow2GreenSkull3->Scale(Vector2(3.75f, 3.15f));
	mRow2GreenSkull4->Scale(Vector2(3.75f, 3.15f));
	mRow2GreenSkull5->Scale(Vector2(3.75f, 3.15f));
	mRow2GreenSkull6->Scale(Vector2(3.75f, 3.15f));
	mRow2GreenSkull7->Scale(Vector2(3.75f, 3.15f));
	mRow2GreenSkull8->Scale(Vector2(3.75f, 3.15f));
	mRow2GreenSkull9->Scale(Vector2(3.75f, 3.15f));
	mRow2GreenSkull10->Scale(Vector2(3.75f, 3.15f));
	mRow2GreenSkull11->Scale(Vector2(3.75f, 3.15f));
	mBlueSkull1->Scale(Vector2(3.75f, 3.15f));
	mBlueSkull2->Scale(Vector2(3.75f, 3.15f));
	mBlueSkull3->Scale(Vector2(3.75f, 3.15f));
	mBlueSkull4->Scale(Vector2(3.75f, 3.15f));
	mBlueSkull5->Scale(Vector2(3.75f, 3.15f));
	mBlueSkull6->Scale(Vector2(3.75f, 3.15f));
	mBlueSkull7->Scale(Vector2(3.75f, 3.15f));
	mBlueSkull8->Scale(Vector2(3.75f, 3.15f));
	mBlueSkull9->Scale(Vector2(3.75f, 3.15f));
	mBlueSkull10->Scale(Vector2(3.75f, 3.15f));
	mBlueSkull11->Scale(Vector2(3.75f, 3.15f));
	mRow2BlueSkull1->Scale(Vector2(3.75f, 3.15f));
	mRow2BlueSkull2->Scale(Vector2(3.75f, 3.15f));
	mRow2BlueSkull3->Scale(Vector2(3.75f, 3.15f));
	mRow2BlueSkull4->Scale(Vector2(3.75f, 3.15f));
	mRow2BlueSkull5->Scale(Vector2(3.75f, 3.15f));
	mRow2BlueSkull6->Scale(Vector2(3.75f, 3.15f));
	mRow2BlueSkull7->Scale(Vector2(3.75f, 3.15f));
	mRow2BlueSkull8->Scale(Vector2(3.75f, 3.15f));
	mRow2BlueSkull9->Scale(Vector2(3.75f, 3.15f));
	mRow2BlueSkull10->Scale(Vector2(3.75f, 3.15f));
	mRow2BlueSkull11->Scale(Vector2(3.75f, 3.15f));
	mBlueSkull1->Scale(Vector2(3.75f, 3.15f));
	mBlueSkull2->Scale(Vector2(3.75f, 3.15f));
	mBlueSkull3->Scale(Vector2(3.75f, 3.15f));
	mBlueSkull4->Scale(Vector2(3.75f, 3.15f));
	mBlueSkull5->Scale(Vector2(3.75f, 3.15f));
	mBlueSkull6->Scale(Vector2(3.75f, 3.15f));
	mBlueSkull7->Scale(Vector2(3.75f, 3.15f));
	mBlueSkull8->Scale(Vector2(3.75f, 3.15f));
	mBlueSkull9->Scale(Vector2(3.75f, 3.15f));
	mBlueSkull10->Scale(Vector2(3.75f, 3.15f));
	mBlueSkull11->Scale(Vector2(3.75f, 3.15f));
	mRow2BlueSkull1->Scale(Vector2(3.75f, 3.15f));
	mRow2BlueSkull2->Scale(Vector2(3.75f, 3.15f));
	mRow2BlueSkull3->Scale(Vector2(3.75f, 3.15f));
	mRow2BlueSkull4->Scale(Vector2(3.75f, 3.15f));
	mRow2BlueSkull5->Scale(Vector2(3.75f, 3.15f));
	mRow2BlueSkull6->Scale(Vector2(3.75f, 3.15f));
	mRow2BlueSkull7->Scale(Vector2(3.75f, 3.15f));
	mRow2BlueSkull8->Scale(Vector2(3.75f, 3.15f));
	mRow2BlueSkull9->Scale(Vector2(3.75f, 3.15f));
	mRow2BlueSkull10->Scale(Vector2(3.75f, 3.15f));
	mRow2BlueSkull11->Scale(Vector2(3.75f, 3.15f));
	mPinkSkull1->Scale(Vector2(3.75f, 3.15f));
	mPinkSkull2->Scale(Vector2(3.75f, 3.15f));
	mPinkSkull3->Scale(Vector2(3.75f, 3.15f));
	mPinkSkull4->Scale(Vector2(3.75f, 3.15f));
	mPinkSkull5->Scale(Vector2(3.75f, 3.15f));
	mPinkSkull6->Scale(Vector2(3.75f, 3.15f));
	mPinkSkull7->Scale(Vector2(3.75f, 3.15f));
	mPinkSkull8->Scale(Vector2(3.75f, 3.15f));
	mPinkSkull9->Scale(Vector2(3.75f, 3.15f));
	mPinkSkull10->Scale(Vector2(3.75f, 3.15f));
	mPinkSkull11->Scale(Vector2(3.75f, 3.15f));
	mRedBlockade1->Scale(Vector2(4.25f, 3.55f));
	mRedBlockade2->Scale(Vector2(4.25f, 3.55f));
	mRedBlockade3->Scale(Vector2(4.25f, 3.55f));
	mRedBlockade4->Scale(Vector2(4.25f, 3.55f));



	mGreenSkull1->Position(125.0f, 150.0f);
	mGreenSkull2->Position(205.0f, 150.0f);
	mGreenSkull3->Position(285.0f, 150.0f);
	mGreenSkull4->Position(365.0f, 150.0f);
	mGreenSkull5->Position(445.0f, 150.0f);
	mGreenSkull6->Position(525.0f, 150.0f);
	mGreenSkull7->Position(605.0f, 150.0f);
	mGreenSkull8->Position(685.0f, 150.0f);
	mGreenSkull9->Position(765.0f, 150.0f);
	mGreenSkull10->Position(845.0f, 150.0f);
	mGreenSkull11->Position(925.0f, 150.0f);
	mRow2GreenSkull1->Position(125.0f, 210.0f);
	mRow2GreenSkull2->Position(205.0f, 210.0f);
	mRow2GreenSkull3->Position(285.0f, 210.0f);
	mRow2GreenSkull4->Position(365.0f, 210.0f);
	mRow2GreenSkull5->Position(445.0f, 210.0f);
	mRow2GreenSkull6->Position(525.0f, 210.0f);
	mRow2GreenSkull7->Position(605.0f, 210.0f);
	mRow2GreenSkull8->Position(685.0f, 210.0f);
	mRow2GreenSkull9->Position(765.0f, 210.0f);
	mRow2GreenSkull10->Position(845.0f, 210.0f);
	mRow2GreenSkull11->Position(925.0f, 210.0f);
	mBlueSkull1->Position(125.0f, 260.0f);
	mBlueSkull2->Position(205.0f, 260.0f);
	mBlueSkull3->Position(285.0f, 260.0f);
	mBlueSkull4->Position(365.0f, 260.0f);
	mBlueSkull5->Position(445.0f, 260.0f);
	mBlueSkull6->Position(525.0f, 260.0f);
	mBlueSkull7->Position(605.0f, 260.0f);
	mBlueSkull8->Position(685.0f, 260.0f);
	mBlueSkull9->Position(765.0f, 260.0f);
	mBlueSkull10->Position(845.0f, 260.0f);
	mBlueSkull11->Position(925.0f, 260.0f);
	mRow2BlueSkull1->Position(125.0f, 320.0f);
	mRow2BlueSkull2->Position(205.0f, 320.0f);
	mRow2BlueSkull3->Position(285.0f, 320.0f);
	mRow2BlueSkull4->Position(365.0f, 320.0f);
	mRow2BlueSkull5->Position(445.0f, 320.0f);
	mRow2BlueSkull6->Position(525.0f, 320.0f);
	mRow2BlueSkull7->Position(605.0f, 320.0f);
	mRow2BlueSkull8->Position(685.0f, 320.0f);
	mRow2BlueSkull9->Position(765.0f, 320.0f);
	mRow2BlueSkull10->Position(845.0f, 320.0f);
	mRow2BlueSkull11->Position(925.0f, 320.0f);
	mPinkSkull1->Position(125.0f, 380.0f);
	mPinkSkull2->Position(205.0f, 380.0f);
	mPinkSkull3->Position(285.0f, 380.0f);
	mPinkSkull4->Position(365.0f, 380.0f);
	mPinkSkull5->Position(445.0f, 380.0f);
	mPinkSkull6->Position(525.0f, 380.0f);
	mPinkSkull7->Position(605.0f, 380.0f);
	mPinkSkull8->Position(685.0f, 380.0f);
	mPinkSkull9->Position(765.0f, 380.0f);
	mPinkSkull10->Position(845.0f, 380.0f);
	mPinkSkull11->Position(925.0f, 380.0f);
	mRedBlockade1->Position(200.0f, 630.0f);
	mRedBlockade2->Position(400.0f, 630.0f);
	mRedBlockade3->Position(600.0f, 630.0f);
	mRedBlockade4->Position(800.0f, 630.0f);

	//TODO: Create spawn in animation
	//TODO: Make Little aliens moving and grooving 
	//TODO: Add collation to bullets, enemies and the big U red things you know what im talking about im too tired at this point
	

	mLevel = nullptr;
	mLevelStartDelay = 0.30f; // This is where the timer value of delay of 1 player is adujusted 
	mLevelStarted = false;
	mPlayer = nullptr;
	mGameoverCall = false;

	mTriggerPlayerDeath = false;
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
	delete mTopSprites;
	mTopSprites = nullptr;
	delete mGreenSkull1;
	mGreenSkull1 = nullptr;
	delete mGreenSkull2;
	mGreenSkull2 = nullptr;
	delete mGreenSkull3;
	mGreenSkull3 = nullptr;
	delete mGreenSkull4;
	mGreenSkull4 = nullptr;
	delete mGreenSkull5;
	mGreenSkull5 = nullptr;
	delete mGreenSkull6;
	mGreenSkull6 = nullptr;
	delete mGreenSkull7;
	mGreenSkull7 = nullptr;
	delete mGreenSkull8;
	mGreenSkull8 = nullptr;
	delete mGreenSkull9;
	mGreenSkull9 = nullptr;
	delete mGreenSkull10;
	mGreenSkull10 = nullptr;
	delete mGreenSkull11;
	mGreenSkull11 = nullptr;
	delete mRow2GreenSkull1;
	mRow2GreenSkull1 = nullptr;
	delete mRow2GreenSkull2;
	mRow2GreenSkull2 = nullptr;
	delete mRow2GreenSkull3;
	mRow2GreenSkull3 = nullptr;
	delete mRow2GreenSkull4;
	mRow2GreenSkull4 = nullptr;
	delete mRow2GreenSkull5;
	mRow2GreenSkull5 = nullptr;
	delete mRow2GreenSkull6;
	mRow2GreenSkull6 = nullptr;
	delete mRow2GreenSkull7;
	mRow2GreenSkull7 = nullptr;
	delete mRow2GreenSkull8;
	mRow2GreenSkull8 = nullptr;
	delete mRow2GreenSkull9;
	mRow2GreenSkull9 = nullptr;
	delete mRow2GreenSkull10;
	mRow2GreenSkull10 = nullptr;
	delete mRow2GreenSkull11;
	mRow2GreenSkull11 = nullptr;
	
	delete mBlueSkull1;
	mBlueSkull1 = nullptr;
	delete mBlueSkull2;
	mBlueSkull2 = nullptr;
	delete mBlueSkull3;
	mBlueSkull3 = nullptr;
	delete mBlueSkull4;
	mBlueSkull4 = nullptr;
	delete mBlueSkull5;
	mBlueSkull5 = nullptr;
	delete mBlueSkull6;
	mBlueSkull6 = nullptr;
	delete mBlueSkull7;
	mBlueSkull7 = nullptr;
	delete mBlueSkull8;
	mBlueSkull8 = nullptr;
	delete mBlueSkull9;
	mBlueSkull9 = nullptr;
	delete mBlueSkull10;
	mBlueSkull10 = nullptr;
	delete mBlueSkull11;
	mBlueSkull11 = nullptr;
	delete mRow2BlueSkull1;
	mRow2BlueSkull1 = nullptr;
	delete mRow2BlueSkull2;
	mRow2BlueSkull2 = nullptr;
	delete mRow2BlueSkull3;
	mRow2BlueSkull3 = nullptr;
	delete mRow2BlueSkull4;
	mRow2BlueSkull4 = nullptr;
	delete mRow2BlueSkull5;
	mRow2BlueSkull5 = nullptr;
	delete mRow2BlueSkull6;
	mRow2BlueSkull6 = nullptr;
	delete mRow2BlueSkull7;
	mRow2BlueSkull7 = nullptr;
	delete mRow2BlueSkull8;
	mRow2BlueSkull8 = nullptr;
	delete mRow2BlueSkull9;
	mRow2BlueSkull9 = nullptr;
	delete mRow2BlueSkull10;
	mRow2BlueSkull10 = nullptr;
	delete mRow2BlueSkull11;
	mRow2BlueSkull11 = nullptr;

	delete mPinkSkull1;
	mPinkSkull1 = nullptr;
	delete mPinkSkull2;
	mPinkSkull2 = nullptr;
	delete mPinkSkull3;
	mPinkSkull3 = nullptr;
	delete mPinkSkull4;
	mPinkSkull4 = nullptr;
	delete mPinkSkull5;
	mPinkSkull5 = nullptr;
	delete mPinkSkull6;
	mPinkSkull6 = nullptr;
	delete mPinkSkull7;
	mPinkSkull7 = nullptr;
	delete mPinkSkull8;
	mPinkSkull8 = nullptr;
	delete mPinkSkull9;
	mPinkSkull9 = nullptr;
	delete mPinkSkull10;
	mPinkSkull10 = nullptr;
	delete mPinkSkull11;
	mPinkSkull11 = nullptr;
	delete mRedBlockade1;
	mRedBlockade1 = nullptr;
	delete mRedBlockade2;
	mRedBlockade2 = nullptr;
	delete mRedBlockade3;
	mRedBlockade3 = nullptr;
	delete mRedBlockade4;
	mRedBlockade4 = nullptr;
	
	
	



}

void PlayScreen::Update() {
	if (mInputManager->KeyPressed(SDL_SCANCODE_Y)) {

		mPlayer->AddScore(100);
		std::cout << mPlayer->Score();
		mSideBar->SetPlayerScore(mPlayer->Score());

	}
	//TODO: Make High score board cashe the highest score  

	if (mInputManager->KeyPressed(SDL_SCANCODE_G)) {

		mPlayer->MinusLives(1);
		std::cout << mPlayer->Lives();
		mSideBar->SetLives(mPlayer->Lives());

	}

	if (mInputManager->KeyPressed(SDL_SCANCODE_F)) {

		
		mSideBar->SetRoundNumber(1);

	}
	//TODO: Make the round add +1 each round instead of just 1

	if (mInputManager->KeyPressed(SDL_SCANCODE_H)) {

		mTriggerPlayerDeath = true;
	
		// This is where the player will be told what to do when they die. aka general spirte sheet death
	}
	
	if (mTriggerPlayerDeath == true)  {
		mLevel->HandlePlayerDeath();

	}


	if (mGameStarted) {
		mPlayer->Update();
	

		if (!mLevelStarted) {
			StartNextLevel();
			mLevelStartTimer += mTimer->DeltaTime();
			if (mLevelStartTimer >= mLevelStartDelay) {
				
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
	else {
	//	if (!Mix_PlayingMusic()) {
		mGameStarted = true;
		}
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

	mGreenSkull1->Render();
	mGreenSkull2->Render();
	mGreenSkull3->Render();
	mGreenSkull4->Render();
	mGreenSkull5->Render();
	mGreenSkull6->Render();
	mGreenSkull7->Render();
	mGreenSkull8->Render();
	mGreenSkull9->Render();
	mGreenSkull10->Render();
	mGreenSkull11->Render();
	mRow2GreenSkull1->Render();
	mRow2GreenSkull2->Render();
	mRow2GreenSkull3->Render();
	mRow2GreenSkull4->Render();
	mRow2GreenSkull5->Render();
	mRow2GreenSkull6->Render();
	mRow2GreenSkull7->Render();
	mRow2GreenSkull8->Render();
	mRow2GreenSkull9->Render();
	mRow2GreenSkull10->Render();
	mRow2GreenSkull11->Render();
	mBlueSkull1->Render();
	mBlueSkull2->Render();
	mBlueSkull3->Render();
	mBlueSkull4->Render();
	mBlueSkull5->Render();
	mBlueSkull6->Render();
	mBlueSkull7->Render();
	mBlueSkull8->Render();
	mBlueSkull9->Render();
	mBlueSkull10->Render();
	mBlueSkull11->Render();
	mRow2BlueSkull1->Render();
	mRow2BlueSkull2->Render();
	mRow2BlueSkull3->Render();
	mRow2BlueSkull4->Render();
	mRow2BlueSkull5->Render();
	mRow2BlueSkull6->Render();
	mRow2BlueSkull7-> Render();
	mRow2BlueSkull8->Render();
	mRow2BlueSkull9->Render();
	mRow2BlueSkull10->Render();
	mRow2BlueSkull11->Render();
	mPinkSkull1->Render();
	mPinkSkull2->Render();
	mPinkSkull3->Render();
	mPinkSkull4->Render();
	mPinkSkull5->Render();
	mPinkSkull6->Render();
	mPinkSkull7->Render();
	mPinkSkull8->Render();
	mPinkSkull9->Render();
	mPinkSkull10->Render();
	mPinkSkull11->Render();
	mRedBlockade1->Render();
	mRedBlockade2->Render();
	mRedBlockade3->Render();
	mRedBlockade4->Render();

}

void PlayScreen::StartNewGame() {
	delete mPlayer;
	mPlayer = new Player();
	mPlayer->Parent(this);
	mPlayer->Position(Graphics::SCREEN_WIDTH * 0.4, Graphics::SCREEN_HEIGHT * 0.8f);
	mPlayer->Active(false);

	//mSideBar->SetHighScore(30000);
	mSideBar->SetLives(mPlayer->Lives());
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