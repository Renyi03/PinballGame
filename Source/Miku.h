#pragma once
#include "raylib.h"
#include "ModuleGame.h"
#include "PhysicEntity.h"

class Miku : public PhysicEntity
{
public:
	Miku(ModulePhysics* physics, int _x, int _y, int _radius, Module* _listener,
		Texture2D _normalTexture, Texture2D _shineTexture);
	void Update() override;

	void Activate();

	// Reset to normal texture
	void Deactivate();
	bool GetIsActivated();

private:
	Texture2D normalTexture;   // Normal texture
	Texture2D shineTexture;    // Shine texture that displays when the ball touches the sensor
	Texture2D currentTexture;  // Currently displayed texture
	bool isActivated;
};
