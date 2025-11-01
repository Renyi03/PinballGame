#pragma once

#include "Globals.h"
#include "Module.h"

#include "p2Point.h"

#include "raylib.h"
#include <vector>

#include "Box2D/Box2D.h"

class PhysBody;
class PhysicEntity;
class Ball;
class BoardTriangleR;
class SpringLauncherEntity;
class LeftFlipper;
class RightFlipper;

enum class EntityType {
	DEFAULT,
	BALL,
	ROUND_BUMPER,
	TRIANGLE_BUMPER,
	FLIPPER,
	SPRING,
	MULTIPLIER
};

class ModuleGame : public Module
{
public:
	ModuleGame(Application* app, bool start_enabled = true);
	~ModuleGame();

	bool Start();
	update_status Update();
	bool CleanUp();
	void OnCollision(PhysBody* bodyA, PhysBody* bodyB);
	void AddScore(int points);
	void MultiplyScore(int multiplier);

public:
	std::vector<PhysicEntity*> entities;
	Texture2D ballTexture;
	bool changeGravity;
	bool bounceMode;
	b2RevoluteJoint* leftJoint;
	b2RevoluteJoint* rightJoint;
	Ball* ball;
	BoardTriangleR* boardTriangleR;
	SpringLauncherEntity* springLauncherEntity;
	LeftFlipper* leftFlipperEntity;
	RightFlipper* rightFlipperEntity;
	int currentScore = 0;
	int scoreMultiplier = 1;
	int previousScore;
	int highestScore;
	bool isMultiplied = false;
};
