#include "StartScreen.h"


StartScreen::StartScreen() {
	mTimer = Timer::Instance();
	mInputManager = InputManager::Instance();

	mTopBar = new GameEntity(Graphics::SCREEN_WIDTH * 0.5f, 80.0f);


	mBottomBar = new GameEntity(Graphics::SCREEN_WIDTH * 0.5f,Graphics::SCREEN_HEIGHT * 0.7f);
	mPleaseSelect = new Texture("PLEASE  SELECT", "emulogic.ttf", 32, { 0, 255, 255 });
	mRights = new Texture("© TATITO CORP.MCMLXXXV", "emulogic.ttf", 32, { 255, 0, 0 });
	m1or2Players = new Texture("< 1 or 2 Players >", "emulogic.ttf", 32, { 255, 0, 0 });
	mGreenSkull2 = new Texture("GeneralSprite.png", 9, 0, 8, 8);



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


	mPlayerModes->Parent(this);
	mOnePlayerMode->Parent(mPlayerModes);
	mTwoPlayerMode->Parent(mPlayerModes);
	mCursor->Parent(mPlayerModes);

	mOnePlayerMode->Position(-50.0f, -5.0f);
	mTwoPlayerMode->Position(-50.0f, 70.0f);
	mCursor->Position(-245.0, -5.0f);
	mPleaseSelect->Position(-100.0f, -300.0f);
	mRights->Position(-120.0f, 170.0f);
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
	mOnePlayerMode->Render();
	mTwoPlayerMode->Render();
	mCursor->Render();
	mRights->Render();
	m1or2Players->Render();
	mPleaseSelect->Render();
	mGreenSkull2->Render();


}

