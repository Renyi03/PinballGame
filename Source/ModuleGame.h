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
};
