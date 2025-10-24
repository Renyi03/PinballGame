#include "Globals.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleGame.h"
#include "ModuleAudio.h"
#include "ModulePhysics.h"

class Board {


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

	//CreateBoard();
	CreateBall();

	return ret;
}

// Load assets
bool ModuleGame::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

void ModuleGame::CreateBoard()
{
	static constexpr int boardVertices[16] = {
		240, 1120,
		180, 1067,
		180, 213,
		240, 160,
		480, 160,
		540, 213,
		540, 1067,
		480, 1120
	};

	boardBody = App->physics->CreateChain(0, 0, boardVertices, 100);
}

void ModuleGame::CreateBall()
{
	LOG("Creating circle");
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		
		App->physics->CreateCircle(GetMouseX(), GetMouseY(), 50);
	}
}

// Update: draw background
update_status ModuleGame::Update()
{
	return UPDATE_CONTINUE;
}
