#pragma once
#include "AudioManager.h"
#include "GameEntity.h"
#include "Timer.h"
#include "Level.h"
#include "Player.h"

using namespace SDLFramework;

class PlayScreen : public GameEntity {
private:
	Timer* mTimer;
	AudioManager* mAudio;
	InputManager* mInputManager;

	PlaySideBar* mSideBar;

	Texture* mStartLabel;
	Texture* mGreenSkull1;
	Texture* mGreenSkull2;
	Texture* mGreenSkull3;
	Texture* mGreenSkull4;
	Texture* mGreenSkull5;
	Texture* mGreenSkull6;
	Texture* mGreenSkull7;
	Texture* mGreenSkull8;
	Texture* mGreenSkull9;
	Texture* mGreenSkull10;
	Texture* mGreenSkull11;
	Texture* mRow2GreenSkull1;
	Texture* mRow2GreenSkull2;
	Texture* mRow2GreenSkull3;
	Texture* mRow2GreenSkull4;
	Texture* mRow2GreenSkull5;
	Texture* mRow2GreenSkull6;
	Texture* mRow2GreenSkull7;
	Texture* mRow2GreenSkull8;
	Texture* mRow2GreenSkull9;
	Texture* mRow2GreenSkull10;
	Texture* mRow2GreenSkull11;
	Texture* mBlueSkull1;
	Texture* mBlueSkull2;
	Texture* mBlueSkull3;
	Texture* mBlueSkull4;
	Texture* mBlueSkull5;
	Texture* mBlueSkull6;
	Texture* mBlueSkull7;
	Texture* mBlueSkull8;
	Texture* mBlueSkull9;
	Texture* mBlueSkull10;
	Texture* mBlueSkull11;
	Texture* mRow2BlueSkull1;
	Texture* mRow2BlueSkull2;
	Texture* mRow2BlueSkull3;
	Texture* mRow2BlueSkull4;
	Texture* mRow2BlueSkull5;
	Texture* mRow2BlueSkull6;
	Texture* mRow2BlueSkull7;
	Texture* mRow2BlueSkull8;
	Texture* mRow2BlueSkull9;
	Texture* mRow2BlueSkull10;
	Texture* mRow2BlueSkull11;
	Texture* mPinkSkull1;
	Texture* mPinkSkull2;
	Texture* mPinkSkull3;
	Texture* mPinkSkull4;
	Texture* mPinkSkull5;
	Texture* mPinkSkull6;
	Texture* mPinkSkull7;
	Texture* mPinkSkull8;
	Texture* mPinkSkull9;
	Texture* mPinkSkull10;
	Texture* mPinkSkull11;
	Texture* mRedBlockade1;
	Texture* mRedBlockade2;
	Texture* mRedBlockade3;
	Texture* mRedBlockade4;

	GameEntity* mTopSprites;



	float mLevelStartTimer;
	float mLevelStartDelay;

	bool mGameoverCall;
	bool mGameStarted;
	bool mTriggerPlayerDeath;
	Level* mLevel;
	bool mLevelStarted;
	int mCurrentStage;

	Player* mPlayer;
	 
public:
	PlayScreen(PlaySideBar* mSideBarPS);
	~PlayScreen();

	void StartNewGame();
	void StartNextLevel();

	bool GameOver();

	void Update() override;
	void Render() override;
};