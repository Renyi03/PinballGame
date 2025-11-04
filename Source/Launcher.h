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
	Texture2D springTexture = LoadTexture("Assets/Textures/SpringSpriteSheet.png");
	int framesCtr;
	int currentXSpring = 0;
	Rectangle frameRec{ 0, 0, 39, 139 };
	b2PrismaticJoint* springLauncherJoint = nullptr;
	b2Body* springPlungerBody = nullptr;
	Sound spring = LoadSound("Assets/Sounds/spring.wav");
};
