#include "Ball.h"
#include "ModulePhysics.h"
#include "raylib.h"

Ball::Ball(ModulePhysics* physics, int x, int y, Module* listener, Texture2D texture)
    : PhysicEntity(physics->CreateCircle(x, y, 10), listener)
    , texture(texture)
    , physics(physics)
{
}

Ball::~Ball()
{
    if (body != nullptr && physics != nullptr)
    {
        physics->DestroyBody(body);
        body = nullptr;
    }
}

void Ball::Update()
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

Vector2 Ball::GetPosition() const
{
    int x = 0, y = 0;
    if (body != nullptr)
        body->GetPhysicPosition(x, y);
    return { (float)x, (float)y };
}
