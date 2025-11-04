#include "Globals.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleGame.h"
#include "ModuleAudio.h"
#include "ModulePhysics.h"
#include "PhysicEntity.h"
#include "Ball.h"
#include "Board.h"
#include "Bumper.h"
#include "Miku.h"
#include "Flipper.h"
#include "Launcher.h"
#include "Multiplier.h"

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

	// Loading all the textures
	ballTexture = LoadTexture("Assets/Textures/Turbo.png");
	yellowBumperTexture = LoadTexture("Assets/Textures/YellowBumper.png");
	redBumperTexture = LoadTexture("Assets/Textures/RedBumper.png");
	blueBumperTexture = LoadTexture("Assets/Textures/BlueBumper.png");
	bordersTexture = LoadTexture("Assets/Textures/Borders.png");
	leftTriangleBumper = LoadTexture("Assets/Textures/leftTriangleBumper.png");
	rightTriangleBumper = LoadTexture("Assets/Textures/rightTriangleBumper.png");
	sNailTexture = LoadTexture("Assets/Textures/sNail.png");
	rightFlipperTexture = LoadTexture("Assets/Textures/rightFlipper.png");
	leftFlipperTexture = LoadTexture("Assets/Textures/leftFlipper.png");
	rightSlugTexture = LoadTexture("Assets/Textures/rightSlug.png");
	leftSlugTexture = LoadTexture("Assets/Textures/leftSlug.png");
	controls = LoadTexture("Assets/Textures/controls_menu.png");
	mTexture = LoadTexture("Assets/Textures/M_Sprite.png");
	iTexture = LoadTexture("Assets/Textures/I_Sprite.png");
	kTexture = LoadTexture("Assets/Textures/K_Sprite.png");
	uTexture = LoadTexture("Assets/Textures/U_Sprite.png");
	mTextureShine = LoadTexture("Assets/Textures/M_ShineSprite.png");
	iTextureShine = LoadTexture("Assets/Textures/I_ShineSprite.png");
	kTextureShine = LoadTexture("Assets/Textures/K_ShineSprite.png");
	uTextureShine = LoadTexture("Assets/Textures/U_ShineSprite.png");
	multiplierTexture = LoadTexture("Assets/Textures/Multiplier.png");

	// Loading all the sounds and music
	bumperHit = LoadSound("Assets/Sounds/bumper_hit.wav");
	flipper = LoadSound("Assets/Sounds/flipper_no_hit.wav");
	miku = LoadSound("Assets/Sounds/miku.wav");
	wallHit = LoadSound("Assets/Sounds/wall_hit.wav");
	multiplierSound = LoadSound("Assets/Sounds/multiplier.wav");
	letterActivate = LoadSound("Assets/Sounds/letter_activate.wav");
	bgm = LoadMusicStream("Assets/Sounds/bgm.wav");
	SetMusicVolume(bgm, 0.10f);
	PlayMusicStream(bgm);

	bool ret = true;
	changeGravity = false;

	// Entity creation
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

	M = new Miku(App->physics, 116, 541, 22, this, mTexture, mTextureShine);
	entities.emplace_back(M);
	TraceLog(LOG_INFO, "Created M - entities.size(): %d", entities.size());

	I = new Miku(App->physics, 280, 262, 22, this, iTexture, iTextureShine);
	entities.emplace_back(I);
	TraceLog(LOG_INFO, "Created I - entities.size(): %d", entities.size());

	K = new Miku(App->physics, 347, 747, 22, this, kTexture, kTextureShine);
	entities.emplace_back(K);
	TraceLog(LOG_INFO, "Created K - entities.size(): %d", entities.size());

	U = new Miku(App->physics, 470, 472, 22, this, uTexture, uTextureShine);
	entities.emplace_back(U);
	TraceLog(LOG_INFO, "Created U - entities.size(): %d", entities.size());

	leftFlipperEntity = new LeftFlipper(App->physics, SCREEN_WIDTH / 2 - 115, SCREEN_HEIGHT - 140, this, leftJoint, leftFlipperTexture);
	entities.emplace_back(leftFlipperEntity);
	TraceLog(LOG_INFO, "Created Left Flipper - entities.size(): %d", entities.size());

	rightFlipperEntity = new RightFlipper(App->physics, SCREEN_WIDTH / 2 + 65, SCREEN_HEIGHT - 140, this, rightJoint, rightFlipperTexture);
	entities.emplace_back(rightFlipperEntity);
	TraceLog(LOG_INFO, "Created Right Flipper - entities.size(): %d", entities.size());

	entities.emplace_back(new MultiplierZone(App->physics, 138, 344, 22, this, 2, multiplierTexture));
	TraceLog(LOG_INFO, "Created Multiplier zone - entities.size(): %d", entities.size());

	ball = new Ball(App->physics, 480, 200, this, ballTexture);
	entities.emplace_back(ball);
	TraceLog(LOG_INFO, "Created Ball- entities.size(): %d", entities.size());


	TraceLog(LOG_INFO, "=== Finished entity creation ===");
	TraceLog(LOG_INFO, "Total entities: %d", entities.size());


	return ret;
}

