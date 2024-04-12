#pragma once
#include "Texture.h"

using namespace SDLFramework;

class Collider : public GameEntity {
public:
	enum class ColliderType {Box, Circle};

	Collider(ColliderType type);
	virtual ~Collider();

	virtual Vector2 GetFurthestPoint() = 0;

	ColliderType GetType();

	virtual void Render() override;

protected:
	static const bool DEBUG_COLLIDERS = true;

	ColliderType mType;
	Texture* mDebugTexture;

	void SetDebugTexture(Texture* tex);
};