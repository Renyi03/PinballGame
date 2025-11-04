#include "Globals.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleGame.h"
#include "ModuleAudio.h"
#include "ModulePhysics.h"

class PhysicEntity
{
protected:

	PhysicEntity(PhysBody* _body, Module* _listener, EntityType _entityType = EntityType::DEFAULT, int _scoreValue = 0, int _multiplierValue = 1, bool _isMiku = false)
		: body(_body), listener(_listener), entityType(_entityType), scoreValue(_scoreValue), multiplierValue(_multiplierValue), isMiku(_isMiku)
	{
		if (_body != nullptr) {
			body->listener = _listener;
			TraceLog(LOG_INFO, "PhysicEntity created: body=%p, listener=%p", _body, _listener);
		}
		TraceLog(LOG_INFO, "PhysicEntity created: body=%p, listener=%p", _body, _listener);
	}

public:
	virtual ~PhysicEntity() = default;
	virtual void Update() = 0;

	virtual int RayHit(vec2<int> ray, vec2<int> mouse, vec2<float>& normal)
	{
		return 0;
	}
	PhysBody* GetBody()
	{
		return body;
	}
	EntityType GetEntityType() {
		return entityType;
	}
	int GetScoreValue() {
		return scoreValue;
	}
	int GetMultiplierValue() {
		return multiplierValue;
	}

	bool isMiku;

protected:
	PhysBody* body;
	Module* listener;
	EntityType entityType;
	int scoreValue;
	double multiplierValue;
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
		: PhysicEntity(physics->CreateChain(0, 0, boardVertices, 52), _listener, EntityType::WALL)
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
	491, 832,
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
		: PhysicEntity(physics->CreateChain(0, 0, boardRightWallVertices, 50), _listener, EntityType::WALL)
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
	7, 832,
	46, 838,
	209, 922,
	208, 939,
	7, 939
	};
	BoardLeftWall(ModulePhysics* physics, int _x, int _y, Module* _listener)
		: PhysicEntity(physics->CreateChain(0, 0, boardLeftWallVertices, 28), _listener, EntityType::WALL)
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
	static constexpr int boardNearFlippersRVertices[20] = {
		347, 777,
		436, 730,
		444, 718,
		444, 590,
		450, 580,
		462, 580,
		468, 590,
		468, 735,
		452, 755,
		359, 801
	};
	BoardNearFlippersR(ModulePhysics* physics, int _x, int _y, Module* _listener)
		: PhysicEntity(physics->CreateChain(0, 0, boardNearFlippersRVertices, 20), _listener, EntityType::WALL)
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
	static constexpr int boardNearFlippersLVertices[20] = {
		48, 755,
		32, 735,
		32, 642,
		35, 635,
		52, 635,
		56, 642,
		56, 718,
		64, 730,
		153, 777,
		141, 801
	};
	BoardNearFlippersL(ModulePhysics* physics, int _x, int _y, Module* _listener)
		: PhysicEntity(physics->CreateChain(0, 0, boardNearFlippersLVertices, 20), _listener, EntityType::WALL)
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
		: PhysicEntity(physics->CreateBumper(0, 0, boardTriangleRVertices, 20), _listener, EntityType::BUMPER, 30)
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
		: PhysicEntity(physics->CreateBumper(0, 0, boardTriangleLVertices, 20), _listener, EntityType::BUMPER, 30)
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
		: PhysicEntity(physics->CreateChain(0, 0, boardRhombusVertices, 20), _listener, EntityType::WALL)
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
		: PhysicEntity(physics->CreateChain(0, 0, boardOvalRVertices, 12), _listener, EntityType::WALL)
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
		: PhysicEntity(physics->CreateChain(0, 0, boardOvalLVertices, 12), _listener, EntityType::WALL)
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
		: PhysicEntity(physics->CreateChain(0, 0, boardLeftPassageVertices, 54), _listener, EntityType::WALL)
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
		: PhysicEntity(physics->CreateChain(0, 0, boardSmallOvalRVertices, 12), _listener, EntityType::WALL)
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
		: PhysicEntity(physics->CreateChain(0, 0, boardSmallOvalLVertices, 12), _listener, EntityType::WALL)
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
	YellowBumper(ModulePhysics* physics, int _x, int _y, Module* _listener, Texture2D _texture)
		: PhysicEntity(physics->CreateCircularBumper(279, 379, 38), _listener, EntityType::BUMPER, 50)
		, texture(_texture)
	{
	}
	void Update() override
	{
		int x, y;
		body->GetPhysicPosition(x, y);
		Vector2 position{ (float)x, (float)y };
		DrawTexture(texture, x - 38, y - 38, WHITE);
	}
