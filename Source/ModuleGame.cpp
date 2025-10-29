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
	Vector2 PhysicEntity::GetPosition() const
	{
		int x, y;
		body->GetPosition(x,y);
		Vector2 result;
		result.x = x;
		result.y = y;
		return result;
	}

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
	static constexpr int boardRightWallVertices[50] = {
	291, 939,
	291, 921,
	454, 838,
	491, 838,
	491, 556,
	472, 532,
	486, 514,
	493, 491,
	494, 467,
	494, 325,
	483, 289,
	466, 256,
	452, 237,
	433, 218,
	414, 204,
	385, 186,
	387, 182,
	413, 196,
	429, 208,
	445, 222,
	460, 240,
	479, 268,
	495, 304,
	503, 342,
	503, 939
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
	428, 486,
	423, 467,
	458, 365,
	459, 338,
	447, 298,
	422, 262,
	392, 235,
	364, 215,
	369, 209,
	402, 235,
	426, 257,
	451, 292,
	467, 332,
	471, 365,
	439, 498
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
		347, 777,
		440, 727,
		452, 713,
		455, 747,
		447, 756,
		389, 801
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
	53, 756,
	45, 747,
	48, 713,
	60, 727,
	153, 777,
	141, 801
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
	343, 715,
	341, 702,
	387, 610,
	397, 603,
	409, 606,
	416, 617,
	416, 687,
	407, 697,
	364, 722,
	351, 721
	};
	BoardTriangleR(ModulePhysics* physics, int _x, int _y, Module* _listener)
		: PhysicEntity(physics->CreateBumper(0, 0, boardTriangleRVertices, 20), _listener)
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
	136, 722,
	93, 697,
	84, 687,
	84, 617,
	91, 606,
	103, 603,
	113, 610,
	159, 702,
	157, 715,
	149, 721
	};
	BoardTriangleL(ModulePhysics* physics, int _x, int _y, Module* _listener)
		: PhysicEntity(physics->CreateBumper(0, 0, boardTriangleLVertices, 20), _listener)
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
	245, 555,
	196, 532,
	192, 522,
	196, 512,
	245, 489,
	259, 489,
	308, 512,
	312, 522,
	308, 532,
	259, 555
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
	350, 455,
	377, 400,
	392, 398,
	399, 411,
	371, 466,
	358, 466
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
	176, 465,
	148, 409,
	155, 399,
	169, 398,
	198, 455,
	191, 465
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
	126, 504,
	102, 480,
	82, 447,
	70, 414,
	63, 370,
	63, 343,
	69, 306,
	89, 258,
	125, 215,
	151, 196,
	169, 184,
	181, 182,
	190, 184,
	202, 199,
	201, 209,
	192, 219,
	169, 236,
	150, 254,
	129, 278,
	116, 298,
	105, 326,
	100, 354,
	100, 388,
	111, 438,
	124, 468,
	134, 495,
	133, 501
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
};

class SpringLauncherEntity : public PhysicEntity
{
public:
	SpringLauncherEntity(ModulePhysics* physics, int x, int y, Module* listener)
		: PhysicEntity(nullptr, listener)
	{
		// Get both the plunger and the base from physics
		b2Body* baseBody = nullptr;
		PhysBody* plungerBody = physics->CreateSpringLauncher(x, y, baseBody);

		// Store bodies
		springPlungerBody = plungerBody->body;
		springLauncherJoint = nullptr;
		// Create prismatic joint connecting base and plunger
		b2PrismaticJointDef jointDef;
		b2Vec2 axis(0.0f, -1.0f); // vertical movement
		jointDef.Initialize(baseBody, springPlungerBody, baseBody->GetWorldCenter(), axis);

		jointDef.enableLimit = true;
		jointDef.lowerTranslation = -PIXEL_TO_METERS(80);
		jointDef.upperTranslation = PIXEL_TO_METERS(0);

		jointDef.enableMotor = true;
		jointDef.maxMotorForce = 1500.0f;
		jointDef.motorSpeed = 0.0f;

		b2PrismaticJoint* joint = (b2PrismaticJoint*)physics->GetWorld()->CreateJoint(&jointDef);

		springLauncherJoint = joint;

		body = plungerBody;

	}

	void Update() override
	{
		//we can more this code if needed. but this code is to detect how long player is holding down key to influence spring power
	//and launching ball once key is released
		if (springLauncherJoint != nullptr)
		{
			static float holdTime = 0.0f;
			static bool charging = false;

			if (IsKeyDown(KEY_DOWN))
			{
				charging = true;
				holdTime += GetFrameTime();
				springLauncherJoint->SetMotorSpeed(-1.0f); // Pull down
			}
			else if (charging && IsKeyReleased(KEY_DOWN))
			{
				charging = false;
				float power = std::min(holdTime * 25.0f, 60.0f);
				//^^25 is conversion factor from seconds to whatever box2D uses, and 60 is like the max cap of how long you hold
				holdTime = 0.0f;
				springLauncherJoint->SetMotorSpeed(power); // Launch
			}
			else
			{
				springLauncherJoint->SetMotorSpeed(0.0f);
			}
		}
		
	}

private:
	Texture2D texture;
	b2PrismaticJoint* springLauncherJoint = nullptr;
	b2Body* springPlungerBody = nullptr;
};


class Ball : public PhysicEntity
{
public:
	Ball(ModulePhysics* physics, int _x, int _y, Module* _listener, Texture2D _texture)
		: PhysicEntity(physics->CreateCircle(_x, _y, 10), _listener)
		, texture(_texture)
	{

	}

	void Update() override
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
private:
	Texture2D texture;

};

class Spring : public PhysicEntity
{
public:
	Spring(ModulePhysics* physics, int _x, int _y, Module* _listener, Texture2D _texture)
		: PhysicEntity(physics->CreateCircle(_x, _y, 10), _listener)
		, texture(_texture)
	{

	}

	void Update() override
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
	ballTexture = LoadTexture("Assets/Turbo.png");
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
	entities.emplace_back(new SpringLauncherEntity(App->physics, 520, 800, this));
	balls = new Ball(App->physics, 480, 200, this, ballTexture);
	entities.emplace_back(balls);


	App->physics->CreateLeftFlipper(SCREEN_WIDTH/2-110, SCREEN_HEIGHT-140, leftJoint);
	App->physics->CreateRightFlipper(SCREEN_WIDTH/2+70, SCREEN_HEIGHT-140, rightJoint);


	return ret;
}

// Load assets
bool ModuleGame::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update: draw background
update_status ModuleGame::Update()
{
	for (auto& entity : entities) {
		entity->Update();
	}

	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		entities.emplace_back(new Ball(App->physics, GetMouseX(), GetMouseY(), this, ballTexture));
	}
	if (IsKeyDown(KEY_LEFT)) {
		leftJoint->SetMotorSpeed(-15.0f);
	}
	else {
		leftJoint->SetMotorSpeed(15.0f);
	}
	if (IsKeyDown(KEY_RIGHT)) {
		rightJoint->SetMotorSpeed(15.0f);
	}
	else {
		rightJoint->SetMotorSpeed(-15.0f);
	}


	if (balls->GetPosition().y >= 900.0f) {
		delete balls;
		balls = new Ball(App->physics, 480, 200, this, ballTexture);
		entities.emplace_back(balls);
	}

	return UPDATE_CONTINUE;
}
