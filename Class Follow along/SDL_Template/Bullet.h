#pragma once
#include "Texture.h"
#include "Timer.h"
#include "PhysEntity.h"

using namespace SDLFramework;

class Bullet : public PhysEntity {
private:
	static const int OFFSCRREN_BUFFER = 10;

	Timer* mTimer;

	Texture* mTexture;

	float mSpeed;

	bool IgnoreCollisions() override;

public:
	Bullet(bool friendly);
	~Bullet();

	void Fire(Vector2 pos);
	void Reload();

	void Hit(PhysEntity* other) override;

	void Update() override;
	void Render() override;
};