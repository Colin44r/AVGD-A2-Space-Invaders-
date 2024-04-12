#pragma once
#include "Enemy.h"

class Wasp : public Enemy {
private:
	static std::vector<std::vector<Vector2>> sDivePaths;

	bool mDiver;

private:
	// Inherited via Enemy
	void FlyInComplete() override;

	Vector2 LocalFormationPosition() override;

	void HandleDiveState() override;
	void HandleDeadState() override;

	void RenderDiveState() override;
	void RenderDeadState() override;

public:
	static void CreateDivePaths();
	void Hit(PhysEntity* other) override;

	Wasp(int path, int index, bool challenge, bool diver);
	~Wasp();
};