bool ModuleGame::CleanUp()
{
	// Deleting the entities
	TraceLog(LOG_INFO, "DELETING ENTITIES");
	for (int i = 0; i < entities.size(); ++i) {
		delete entities[i];
		entities[i] = nullptr;
	}
	entities.clear();
	TraceLog(LOG_INFO, "Deleted entities - entities.size(): %d", entities.size());

	// Unloading textures
	TraceLog(LOG_INFO, "UNLOADING TEXTURES");
	UnloadTexture(ballTexture);
	UnloadTexture(yellowBumperTexture);
	UnloadTexture(redBumperTexture);
	UnloadTexture(blueBumperTexture);
	UnloadTexture(bordersTexture);
	UnloadTexture(leftTriangleBumper);
	UnloadTexture(rightTriangleBumper);
	UnloadTexture(sNailTexture);
	UnloadTexture(rightFlipperTexture);
	UnloadTexture(leftFlipperTexture);
	UnloadTexture(rightSlugTexture);
	UnloadTexture(leftSlugTexture);
	UnloadTexture(controls);
	UnloadTexture(mTexture);
	UnloadTexture(mTextureShine);
	UnloadTexture(iTexture);
	UnloadTexture(iTextureShine);
	UnloadTexture(kTexture);
	UnloadTexture(kTextureShine);
	UnloadTexture(uTexture);
	UnloadTexture(uTextureShine);
	UnloadTexture(multiplierTexture);

	// Unloading sounds and music
	TraceLog(LOG_INFO, "UNLOADING AUDIO");
	UnloadSound(bumperHit);
	UnloadSound(flipper);
	UnloadSound(miku);
	UnloadSound(wallHit);
	UnloadSound(multiplierSound);
	UnloadSound(letterActivate);
	UnloadMusicStream(bgm);

	
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
				PlaySound(letterActivate);
				// Change the texture to shine version
				Miku* mikuLetter = dynamic_cast<Miku*>(entities[i]);
				if (mikuLetter != nullptr) {
					mikuLetter->Activate();
				}
				// We put the boolean of the sensor in false so it can't be activated again
				entities[i]->isMiku = false;
				TraceLog(LOG_INFO, "Miku counter: %d", mikuCtr);
				// If 4 Miku sensors are activated, Miku Combo is activated
				if (mikuCtr == 4) {
					MikuCombo();
				}
			}
			// Plays sounds according to the entity type
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
	TraceLog(LOG_INFO, "New total balls: %d", totalBalls);
	// Activates all sensors again
	M->isMiku = true;
	M->Deactivate();  // Reset to normal texture

	I->isMiku = true;
	I->Deactivate();

	K->isMiku = true;
	K->Deactivate();

	U->isMiku = true;
	U->Deactivate();
	// Resets Miku Counter
	mikuCtr = 0;
	TraceLog(LOG_INFO, "Miku combo reset");
}


update_status ModuleGame::Update()
{
	DrawTexture(bordersTexture, 0, 0, WHITE);
	
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
		totalBalls = 3; // Resets the total balls amount in case Miku Combo was achieved in the previous round
		if (currentScore > highestScore) {
			highestScore = currentScore; // Updates highest score
		}

		// Activates all sensors again
		M->isMiku = true;
		M->Deactivate();  // Reset to normal texture

		I->isMiku = true;
		I->Deactivate();

		K->isMiku = true;
		K->Deactivate();

		U->isMiku = true;
		U->Deactivate();
		// Resets Miku Counter
		mikuCtr = 0;

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
		DrawText(TextFormat("BALLS: %d/%d", currentBall, totalBalls), 420, 79, 20, GREEN);

		// Flipper controls and sounds
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

	DrawTexture(leftTriangleBumper, 82, 604, WHITE);
	DrawTexture(rightTriangleBumper, 337, 604, WHITE);
	DrawTexture(sNailTexture, 244, 163, WHITE);
	DrawTexture(sNailTexture, 302, 163, WHITE);
	DrawTexture(rightSlugTexture, 347, 580, WHITE);
	DrawTexture(leftSlugTexture, 32, 635, WHITE);

	// Shows the controls
	if (IsKeyPressed(KEY_H)) {
		controlsMenu = !controlsMenu;
	}
	if (controlsMenu) {
		DrawTexture(controls, 0, 0, WHITE);
	}

	return UPDATE_CONTINUE;
}
