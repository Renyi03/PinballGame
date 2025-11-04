#pragma once
#include "Module.h"
#include "ModulePhysics.h"
#include "Globals.h"
#include "raylib.h"
#include "p2Point.h"
#include <vector>
#include "Box2D/Box2D.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleGame.h"
#include "ModuleAudio.h"

class Module;

class PhysBody;

enum class EntityType {
    DEFAULT,
    BALL,
    BUMPER,
    FLIPPER,
    SPRING,
    MULTIPLIER,
    WALL
};

class PhysicEntity
{
protected:
    PhysicEntity(PhysBody* _body, Module* _listener, EntityType _entityType = EntityType::DEFAULT,
        int _scoreValue = 0, int _multiplierValue = 1, bool _isMiku = false)
        : body(_body), listener(_listener), entityType(_entityType),
        scoreValue(_scoreValue), multiplierValue(_multiplierValue), isMiku(_isMiku)
    {
        if (_body != nullptr) {
            body->listener = _listener;
        }
    }

public:
    virtual ~PhysicEntity() = default;
    virtual void Update() = 0;

    PhysBody* GetBody() { return body; }
    EntityType GetEntityType() { return entityType; }
    int GetScoreValue() { return scoreValue; }
    int GetMultiplierValue() { return multiplierValue; }

    bool isMiku;

protected:
    PhysBody* body;
    Module* listener;
    EntityType entityType;
    int scoreValue;
    double multiplierValue;
};
