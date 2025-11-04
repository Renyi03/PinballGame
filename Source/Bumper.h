#pragma once
#include "raylib.h"
#include "ModuleGame.h"
#include "PhysicEntity.h"

class YellowBumper : public PhysicEntity
{
public:
	YellowBumper(ModulePhysics* physics, int _x, int _y, Module* _listener, Texture2D _texture);
	void Update() override;
private:
	Texture2D texture;

};

class RedBumper : public PhysicEntity
{
public:
	RedBumper(ModulePhysics* physics, int _x, int _y, Module* _listener, Texture2D _texture);
	void Update() override;
private:
	Texture2D texture;
};

class BlueBumper : public PhysicEntity
{
public:
	BlueBumper(ModulePhysics* physics, int _x, int _y, Module* _listener, Texture2D _texture);
	void Update() override;
private:
	Texture2D texture;

};