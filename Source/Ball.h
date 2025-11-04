#pragma once
#include "raylib.h"
#include "ModuleGame.h"
#include "PhysicEntity.h"

class Ball : public PhysicEntity
{
public:
    Ball(ModulePhysics* physics, int _x, int _y, Module* _listener, Texture2D _texture);
    ~Ball() override;

    void Update() override;
    Vector2 GetPosition() const;

private:
    Texture2D texture;
    ModulePhysics* physics;
    int restitution;
};