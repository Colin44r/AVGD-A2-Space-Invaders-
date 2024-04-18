#include "StartScreen.h"


StartScreen::StartScreen() {
	mTimer = Timer::Instance();
	mInputManager = InputManager::Instance();

	mTopBar = new GameEntity(Graphics::SCREEN_WIDTH * 0.5f, 80.0f);
	//mPlayerOne = new Texture("1UP", "emulogic.ttf", 32, { 255, 255, 255 });
	//mPlayerTwo = new Texture("2UP", "emulogic.ttf", 32, { 255, 255, 255 });
	//mHigh = new Texture("HIGH", "emulogic.ttf", 32, { 255, 255, 255 });
	//mScore = new Texture("SCORE", "emulogic.ttf", 32, { 255, 255, 255 });

	mBottomBar = new GameEntity(Graphics::SCREEN_WIDTH * 0.5f,Graphics::SCREEN_HEIGHT * 0.7f);
	mPleaseSelect = new Texture("PLEASE  SELECT", "emulogic.ttf", 32, { 0, 255, 255 });
	mRights = new Texture("� TATITO CORP.MCMLXXXV", "emulogic.ttf", 32, { 255, 0, 0 });
	m1or2Players = new Texture("< 1 or 2 Players >", "emulogic.ttf", 32, { 255, 0, 0 });
	mGreenSkull2 = new Texture("GeneralSprite.png", 9, 0, 8, 8);
	//m5000Display = new Texture("05000", "emulogic.ttf", 32, { 255, 255, 255 });
	//m0Display =  new Texture("00000", "emulogic.ttf", 32, { 255, 255, 255 });
	mRound = new Texture("ROUND", "emulogic.ttf", 32, { 255, 255, 255 });


	mPlayerModes = new GameEntity(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.55f);
	mOnePlayerMode = new Texture("1 Player ", "emulogic.ttf", 32, { 0, 255, 0 });
	mTwoPlayerMode = new Texture("2 Player ", "emulogic.ttf", 32, { 0, 255, 255 });
	mCursor = new Texture("GeneralSprite.png", 103, 63, 8, 8);

	mBottomBar->Parent(this);
	mGreenSkull2->Parent(mBottomBar);
	mPleaseSelect->Parent(mBottomBar);
	mRights->Parent(mBottomBar);
	m1or2Players->Parent(mBottomBar);

	mTopBar->Parent(this);
	//mPlayerOne->Parent(mTopBar);
	//mPlayerTwo->Parent(mTopBar);
	//mScore->Parent(mTopBar);
	//mHigh->Parent(mTopBar);
	//m5000Display->Parent(mTopBar);
	//m0Display->Parent(mTopBar);
	mRound->Parent(mTopBar);

	//mPlayerOne->Position(-Graphics::SCREEN_WIDTH * 0.35f, 0.0f);
	//mPlayerTwo->Position(Graphics::SCREEN_WIDTH * 0.2f, 0.0f);
	//mHigh->Position(330.0f, 0.0f);
	//mScore->Position(375.0f, 35.0f);
	//m0Display->Position(375.0f, 210.0f);
	//m5000Display ->Position(375.0f, 90.0f);
	mRound->Position(365.0f, 450.0f);

	mPlayerModes->Parent(this);
	mOnePlayerMode->Parent(mPlayerModes);
	mTwoPlayerMode->Parent(mPlayerModes);
	mCursor->Parent(mPlayerModes);

	mOnePlayerMode->Position(-50.0f, -5.0f);
	mTwoPlayerMode->Position(-50.0f, 70.0f);
	mCursor->Position(-245.0, -5.0f);
	mPleaseSelect->Position(-100.0f, -300.0f);
	mRights->Position(-120.0f, 170.0f);
	//mPlayerOne->Position(330.0f, 150.0f);
	//mPlayerTwo->Position(330.0f, 270.0f);
	mGreenSkull2->Position(-100.0f, -485.0f);
	m1or2Players->Position(-100.0f, -230.0f);

	mGreenSkull2->Scale(Vector2(3.75f, 3.15f));
	mCursor->Scale(Vector2(5.75f, 5.15f));

	mLogo = new Texture("GalagaLogo.png", 0, 0, 360, 180);
	mAnimatedLogo = new AnimatedTexture("GalagaLogo.png", 0, 0, 360, 180, 3, 0.5f, AnimatedTexture::Vertical);

	mLogo->Parent(this);
	mAnimatedLogo->Parent(this);

	mLogo->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.32f);
	mAnimatedLogo->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.32f);


	mCursorStartPos = mCursor->Position(Local);
	mCursorOffset = Vector2(0, 80);



}

StartScreen::~StartScreen() {
	delete mTopBar;
	mTopBar = nullptr;
	//delete mPlayerOne;
	//mPlayerOne = nullptr;
	//delete mPlayerTwo;
	//mPlayerTwo = nullptr;
	//delete mHigh;
	//mHigh = nullptr;
	//delete mScore;
	//mScore = nullptr;
	delete mPlayerModes;
	mPlayerModes = nullptr;
	delete mOnePlayerMode;
	mOnePlayerMode = nullptr;
	delete mTwoPlayerMode;
	mTwoPlayerMode = nullptr;
	delete mCursor;
	mCursor = nullptr;
	delete mGreenSkull2;
	mGreenSkull2 = nullptr;
	delete mPleaseSelect;
	mPleaseSelect = nullptr;
	delete mRights;
	mRights = nullptr;
	delete m1or2Players;
	m1or2Players = nullptr;
//	delete m5000Display;
	//m5000Display = nullptr;
	//delete m0Display;
	//m0Display = nullptr;
	delete mRound;
	mRound = nullptr;

	delete mLogo;
	mLogo = nullptr;
	delete mAnimatedLogo;
	mAnimatedLogo = nullptr;
	
	
	mTimer = nullptr;
	mInputManager = nullptr;
	mTimer = nullptr;
	mInputManager = nullptr;

	delete mLogo;
	mLogo = nullptr;


	
	
	

}

void StartScreen::ResetAnimation() {

}

void StartScreen::ChangeSelectedMode(int change) {
	mSelectedMode += change;

	if (mSelectedMode < 0) {
		mSelectedMode = 1;
	}
	else if (mSelectedMode > 1) {
		mSelectedMode = 0;
	}
	

	mCursor->Position(mCursorStartPos + mCursorOffset * (float)mSelectedMode);
	// connect (float)mSelectedMode) to mTwoPlayerMode somehow??? i think.....
}

//int StartScreen::GetSelectedMode() {
	//return mSelectedMode;

//}

void StartScreen::Update() {
	
	
		mAnimatedLogo->Update();

	if (mInputManager->KeyPressed(SDL_SCANCODE_DOWN)) {
			ChangeSelectedMode(1);
	}
	else if (mInputManager->KeyPressed(SDL_SCANCODE_UP)) {
			ChangeSelectedMode(-1);
	}
	

}

void StartScreen::Render() {
	//mPlayerOne->Render();
	//mPlayerTwo->Render();
	//mHigh->Render();
	//mScore->Render();
	mOnePlayerMode->Render();
	mTwoPlayerMode->Render();
	mCursor->Render();
	mRights->Render();
	m1or2Players->Render();
	mPleaseSelect->Render();
	mGreenSkull2->Render();
	//m0Display ->Render();
	//m5000Display->Render();
	mRound->Render();

	//mLogo->Render();
	//mAnimatedLogo->Render();

}

