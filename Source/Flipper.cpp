#include "Flipper.h"
#include "PhysicEntity.h"
#include "ModulePhysics.h"

LeftFlipper::LeftFlipper(ModulePhysics* physics, int x, int y, Module* listener, b2RevoluteJoint*& joint, Texture2D _texture)
	: PhysicEntity(physics->CreateLeftFlipper(x, y, joint), listener, EntityType::FLIPPER, 0)
	, texture(_texture)
{
	this->joint = joint;
}

void LeftFlipper::Update()
{
	int x, y;
	body->GetPhysicPosition(x, y);
	Vector2 position{ (float)x, (float)y };
	float scale = 1.0f;
	Rectangle source = { 0.0f, 0.0f, (float)texture.width, (float)texture.height };
	Rectangle dest = { position.x, position.y, (float)texture.width * scale, (float)texture.height * scale };
	Vector2 origin = { (float)texture.width / 2.0f, (float)texture.height / 2.0f };
	float rotation = body->GetRotation() * RAD2DEG;
	DrawTexturePro(texture, source, dest, origin, rotation, WHITE);
}

RightFlipper::RightFlipper(ModulePhysics* physics, int x, int y, Module* listener, b2RevoluteJoint*& joint, Texture2D _texture)
	: PhysicEntity(physics->CreateRightFlipper(x, y, joint), listener, EntityType::FLIPPER, 0)
	, texture(_texture)
{
	this->joint = joint;
}

void RightFlipper::Update() 
{
	int x, y;
	body->GetPhysicPosition(x, y);
	Vector2 position{ (float)x, (float)y };
	float scale = 1.0f;
	Rectangle source = { 0.0f, 0.0f, (float)texture.width, (float)texture.height };
	Rectangle dest = { position.x, position.y, (float)texture.width * scale, (float)texture.height * scale };
	Vector2 origin = { (float)texture.width / 2.0f, (float)texture.height / 2.0f };
	float rotation = body->GetRotation() * RAD2DEG;
	DrawTexturePro(texture, source, dest, origin, rotation, WHITE);
}