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
	Texture* mGreenSkull4;

	GameEntity* mTopSprites;



	float mLevelStartTimer;
	float mLevelStartDelay;

	bool mGameStarted;

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