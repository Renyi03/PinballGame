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

class BoardNearFlippersR : public PhysicEntity
{
public:
	static constexpr int boardNearFlippersRVertices[12] = {
		359, 801,
		447, 756,
		455, 747,
		452, 713,
		440, 727,
		347, 777
	};
	BoardNearFlippersR(ModulePhysics* physics, int _x, int _y, Module* _listener)
		: PhysicEntity(physics->CreateChain(0, 0, boardNearFlippersRVertices, 12), _listener)
	{
	}
	void Update() override
	{

	}
private:
	Texture2D texture;

};

class BoardNearFlippersL : public PhysicEntity
{
public:
	static constexpr int boardNearFlippersLVertices[12] = {
		141, 801,
		153, 777,
		60, 727,
		48, 713,
		45, 747,
		53, 756
	};
	BoardNearFlippersL(ModulePhysics* physics, int _x, int _y, Module* _listener)
		: PhysicEntity(physics->CreateChain(0, 0, boardNearFlippersLVertices, 12), _listener)
	{
	}
	void Update() override
	{

	}
private:
	Texture2D texture;

};

class BoardTriangleR : public PhysicEntity
{
public:
	static constexpr int boardTriangleRVertices[20] = {
		351, 721,
		364, 722,
		407, 697,
		416, 687,
		416, 617,
		409, 606,
		397, 603,
		387, 610,
		341, 702,
		343, 715
	};
	BoardTriangleR(ModulePhysics* physics, int _x, int _y, Module* _listener)
		: PhysicEntity(physics->CreateChain(0, 0, boardTriangleRVertices, 20), _listener)
	{
	}
	void Update() override
	{

	}
private:
	Texture2D texture;

};

class BoardTriangleL : public PhysicEntity
{
public:
	static constexpr int boardTriangleLVertices[20] = {
		149, 721,
		157, 715,
		159, 702,
		113, 610,
		103, 603,
		91, 606,
		84, 617,
		84, 687,
		93, 697,
		136, 722
	};
	BoardTriangleL(ModulePhysics* physics, int _x, int _y, Module* _listener)
		: PhysicEntity(physics->CreateChain(0, 0, boardTriangleLVertices, 20), _listener)
	{
	}
	void Update() override
	{

	}
private:
	Texture2D texture;

};

class BoardRhombus : public PhysicEntity
{
public:
	static constexpr int boardRhombusVertices[20] = {
		259, 555,
		308, 532,
		312, 522,
		308, 512,
		259, 489,
		245, 489,
		196, 512,
		192, 522,
		196, 532,
		245, 555
	};
	BoardRhombus(ModulePhysics* physics, int _x, int _y, Module* _listener)
		: PhysicEntity(physics->CreateChain(0, 0, boardRhombusVertices, 20), _listener)
	{
	}
	void Update() override
	{

	}
private:
	Texture2D texture;

};

class BoardOvalR : public PhysicEntity
{
public:
	static constexpr int boardOvalRVertices[12] = {
		358, 466,
		371, 466,
		399, 411,
		392, 398,
		377, 400,
		350, 455
	};
	BoardOvalR(ModulePhysics* physics, int _x, int _y, Module* _listener)
		: PhysicEntity(physics->CreateChain(0, 0, boardOvalRVertices, 12), _listener)
	{
	}
	void Update() override
	{

	}
private:
	Texture2D texture;

};

class BoardOvalL : public PhysicEntity
{
public:
	static constexpr int boardOvalLVertices[12] = {
		191, 465,
		198, 455,
		169, 398,
		155, 399,
		148, 409,
		176, 465
	};
	BoardOvalL(ModulePhysics* physics, int _x, int _y, Module* _listener)
		: PhysicEntity(physics->CreateChain(0, 0, boardOvalLVertices, 12), _listener)
	{
	}
	void Update() override
	{

	}
private:
	Texture2D texture;

};

