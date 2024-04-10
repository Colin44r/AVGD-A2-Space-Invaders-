#pragma once
#include "AnimatedTexture.h"
#include "InputManager.h"
#include "AudioManager.h"
#include "Bullet.h"

using namespace SDLFramework;

class Player : public GameEntity {
private:
	static const int MAX_BULLETS = 2;

	Timer* mTimer;
	InputManager* mInput;
	AudioManager* mAudio;

	bool mVisible;
	bool mAnimating;

	int mScore;
	int mLives;

	Texture* mShip;
	AnimatedTexture* mDeathAnimation;

	float mMoveSpeed;
	Vector2 mMoveBounds;

	Bullet* mBullets[MAX_BULLETS];

	void HandleMovement();
	void HandleFiring();

public:
	Player();
	~Player();

	void Visible(bool visible);
	bool IsAnimating();

	int Score();
	int Lives();

	void AddScore(int change);

	void WasHit();

	void Update() override;
	void Render() override;
};