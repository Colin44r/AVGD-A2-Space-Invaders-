#include "ScreenManager.h"

ScreenManager* ScreenManager::sInstance = nullptr;

ScreenManager* ScreenManager::Instance() {
	if (sInstance == nullptr) {
		sInstance = new ScreenManager();
	}

	return sInstance;
}

void ScreenManager::Release() {
	delete sInstance;
	sInstance = nullptr;
}

ScreenManager::ScreenManager() {
	mInput = InputManager::Instance();

	mStartScreen = new StartScreen();
	mPlayScreen = new PlayScreen();

	mCurrentScreen = Start;
}

ScreenManager::~ScreenManager() {
	mInput = nullptr;

	delete mStartScreen;
	mStartScreen = nullptr;
	delete mPlayScreen;
	mPlayScreen = nullptr;
}

void ScreenManager::Update() {
	//Call update on any background image/effect that you want to persist between screens here!


	switch (mCurrentScreen)
	{
	case ScreenManager::Start:
		mStartScreen->Update();

		if (mInput->KeyPressed(SDL_SCANCODE_RETURN)) {
			mCurrentScreen = Play;
			mStartScreen->ResetAnimation();
			mPlayScreen->StartNewGame();
		}

		break;
	case ScreenManager::Play:
		mPlayScreen->Update();

		if (mPlayScreen->GameOver()) {
			mCurrentScreen = Start;
		}

		break;
	default:
		break;
	}
}

void ScreenManager::Render() {
	//Call Render on any background image/effect that you want to persist between screens here!


	switch (mCurrentScreen)
	{
	case ScreenManager::Start:
		mStartScreen->Render();

		break;
	case ScreenManager::Play:
		mPlayScreen->Render();

		break;
	default:
		break;
	}
}