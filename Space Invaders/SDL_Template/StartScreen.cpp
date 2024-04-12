#include "StartScreen.h"

StartScreen::StartScreen() {
	mTimer = Timer::Instance();
	mInputManager = InputManager::Instance();

	mTopBar = new GameEntity(Graphics::SCREEN_WIDTH * 0.5f, 80.0f);
	mPlayerOne = new Texture("1UP", "emulogic.ttf", 32, { 200, 0, 0 });
	mPlayerTwo = new Texture("2UP", "emulogic.ttf", 32, { 200, 0, 0 });
	mHiScore = new Texture("HI SCORE", "emulogic.ttf", 32, { 200, 0, 0 });
	
	mBottomBar = new GameEntity(Graphics::SCREEN_WIDTH * 0.5f,Graphics::SCREEN_HEIGHT * 0.7f);
	mPleaseSelect = new Texture("PLEASE SELECT", "emulogic.ttf", 32, { 0, 200, 200 });
	mRights = new Texture("© TATITO CORP.MCMLXXXV", "emulogic.ttf", 32, { 200, 0, 0 });

	mGreenSkull2 = new Texture("GeneralSprite", 0, 9, 8, 8);


	mBottomBar->Parent(this);
	mGreenSkull2->Parent(mBottomBar);
	mPleaseSelect->Parent(mBottomBar);
	mRights->Parent(mBottomBar);

	mTopBar->Parent(this);
	mPlayerOne->Parent(mTopBar);
	mPlayerTwo->Parent(mTopBar);
	mHiScore->Parent(mTopBar);

	mPlayerOne->Position(-Graphics::SCREEN_WIDTH * 0.35f, 0.0f);
	mPlayerTwo->Position(Graphics::SCREEN_WIDTH * 0.2f, 0.0f);
	mHiScore->Position(-30.0f, 0.0f);

	mPlayerModes = new GameEntity(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.55f);
	mOnePlayerMode = new Texture("1 Player ", "emulogic.ttf", 32, { 230, 230, 230 });
	mTwoPlayerMode = new Texture("2 Player ", "emulogic.ttf", 32, { 230, 230, 230 });
	mCursor = new Texture("Cursor.png");

	mPlayerModes->Parent(this);
	mOnePlayerMode->Parent(mPlayerModes);
	mTwoPlayerMode->Parent(mPlayerModes);
	mCursor->Parent(mPlayerModes);

	mOnePlayerMode->Position(0.0f, -35.0f);
	mTwoPlayerMode->Position(0.0f, 35.0f);
	mCursor->Position(-175.0, -35.0f);
	mGreenSkull2->Position(0.0f, 90.0f);
	mPleaseSelect->Position(0.0f, -300.0f);
	mRights->Position(0.0f, 170.0f);
	mPlayerOne->Position(270.0f, 200.0f);


	mGreenSkull2->Scale(Vector2(4.75f, 4.15f));


	mLogo = new Texture("GalagaLogo.png", 0, 0, 360, 180);
	mAnimatedLogo = new AnimatedTexture("GalagaLogo.png", 0, 0, 360, 180, 3, 0.5f, AnimatedTexture::Vertical);

	mLogo->Parent(this);
	mAnimatedLogo->Parent(this);

	mLogo->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.32f);
	mAnimatedLogo->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.32f);


}

StartScreen::~StartScreen() {
	delete mTopBar;
	mTopBar = nullptr;
	delete mPlayerOne;
	mPlayerOne = nullptr;
	delete mPlayerTwo;
	mPlayerTwo = nullptr;
	delete mHiScore;
	mHiScore = nullptr;
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
}

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
	mPlayerOne->Render();
	mPlayerTwo->Render();
	mHiScore->Render();
	mOnePlayerMode->Render();
	mTwoPlayerMode->Render();
	mCursor->Render();
	mRights->Render();

	mPleaseSelect->Render();
	mGreenSkull2->Render();


	//mLogo->Render();
	//mAnimatedLogo->Render();

}

