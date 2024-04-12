#include "Bullet.h"
#include "PhysicsManager.h"
#include "BoxCollider.h"

Bullet::Bullet(bool friendly) {
	mTimer = Timer::Instance();

	mTexture = new Texture("Bullet.png");
	mTexture->Parent(this);
	mTexture->Position(Vec2_Zero);

	mSpeed = 500;

	Reload();

	AddCollider(new BoxCollider(mTexture->ScaledDimensions()));

	if (friendly) {
		mId = PhysicsManager::Instance()->RegisterEntity(this, PhysicsManager::CollisionLayers::FriendlyProjectiles);
	}
	else {
		mId = PhysicsManager::Instance()->RegisterEntity(this, PhysicsManager::CollisionLayers::HostileProjectiles);
	}
}

bool Bullet::IgnoreCollisions() {
	return !Active();
}

void Bullet::Hit(PhysEntity* other) {
	Reload();
}

Bullet::~Bullet() {
	mTimer = nullptr;

	delete mTexture;
	mTexture = nullptr;
}

void Bullet::Fire(Vector2 pos) {
	Position(pos);
	Active(true);
}

void Bullet::Reload() {
	Active(false);
}

void Bullet::Update() {
	if (Active()) {
		Translate(-Vec2_Up * mSpeed * mTimer->DeltaTime());

		Vector2 pos = Position();
		if (pos.y < -OFFSCRREN_BUFFER) {
			Reload();
		}
	}
}

void Bullet::Render() {
	if (Active()) {
		mTexture->Render();
		PhysEntity::Render();
	}
}