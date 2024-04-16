#pragma once
#include "StartScreen.h"
#include "PlayScreen.h"

class ScreenManager {
private:
	static ScreenManager* sInstance;

	ScreenManager();
	~ScreenManager();

	InputManager* mInput;

	enum Screens { Start, Play};
	Screens mCurrentScreen;

	StartScreen* mStartScreen;
	PlayScreen* mPlayScreen;
	PlaySideBar* mSideBarSS;

public:
	static ScreenManager* Instance();
	static void Release();

	void Update();
	void Render();
};