private:
	Texture2D texture;

};

class RedBumper : public PhysicEntity
{
public:
	RedBumper(ModulePhysics* physics, int _x, int _y, Module* _listener, Texture2D _texture)
		: PhysicEntity(physics->CreateCircularBumper(338, 295, 38), _listener, EntityType::BUMPER, 100)
		, texture(_texture)
	{
	}
	void Update() override
	{
		int x, y;
		body->GetPhysicPosition(x, y);
		Vector2 position{ (float)x, (float)y };
		DrawTexture(texture, x - 38, y - 38, WHITE);
	}
private:
	Texture2D texture;

};

class BlueBumper : public PhysicEntity
{
public:
	BlueBumper(ModulePhysics* physics, int _x, int _y, Module* _listener, Texture2D _texture)
		: PhysicEntity(physics->CreateCircularBumper(220, 295, 38), _listener, EntityType::BUMPER, 25)
		, texture(_texture)
	{
	}
	void Update() override
	{
		int x, y;
		body->GetPhysicPosition(x, y);
		Vector2 position{ (float)x, (float)y };
		DrawTexture(texture, x - 38, y - 38, WHITE);
	}
private:
	Texture2D texture;

};

class SpringLauncherEntity : public PhysicEntity
{
public:
	SpringLauncherEntity(ModulePhysics* physics, int x, int y, Module* listener, Sound spring)
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
				PlaySound(spring);
			}
		}

	}
private:
	Texture2D texture;
	b2PrismaticJoint* springLauncherJoint = nullptr;
	b2Body* springPlungerBody = nullptr;
	Sound spring = LoadSound("Assets/Sounds/spring.wav");
};

