#include "Miku.h"
#include "PhysicEntity.h"
#include "ModulePhysics.h"

Miku::Miku(ModulePhysics* physics, int _x, int _y, int _radius, Module* _listener,
	Texture2D _normalTexture, Texture2D _shineTexture)
	: PhysicEntity(physics->CreateCircleSensor(_x, _y, _radius), _listener, EntityType::MULTIPLIER, 0, 1, true)
	, normalTexture(_normalTexture)
	, shineTexture(_shineTexture)
	, isActivated(false)
{
	currentTexture = normalTexture;  // Start with normal texture
}
void Miku::Update() 
{
	int x, y;
	body->GetPhysicPosition(x, y);
	Vector2 position{ (float)x, (float)y };
	float scale = 1.0f;
	Rectangle source = { 0.0f, 0.0f, (float)currentTexture.width, (float)currentTexture.height };
	Rectangle dest = { position.x, position.y, (float)currentTexture.width * scale, (float)currentTexture.height * scale };
	Vector2 origin = { (float)currentTexture.width / 2.0f, (float)currentTexture.height / 2.0f };
	float rotation = body->GetRotation() * RAD2DEG;

	DrawTexturePro(currentTexture, source, dest, origin, rotation, WHITE);
}

void Miku::Activate() {
	if (!isActivated) {
		currentTexture = shineTexture;
		isActivated = true;
		TraceLog(LOG_INFO, "Changing Miku texture to shine");
	}
}

// Reset to normal texture
void Miku::Deactivate() {
	currentTexture = normalTexture;
	isActivated = false;
}

bool Miku::GetIsActivated() {
	return isActivated;
}
