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


class ModuleGame : public Module
{
public:
	ModuleGame(Application* app, bool start_enabled = true);
	~ModuleGame();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	std::vector<PhysicEntity*> entities;
	Texture2D ballTexture;
	void CreateBall();
	PhysBody* boardBody;
	b2RevoluteJoint* leftJoint;
	b2RevoluteJoint* rightJoint;
	Ball* ball;
	int totalBalls = 4;     // Max balls per round
	int currentBall = 0;    // How many have been used
	bool roundOver = false; // To prevent respawning after the last ball
};
