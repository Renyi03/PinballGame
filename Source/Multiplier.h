#pragma once
#include "raylib.h"
#include "ModuleGame.h"
#include "PhysicEntity.h"

class MultiplierZone : public PhysicEntity
{
public:
	MultiplierZone(ModulePhysics* physics, int _x, int _y, int _radius, Module* _listener, int _multiplier, Texture2D _texture);
		void Update() override;

private:
	int multiplier;
	Texture2D texture;
};
