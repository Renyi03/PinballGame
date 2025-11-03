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
class Miku;

enum class EntityType {
	DEFAULT,
	BALL,
	BUMPER,
	FLIPPER,
	SPRING,
	MULTIPLIER,
	WALL
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
	void MultiplyScore(double multiplier);
	void MikuCombo();

public:
	std::vector<PhysicEntity*> entities;
	Texture2D ballTexture;
	Texture2D yellowBumperTexture;
	Texture2D redBumperTexture;
	Texture2D blueBumperTexture;
	Texture2D bordersTexture;
	Texture2D leftTriangleBumper;
	Texture2D rightTriangleBumper;
	Texture2D sNailTexture;
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
	Miku* M;
	Miku* I;
	Miku* K;
	Miku* U;
	int currentScore = 0;
	int scoreMultiplier = 1;
	int previousScore = 0;
	int highestScore = 0;
	int totalBalls = 3;     // Max balls per round
	int currentBall = 1;    // How many have been used
	bool roundOver = false; // To prevent respawning after the last ball
	bool isMultiplied = false;
	int mikuCtr = 0;
	Music bgm;
	Sound bumperHit;
	Sound flipperHit;
	Sound flipperNoHit;
	Sound miku;
	Sound spring;
	Sound wallHit;
};
