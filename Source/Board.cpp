#include "Board.h"
#include "PhysicEntity.h"
#include "ModulePhysics.h"


Board::Board(ModulePhysics* physics, int _x, int _y, Module* _listener)
    : PhysicEntity(physics->CreateChain(0, 0, boardVertices, 52), _listener, EntityType::WALL)
{
}

void Board::Update()
{
}

BoardRightWall::BoardRightWall(ModulePhysics* physics, int _x, int _y, Module* _listener)
    : PhysicEntity(physics->CreateChain(0, 0, boardRightWallVertices, 50), _listener, EntityType::WALL)
{
}

void BoardRightWall::Update()
{
}

BoardTube::BoardTube(ModulePhysics* physics, int _x, int _y, Module* _listener)
	: PhysicEntity(physics->CreateChain(0, 0, boardTubeVertices, 30), _listener)
{
}

void BoardTube::Update()
{
}

BoardLeftWall::BoardLeftWall(ModulePhysics* physics, int _x, int _y, Module* _listener)
	: PhysicEntity(physics->CreateChain(0, 0, boardLeftWallVertices, 28), _listener, EntityType::WALL)
{
}

void BoardLeftWall::Update()
{
}

BoardNearFlippersR::BoardNearFlippersR(ModulePhysics* physics, int _x, int _y, Module* _listener)
	: PhysicEntity(physics->CreateChain(0, 0, boardNearFlippersRVertices, 20), _listener, EntityType::WALL)
{
}

void BoardNearFlippersR::Update()
{

}

BoardNearFlippersL::BoardNearFlippersL(ModulePhysics* physics, int _x, int _y, Module* _listener)
	: PhysicEntity(physics->CreateChain(0, 0, boardNearFlippersLVertices, 20), _listener, EntityType::WALL)
{
}

void BoardNearFlippersL::Update()
{

}

BoardTriangleR::BoardTriangleR(ModulePhysics* physics, int _x, int _y, Module* _listener)
	: PhysicEntity(physics->CreateBumper(0, 0, boardTriangleRVertices, 20), _listener, EntityType::BUMPER, 30)
{
}
void BoardTriangleR::Update()
{

}

BoardTriangleL::BoardTriangleL(ModulePhysics* physics, int _x, int _y, Module* _listener)
	: PhysicEntity(physics->CreateBumper(0, 0, boardTriangleLVertices, 20), _listener, EntityType::BUMPER, 30)
{
}
void BoardTriangleL::Update()
{

}

BoardRhombus::BoardRhombus(ModulePhysics* physics, int _x, int _y, Module* _listener)
	: PhysicEntity(physics->CreateChain(0, 0, boardRhombusVertices, 20), _listener, EntityType::WALL)
{
}
void BoardRhombus::Update(){

}

BoardOvalR::BoardOvalR(ModulePhysics* physics, int _x, int _y, Module* _listener)
	: PhysicEntity(physics->CreateChain(0, 0, boardOvalRVertices, 12), _listener, EntityType::WALL)
{
}
void BoardOvalR::Update()
{

}

BoardOvalL::BoardOvalL(ModulePhysics* physics, int _x, int _y, Module* _listener)
	: PhysicEntity(physics->CreateChain(0, 0, boardOvalLVertices, 12), _listener, EntityType::WALL)
{
}
void BoardOvalL::Update()
{

}

BoardLeftPassage::BoardLeftPassage(ModulePhysics* physics, int _x, int _y, Module* _listener)
	: PhysicEntity(physics->CreateChain(0, 0, boardLeftPassageVertices, 54), _listener, EntityType::WALL)
{
}
void BoardLeftPassage::Update()
{

}

BoardSmallOvalR::BoardSmallOvalR(ModulePhysics* physics, int _x, int _y, Module* _listener)
	: PhysicEntity(physics->CreateChain(0, 0, boardSmallOvalRVertices, 12), _listener, EntityType::WALL)
{
}
void BoardSmallOvalR::Update()
{

}

BoardSmallOvalL::BoardSmallOvalL(ModulePhysics* physics, int _x, int _y, Module* _listener)
	: PhysicEntity(physics->CreateChain(0, 0, boardSmallOvalLVertices, 12), _listener, EntityType::WALL)
{
}
void BoardSmallOvalL::Update()
{

}