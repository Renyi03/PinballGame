#include "Multiplier.h"
#include "PhysicEntity.h"
#include "ModulePhysics.h"

MultiplierZone::MultiplierZone(ModulePhysics* physics, int _x, int _y, int _radius, Module* _listener, int _multiplier, Texture2D _texture)
	: PhysicEntity(physics->CreateCircleSensor(_x, _y, _radius), _listener, EntityType::MULTIPLIER, 0, 2)
	, multiplier(_multiplier)
	, texture(_texture)
{
}
void MultiplierZone::Update() 
{
	int x, y;
	body->GetPhysicPosition(x, y);
	Vector2 position{ (float)x, (float)y };
	DrawTexture(texture, x - 22, y - 22, WHITE);
}