class LeftFlipper : public PhysicEntity
{
public:
	LeftFlipper(ModulePhysics* physics, int x, int y, Module* listener, b2RevoluteJoint*& joint, Texture2D _texture)
		: PhysicEntity(physics->CreateLeftFlipper(x, y, joint), listener, EntityType::FLIPPER, 0)
		, texture(_texture)
	{
		this->joint = joint;
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
	b2RevoluteJoint* joint;
	Texture2D texture;
};

class RightFlipper : public PhysicEntity
{
public:
	RightFlipper(ModulePhysics* physics, int x, int y, Module* listener, b2RevoluteJoint*& joint, Texture2D _texture)
		: PhysicEntity(physics->CreateRightFlipper(x, y, joint), listener, EntityType::FLIPPER, 0)
		, texture(_texture)
	{
		this->joint = joint;
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
	b2RevoluteJoint* joint;
	Texture2D texture;
};

class Ball : public PhysicEntity
{
public:
	Ball(ModulePhysics* physics, int _x, int _y, Module* _listener, Texture2D _texture)
		: PhysicEntity(physics->CreateCircle(_x, _y, 10), _listener)
		, texture(_texture)
		, physics(physics)
	{

	}
	~Ball() override
	{
		if (body != nullptr && physics != nullptr) {
			physics->DestroyBody(body);
			body = nullptr;
		}
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
	Vector2 GetPosition() const
	{
		int x = 0, y = 0;
		if (body != nullptr)
			body->GetPhysicPosition(x, y);
		return { (float)x, (float)y };
	}
private:
	Texture2D texture;
	ModulePhysics* physics;
	int restitution;

};

class MultiplierZone : public PhysicEntity
{
public:
	MultiplierZone(ModulePhysics* physics, int _x, int _y, int _radius, Module* _listener, int _multiplier)
		: PhysicEntity(physics->CreateCircleSensor(_x, _y, _radius), _listener, EntityType::MULTIPLIER, 0, 2) 
		// Even though it says that the multiplier is 2, since the sensor detects the ball twice, it's going to be 4
		, multiplier(_multiplier)
	{
	}
	void Update() override
	{
	}

private:
	int multiplier;
	Texture2D texture;
};

class Miku : public PhysicEntity
{
public:
	Miku(ModulePhysics* physics, int _x, int _y, int _radius, Module* _listener, Texture2D _texture)
		: PhysicEntity(physics->CreateCircleSensor(_x, _y, _radius), _listener, EntityType::MULTIPLIER, 0, 1, true)
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
{
}

// Load assets
bool ModuleGame::Start()
{
	LOG("Loading Intro assets");

	ballTexture = LoadTexture("Assets/Turbo.png");
	yellowBumperTexture = LoadTexture("Assets/YellowBumper.png");
	redBumperTexture = LoadTexture("Assets/RedBumper.png");
	blueBumperTexture = LoadTexture("Assets/BlueBumper.png");
	bordersTexture = LoadTexture("Assets/Borders.png");
	leftTriangleBumper = LoadTexture("Assets/leftTriangleBumper.png");
	rightTriangleBumper = LoadTexture("Assets/rightTriangleBumper.png");
	sNailTexture = LoadTexture("Assets/sNail.png");
	rightFlipperTexture = LoadTexture("Assets/rightFlipper.png");
	leftFlipperTexture = LoadTexture("Assets/leftFlipper.png");
	rightSlugTexture = LoadTexture("Assets/rightSlug.png");
	leftSlugTexture = LoadTexture("Assets/leftSlug.png");
	mTexture = LoadTexture("Assets/M_Sprite.png");
	iTexture = LoadTexture("Assets/I_Sprite.png");
	kTexture = LoadTexture("Assets/K_Sprite.png");
	uTexture = LoadTexture("Assets/U_Sprite.png");

	bumperHit = LoadSound("Assets/Sounds/bumper_hit.wav");
	flipper = LoadSound("Assets/Sounds/flipper_no_hit.wav");
	miku = LoadSound("Assets/Sounds/miku.wav");
	wallHit = LoadSound("Assets/Sounds/wall_hit.wav");
	multiplierSound = LoadSound("Assets/Sounds/multiplier.wav");
	bgm = LoadMusicStream("Assets/Sounds/bgm.wav");
	SetMusicVolume(bgm, 0.10f);
	PlayMusicStream(bgm);

	bool ret = true;
	changeGravity = false;

	TraceLog(LOG_INFO, "=== Starting entity creation ===");
	TraceLog(LOG_INFO, "entities.size() before: %d", entities.size());
	entities.emplace_back(new Board(App->physics, 0, 0, this));
	TraceLog(LOG_INFO, "Created Board - entities.size(): %d", entities.size());

	entities.emplace_back(new BoardRightWall(App->physics, 0, 0, this));
	TraceLog(LOG_INFO, "Created Board Right wall - entities.size(): %d", entities.size());

	entities.emplace_back(new BoardTube(App->physics, 0, 0, this));
	TraceLog(LOG_INFO, "Created Board Tube- entities.size(): %d", entities.size());

	entities.emplace_back(new BoardLeftWall(App->physics, 0, 0, this));
	TraceLog(LOG_INFO, "Created Board Left Wall- entities.size(): %d", entities.size());

	entities.emplace_back(new BoardNearFlippersR(App->physics, 0, 0, this));
	TraceLog(LOG_INFO, "Created Board Near Flippers R- entities.size(): %d", entities.size());

	entities.emplace_back(new BoardNearFlippersL(App->physics, 0, 0, this));
	TraceLog(LOG_INFO, "Created Board Near Flippers L- entities.size(): %d", entities.size());

	boardTriangleR = new BoardTriangleR(App->physics, 0, 0, this);
	entities.emplace_back(boardTriangleR);
	TraceLog(LOG_INFO, "Created Board Triangle R- entities.size(): %d", entities.size());

	entities.emplace_back(new BoardTriangleL(App->physics, 0, 0, this));
	TraceLog(LOG_INFO, "Created Board Triangle L- entities.size(): %d", entities.size());

	entities.emplace_back(new BoardRhombus(App->physics, 0, 0, this));
	TraceLog(LOG_INFO, "Created Board Rhombus- entities.size(): %d", entities.size());

	entities.emplace_back(new BoardOvalR(App->physics, 0, 0, this));
	TraceLog(LOG_INFO, "Created Board Oval R- entities.size(): %d", entities.size());

	entities.emplace_back(new BoardOvalL(App->physics, 0, 0, this));
	TraceLog(LOG_INFO, "Created Board Oval L- entities.size(): %d", entities.size());

	entities.emplace_back(new BoardLeftPassage(App->physics, 0, 0, this));
	TraceLog(LOG_INFO, "Created Board Left Passage- entities.size(): %d", entities.size());

	entities.emplace_back(new BoardSmallOvalR(App->physics, 0, 0, this));
	TraceLog(LOG_INFO, "Created Board Small Oval R- entities.size(): %d", entities.size());

	entities.emplace_back(new BoardSmallOvalL(App->physics, 0, 0, this));
	TraceLog(LOG_INFO, "Created Board Small Oval L- entities.size(): %d", entities.size());

	entities.emplace_back(new YellowBumper(App->physics, 0, 0, this, yellowBumperTexture));
	TraceLog(LOG_INFO, "Created Board Yellow Bumper- entities.size(): %d", entities.size());

	entities.emplace_back(new RedBumper(App->physics, 0, 0, this, redBumperTexture));
	TraceLog(LOG_INFO, "Created Board Red Bumper- entities.size(): %d", entities.size());

	entities.emplace_back(new BlueBumper(App->physics, 0, 0, this, blueBumperTexture)); 
	TraceLog(LOG_INFO, "Created Board Blue Bumper - entities.size(): %d", entities.size());

	springLauncherEntity = new SpringLauncherEntity(App->physics, 520, 800, this, spring);
	entities.emplace_back(springLauncherEntity);
	TraceLog(LOG_INFO, "Created Board Spring- entities.size(): %d", entities.size());

	M = new Miku(App->physics, 116, 541, 22, this, mTexture);
	entities.emplace_back(M);
	TraceLog(LOG_INFO, "Created M - entities.size(): %d", entities.size());

	I = new Miku(App->physics, 280, 262, 22, this, iTexture);
	entities.emplace_back(I);
	TraceLog(LOG_INFO, "Created I - entities.size(): %d", entities.size());

	K = new Miku(App->physics, 347, 747, 22, this, kTexture);
	entities.emplace_back(K);
	TraceLog(LOG_INFO, "Created K - entities.size(): %d", entities.size());

	U = new Miku(App->physics, 470, 472, 22, this, uTexture);
	entities.emplace_back(U);
	TraceLog(LOG_INFO, "Created U - entities.size(): %d", entities.size());
	
	ball = new Ball(App->physics, 480, 200, this, ballTexture);
	entities.emplace_back(ball);
	TraceLog(LOG_INFO, "Created Ball- entities.size(): %d", entities.size());

	leftFlipperEntity = new LeftFlipper(App->physics, SCREEN_WIDTH / 2 - 115, SCREEN_HEIGHT - 140, this, leftJoint, leftFlipperTexture);
	entities.emplace_back(leftFlipperEntity);
	TraceLog(LOG_INFO, "Created Left Flipper - entities.size(): %d", entities.size());

	rightFlipperEntity = new RightFlipper(App->physics, SCREEN_WIDTH / 2 + 65, SCREEN_HEIGHT - 140, this, rightJoint, rightFlipperTexture);
	entities.emplace_back(rightFlipperEntity);
	TraceLog(LOG_INFO, "Created Right Flipper - entities.size(): %d", entities.size());

	entities.emplace_back(new MultiplierZone(App->physics, 138, 344, 22, this, 2));
	TraceLog(LOG_INFO, "Created Multiplier zone - entities.size(): %d", entities.size());



	TraceLog(LOG_INFO, "=== Finished entity creation ===");
	TraceLog(LOG_INFO, "Total entities: %d", entities.size());


	return ret;
}

// Load assets
bool ModuleGame::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

void ModuleGame::OnCollision(PhysBody* bodyA, PhysBody* bodyB)
{
	// Iterates through the entity vector
	for (int i = 0; i < entities.size(); ++i) {
		// Assigns the current entity being checked to entityBody
		PhysBody* entityBody = entities[i]->GetBody();
		// Checks if either of the PhysBodys correspond to the current entityBody
		if (bodyA == entityBody || bodyB == entityBody) {
			// Gets the score value of the current entity
			int score = entities[i]->GetScoreValue();
			double multiplier = entities[i]->GetMultiplierValue();
			bool miku = entities[i]->isMiku;
			if (multiplier > 1) {
				MultiplyScore(multiplier);
			}
			if (score > 0) {
				// Adds the score
				AddScore(score);
			}
			// If the entity is a Miku sensor
			if (miku == true) {
				// Adds to the counter to know how many sensors have been activated
				++mikuCtr;
				// We put the boolean of the sensor in false so it can't be activated again
				entities[i]->isMiku = false;
				TraceLog(LOG_INFO, "Miku counter: %d", mikuCtr);
				// If 4 Miku sensors are activated, Miku Combo is activated
				if (mikuCtr == 4) {
					MikuCombo();
				}
			}
			if (entities[i]->GetEntityType() == EntityType::BUMPER) {
				PlaySound(bumperHit);
			}
			else if (entities[i]->GetEntityType() == EntityType::WALL) {
				PlaySound(wallHit);
			}
		}
	}
}

void ModuleGame::AddScore(int points)
{
	// Addes the score to the current score
	currentScore += points;
	TraceLog(LOG_INFO, "Current Score: %d", currentScore);
}

void ModuleGame::MultiplyScore(double multiplier)
{
	// Multiplies the score multiplier to the current score
	scoreMultiplier = multiplier;
	currentScore *= scoreMultiplier;
	PlaySound(multiplierSound);
	TraceLog(LOG_INFO, "Multiplying score");
	TraceLog(LOG_INFO, "Current Score: %d", currentScore);
}

void ModuleGame::MikuCombo()
{
	TraceLog(LOG_INFO, "MIKU COMBO!!!!");
	PlaySound(miku);
	// Miku combo multiplies the current score by 3
	currentScore *= 3;
	TraceLog(LOG_INFO, "Current Score: %d", currentScore);
	// Miku combo spawns an extra ball!
	totalBalls++;
	// Activates all sensors again
	M->isMiku = true;
	I->isMiku = true;
	K->isMiku = true;
	U->isMiku = true;
	// Resets Miku Counter
	mikuCtr = 0;
	TraceLog(LOG_INFO, "Miku combo reset");
}

// Update: draw background
update_status ModuleGame::Update()
{
	if (!roundOver) {
		for (auto& entity : entities) {
			Ball* ball = dynamic_cast<Ball*>(entity);
			if (ball != nullptr) {
				Vector2 pos = ball->GetPosition();
				if (pos.y >= 925.0f) {
					delete ball;  // This will automatically destroy the physics body via destructor
					ball = nullptr;
					entity = nullptr;
					if (currentBall < totalBalls) {
						entity = new Ball(App->physics, 480, 200, this, ballTexture);
						currentBall++;
					}
					else {
						roundOver = true;
						entity = new Ball(App->physics, 480, 200, this, ballTexture);
						break;
					}

				}
			}
			if (entity != nullptr)
				entity->Update();
		}
	}

	if (roundOver) {
		totalBalls = 3;
		if (currentScore > highestScore) {
			highestScore = currentScore;
		}

		// Dark overlay
		DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, Fade(BLACK, 0.6f));

		// Main text
		DrawText("GAME OVER", SCREEN_WIDTH / 2 - 160, SCREEN_HEIGHT / 2 - 120, 50, RED);

		DrawText(TextFormat("YOUR SCORE: %d", currentScore), SCREEN_WIDTH / 2 - 140, SCREEN_HEIGHT / 2 - 40, 30, WHITE);
		DrawText(TextFormat("HIGH SCORE: %d", highestScore), SCREEN_WIDTH / 2 - 140, SCREEN_HEIGHT / 2, 30, YELLOW);
		DrawText(TextFormat("PREVIOUS SCORE: %d", previousScore), SCREEN_WIDTH / 2 - 140, SCREEN_HEIGHT / 2 + 40, 30, YELLOW);

		// Options
		DrawText("Press [R] to Restart", SCREEN_WIDTH / 2 - 140, SCREEN_HEIGHT / 2 + 100, 25, LIGHTGRAY);
		DrawText("Press [ESC] to Quit", SCREEN_WIDTH / 2 - 140, SCREEN_HEIGHT / 2 + 140, 25, LIGHTGRAY);

		if (IsKeyPressed(KEY_R)) {
			// Reset round
			previousScore = currentScore;
			currentScore = 0;
			currentBall = 1;
			roundOver = false;
		}
		if (IsKeyPressed(KEY_ESCAPE)) {
			return UPDATE_STOP; // Ends the game
		}

		return UPDATE_CONTINUE;
	}
		UpdateMusicStream(bgm);

