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
	SPRING
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

public:
	std::vector<PhysicEntity*> entities;
	Texture2D ballTexture;
	bool changeGravity;
	bool bounceMode;
	void CreateBall();
	b2RevoluteJoint* leftJoint;
	b2RevoluteJoint* rightJoint;
	Ball* ball;
	BoardTriangleR* boardTriangleR;
	SpringLauncherEntity* springLauncherEntity;
	LeftFlipper* leftFlipperEntity;
	RightFlipper* rightFlipperEntity;
	int currentScore;
	int previousScore;
	int highestScore;
	int totalBalls = 2;     // Max balls per round
	int currentBall = 1;    // How many have been used
	bool roundOver = false; // To prevent respawning after the last ball
};
