#include "Bumper.h"
#include "PhysicEntity.h"
#include "ModulePhysics.h"

YellowBumper::YellowBumper(ModulePhysics* physics, int _x, int _y, Module* _listener, Texture2D _texture)
	: PhysicEntity(physics->CreateCircularBumper(279, 379, 38), _listener, EntityType::BUMPER, 50)
	, texture(_texture)
{
}

void YellowBumper::Update()
{
	int x, y;
	body->GetPhysicPosition(x, y);
	Vector2 position{ (float)x, (float)y };
	DrawTexture(texture, x - 38, y - 38, WHITE);
}

RedBumper::RedBumper(ModulePhysics* physics, int _x, int _y, Module* _listener, Texture2D _texture)
	: PhysicEntity(physics->CreateCircularBumper(338, 295, 38), _listener, EntityType::BUMPER, 100)
	, texture(_texture)
{
}
void RedBumper::Update()
{
	int x, y;
	body->GetPhysicPosition(x, y);
	Vector2 position{ (float)x, (float)y };
	DrawTexture(texture, x - 38, y - 38, WHITE);
}

BlueBumper::BlueBumper(ModulePhysics* physics, int _x, int _y, Module* _listener, Texture2D _texture)
	: PhysicEntity(physics->CreateCircularBumper(220, 295, 38), _listener, EntityType::BUMPER, 25)
	, texture(_texture)
{
}
void BlueBumper::Update()
{
	int x, y;
	body->GetPhysicPosition(x, y);
	Vector2 position{ (float)x, (float)y };
	DrawTexture(texture, x - 38, y - 38, WHITE);
}