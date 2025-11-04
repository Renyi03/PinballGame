#pragma once
#include "raylib.h"
#include "ModuleGame.h"
#include "PhysicEntity.h"

class LeftFlipper : public PhysicEntity
{
public:
	LeftFlipper(ModulePhysics* physics, int x, int y, Module* listener, b2RevoluteJoint*& joint, Texture2D _texture);

	void Update() override;

private:
	b2RevoluteJoint* joint;
	Texture2D texture;
};

class RightFlipper : public PhysicEntity
{
public:
	RightFlipper(ModulePhysics* physics, int x, int y, Module* listener, b2RevoluteJoint*& joint, Texture2D _texture);

	void Update() override;

private:
	b2RevoluteJoint* joint;
	Texture2D texture;
};