class BoardLeftPassage : public PhysicEntity
{
public:
	static constexpr int boardLeftPassageVertices[54] = {
		133, 501,
		134, 495,
		124, 468,
		111, 438,
		100, 388,
		100, 354,
		105, 326,
		116, 298,
		129, 278,
		150, 254,
		169, 236,
		192, 219,
		201, 209,
		202, 199,
		190, 184,
		181, 182,
		169, 184,
		151, 196,
		125, 215,
		89, 258,
		69, 306,
		63, 343,
		63, 370,
		70, 414,
		82, 447,
		102, 480,
		126, 504
	};
	BoardLeftPassage(ModulePhysics* physics, int _x, int _y, Module* _listener)
		: PhysicEntity(physics->CreateChain(0, 0, boardLeftPassageVertices, 54), _listener)
	{
	}
	void Update() override
	{

	}
private:
	Texture2D texture;

};

class BoardSmallOvalR : public PhysicEntity
{
public:
	static constexpr int boardSmallOvalRVertices[12] = {
		311, 163,
		319, 170,
		319, 223,
		310, 230,
		302, 223,
		302, 170
	};
	BoardSmallOvalR(ModulePhysics* physics, int _x, int _y, Module* _listener)
		: PhysicEntity(physics->CreateChain(0, 0, boardSmallOvalRVertices, 12), _listener)
	{
	}
	void Update() override
	{

	}
private:
	Texture2D texture;

};

class BoardSmallOvalL : public PhysicEntity
{
public:
	static constexpr int boardSmallOvalLVertices[12] = {
		252, 163,
		261, 170,
		261, 223,
		253, 230,
		244, 223,
		244, 170
	};
	BoardSmallOvalL(ModulePhysics* physics, int _x, int _y, Module* _listener)
		: PhysicEntity(physics->CreateChain(0, 0, boardSmallOvalLVertices, 12), _listener)
	{
	}
	void Update() override
	{

	}
private:
	Texture2D texture;

};

class YellowBumper : public PhysicEntity
{
public:
	YellowBumper(ModulePhysics* physics, int _x, int _y, Module* _listener)
		: PhysicEntity(physics->CreateCircularBumper(279, 379, 38), _listener)
	{
	}
	void Update() override
	{

	}
private:
	Texture2D texture;

};

class RedBumper : public PhysicEntity
{
public:
	RedBumper(ModulePhysics* physics, int _x, int _y, Module* _listener)
		: PhysicEntity(physics->CreateCircularBumper(338, 295, 38), _listener)
	{
	}
	void Update() override
	{

	}
private:
	Texture2D texture;

};

class BlueBumper : public PhysicEntity
{
public:
	BlueBumper(ModulePhysics* physics, int _x, int _y, Module* _listener)
		: PhysicEntity(physics->CreateCircularBumper(220, 295, 38), _listener)
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
	entities.emplace_back(new BoardNearFlippersR(App->physics, 0, 0, this));
	entities.emplace_back(new BoardNearFlippersL(App->physics, 0, 0, this));
	entities.emplace_back(new BoardTriangleR(App->physics, 0, 0, this));
	entities.emplace_back(new BoardTriangleL(App->physics, 0, 0, this));
	entities.emplace_back(new BoardRhombus(App->physics, 0, 0, this));
	entities.emplace_back(new BoardOvalR(App->physics, 0, 0, this));
	entities.emplace_back(new BoardOvalL(App->physics, 0, 0, this));
	entities.emplace_back(new BoardLeftPassage(App->physics, 0, 0, this));
	entities.emplace_back(new BoardSmallOvalR(App->physics, 0, 0, this));
	entities.emplace_back(new BoardSmallOvalL(App->physics, 0, 0, this));
	entities.emplace_back(new YellowBumper(App->physics, 0, 0, this));
	entities.emplace_back(new RedBumper(App->physics, 0, 0, this));
	entities.emplace_back(new BlueBumper(App->physics, 0, 0, this));

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