		DrawText(TextFormat("SCORE: %d", currentScore), 200, 10, 30, GREEN);

	/*if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		entities.emplace_back(new Ball(App->physics, GetMouseX(), GetMouseY(), this, ballTexture));
	}*/
	if (IsKeyDown(KEY_LEFT)) {
		if (flipperSound == true) {
			PlaySound(flipper);
		}
		flipperSound = false;
		leftJoint->SetMotorSpeed(-15.0f);
	}
	else if (IsKeyReleased(KEY_LEFT)) {
		flipperSound = true;
		leftJoint->SetMotorSpeed(15.0f);
	}
	if (IsKeyDown(KEY_RIGHT)) {
		if (flipperSound == true) {
			PlaySound(flipper);
		}
		flipperSound = false;
		rightJoint->SetMotorSpeed(15.0f);
	}
	else if (IsKeyReleased(KEY_RIGHT)){
		flipperSound = true;
		rightJoint->SetMotorSpeed(-15.0f);
	}

	if (IsKeyPressed(KEY_G)) {
		b2Vec2 currentGravity = App->physics->world->GetGravity();
		changeGravity = !changeGravity;

		if (changeGravity) {
			currentGravity.y = -3.0f;
			App->physics->world->SetGravity(currentGravity);
			TraceLog(LOG_INFO, "Current gravity Y = %d", currentGravity.y);
		}
		else {
			currentGravity.y = -GRAVITY_Y;
			App->physics->world->SetGravity(currentGravity);
			TraceLog(LOG_INFO, "Current gravity Y = %d", currentGravity.y);
		}
	}

	if (IsKeyPressed(KEY_B)) {
		bounceMode = !bounceMode;

		if (bounceMode) {
			ball->GetBody()->body->GetFixtureList()->SetRestitution(0.4f);
			TraceLog(LOG_INFO, "Bounce mode activated");
		}
		else {
			ball->GetBody()->body->GetFixtureList()->SetRestitution(0.1f);

			TraceLog(LOG_INFO, "Bounce mode activated");

			TraceLog(LOG_INFO, "Bounce mode deactivated");

		}
	}

	DrawTexture(bordersTexture, 0, 0, WHITE);
	DrawTexture(leftTriangleBumper, 82, 604, WHITE);
	DrawTexture(rightTriangleBumper, 337, 604, WHITE);
	DrawTexture(sNailTexture, 244, 163, WHITE);
	DrawTexture(sNailTexture, 302, 163, WHITE);
	DrawTexture(rightSlugTexture, 347, 580, WHITE);
	DrawTexture(leftSlugTexture, 32, 635, WHITE);
	return UPDATE_CONTINUE;
}
