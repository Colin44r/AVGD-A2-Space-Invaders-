#pragma once
#include "Texture.h"
#include "Timer.h"

using namespace SDLFramework;

class Bullet : public GameEntity {
private:
	static const int OFFSCRREN_BUFFER = 10;

	Timer* mTimer;

	Texture* mTexture;

	float mSpeed;

public:
	Bullet();
	~Bullet();

	void Fire(Vector2 pos);
	void Reload();

	void Update() override;
	void Render() override;
};