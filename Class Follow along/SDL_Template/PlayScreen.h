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

	PlaySideBar* mSideBar;

	Texture* mStartLabel;

	float mLevelStartTimer;
	float mLevelStartDelay;

	bool mGameStarted;

	Level* mLevel;
	bool mLevelStarted;
	int mCurrentStage;

	Player* mPlayer;

public:
	PlayScreen();
	~PlayScreen();

	void StartNewGame();
	void StartNextLevel();

	bool GameOver();

	void Update() override;
	void Render() override;
};