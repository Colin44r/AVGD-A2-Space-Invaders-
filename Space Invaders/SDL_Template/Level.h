#pragma once
#include "PlaySideBar.h"
#include "Player.h"
#include "Butterfly.h"
#include "tinyxml2.h"

using namespace tinyxml2;

class Level : public GameEntity
{
public:
	enum LevelStates { Running, Finished, GameOver };

private:
	Timer* mTimer;
	PlaySideBar* mSideBar;

	int mStage;
	bool mStageStarted;

	bool mStartLabel;

	float mLabelTimer;

	Texture* mStageLabel;
	Scoreboard* mStageNumber;
	float mStageLabelOnScreen;
	float mStageLabelOffScreen;

	Texture* mReadyLabel;
	float mReadyLabelOnScreen;
	float mReadyLabelOffScreen;

	Player* mPlayer;
	bool mPlayerHit;
	float mRespawnDelay;
	float mRespawnTimer;
	float mRespawnLabelOnScreen;

	Texture* mGameOverLabel;
	float mGameOverDelay;
	float mGameOverTimer;
	float mGameOverLabelOnScreen;

	LevelStates mCurrentState;
	bool mChallengeStage;

	static const int MAX_BUTTERFLIES = 16;

	Butterfly* mFormationButterflies[MAX_BUTTERFLIES];

	Butterfly* mDivingButterfly;
	bool mSkipFirstButterfly;
	float mButterflyDiveDelay;
	float mButterflyDiveTimer;

	XMLDocument mSpawningPatterns;
	int mCurrentFlyInPriority;
	int mCurrentFlyInIndex;

	float mSpawnDelay;
	float mSpawnTimer;
	bool mSpawningFinished;

	int mButterflyCount;
	std::vector<Enemy*> mEnemies;

	Formation* mFormation;

	void StartStage();
	void HandleStartLabels();
	void HandleCollisions();
	

	void HandleEnemySpawning();
	void HandleEnemyFormation();
	void HandleEnemyDiving();

	bool EnemyFyingIn();

public:

	Level(int stage, PlaySideBar* sideBar, Player* player);
	~Level();

	LevelStates State();

	void HandlePlayerDeath();

	void Update();
	void Render();
};