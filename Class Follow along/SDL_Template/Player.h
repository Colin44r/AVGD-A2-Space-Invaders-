#pragma once
#include "AnimatedTexture.h"
#include "InputManager.h"
#include "AudioManager.h"
#include "Bullet.h"

using namespace SDLFramework;

class Player : public PhysEntity {
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

	bool mWasHit;

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

	bool WasHit();

	//Inherited from PhysEntity
	bool IgnoreCollisions() override;
	void Hit(PhysEntity* other) override;

	void Update() override;
	void Render() override;
};;