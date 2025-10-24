#include "Globals.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleGame.h"
#include "ModuleAudio.h"
#include "ModulePhysics.h"

class PhysicEntity
{
protected:

	PhysicEntity(PhysBody* _body, Module* _listener)
		: body(_body)
		, listener(_listener)
	{

	}

public:
	virtual ~PhysicEntity() = default;
	virtual void Update() = 0;

	virtual int RayHit(vec2<int> ray, vec2<int> mouse, vec2<float>& normal)
	{
		return 0;
	}

protected:
	PhysBody* body;
	Module* listener;
};

class Board : public PhysicEntity
{
public:
	static constexpr int boardVertices[52] = {
		291, 939,
		542, 939,
		542, 275,
		530, 250,
		513, 221,
		494, 196,
		466, 166,
		433, 142,
		400, 124,
		361, 110,
		337, 105,
		299, 100,
		275, 99,
		274, 99,
		250, 100,
		212, 105,
		188, 110,
		149, 124,
		116, 142,
		83, 166,
		55, 196,
		36, 221,
		19, 250,
		7, 275,
		7, 939,
		209, 939
	};
	Board(ModulePhysics* physics, int _x, int _y, Module* _listener)
		: PhysicEntity(physics->CreateChain(0, 0, boardVertices, 52), _listener)
	{
	}
	void Update() override
	{

	}
private:
	Texture2D texture;
};

class BoardRightWall : public PhysicEntity
{
public:
	static constexpr int boardRightWallVertices[] = {
		503, 939,
		503, 342,
		495, 304,
		479, 268,
		460, 240,
		445, 222,
		429, 208,
		413, 196,
		387, 182,
		385, 186,
		414, 204,
		433, 218,
		452, 237,
		466, 256,
		483, 289,
		494, 325,
		494, 467,
		493, 491,
		486, 514,
		472, 532,
		491, 556,
		491, 838,
		454, 838,
		291, 921,
		291, 939
	};
	BoardRightWall(ModulePhysics* physics, int _x, int _y, Module* _listener)
		: PhysicEntity(physics->CreateChain(0, 0, boardRightWallVertices, 50), _listener)
	{
	}
	void Update() override
	{

	}
private:
	Texture2D texture;
};

class BoardTube : public PhysicEntity
{
public:
	static constexpr int boardTubeVertices[30] = {
		439, 498,
		471, 365,
		467, 332,
		451, 292,
		426, 257,
		402, 235,
		369, 209,
		364, 215,
		392, 235,
		422, 262,
		447, 298,
		459, 338,
		458, 365,
		423, 467,
		428, 486
	};
	BoardTube(ModulePhysics* physics, int _x, int _y, Module* _listener)
		: PhysicEntity(physics->CreateChain(0, 0, boardTubeVertices, 30), _listener)
	{
	}
	void Update() override
	{

	}
private:
	Texture2D texture;

};

class BoardLeftWall : public PhysicEntity
{
public:
	static constexpr int boardLeftWallVertices[28] = {
		7 , 389,
		24, 460,
		43, 501,
		66, 533,
		68, 542,
		66, 551,
		47, 570,
		30, 591,
		7, 633,
		7, 838,
		46, 838,
		209, 922,
		208, 939,
		7, 939
	};
	BoardLeftWall(ModulePhysics* physics, int _x, int _y, Module* _listener)
		: PhysicEntity(physics->CreateChain(0, 0, boardLeftWallVertices, 28), _listener)
	{
	}
	void Update() override
	{

	}
private:
	Texture2D texture;

};

class BoardNearFlippers : public PhysicEntity
{
public:
	static constexpr int boardNearFlippersVertices[12] = {
		359, 801,
		447, 756,
		455, 747,
		452, 713,
		440, 727,
		347, 777
	};
	BoardNearFlippers(ModulePhysics* physics, int _x, int _y, Module* _listener)
		: PhysicEntity(physics->CreateChain(0, 0, boardNearFlippersVertices, 12), _listener)
	{
	}
	void Update() override
	{

	}
private:
	Texture2D texture;

};

ModuleGame::ModuleGame(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	
}

ModuleGame::~ModuleGame()
{}

// Load assets
bool ModuleGame::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;
	entities.emplace_back(new Board(App->physics, 0, 0, this));
	entities.emplace_back(new BoardRightWall(App->physics, 0, 0, this));
	entities.emplace_back(new BoardTube(App->physics, 0, 0, this));
	entities.emplace_back(new BoardLeftWall(App->physics, 0, 0, this));
	entities.emplace_back(new BoardNearFlippers(App->physics, 0, 0, this));

	return ret;
}

// Load assets
bool ModuleGame::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

void ModuleGame::CreateBall()
{
	LOG("Creating circle");
	App->physics->CreateCircle(GetMouseX(), GetMouseY(), 50);
}

// Update: draw background
update_status ModuleGame::Update()
{
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {

		CreateBall();
	}
	return UPDATE_CONTINUE;
}
