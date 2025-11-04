#pragma once
#include "raylib.h"
#include "ModuleGame.h"
#include "PhysicEntity.h"

class SpringLauncherEntity : public PhysicEntity
{
public:
	SpringLauncherEntity(ModulePhysics* physics, int x, int y, Module* listener, Sound spring);
	void Update() override;
private:
	Texture2D texture;
	b2PrismaticJoint* springLauncherJoint = nullptr;
	b2Body* springPlungerBody = nullptr;
	Sound spring = LoadSound("Assets/Sounds/spring.wav");
};