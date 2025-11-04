#include "Launcher.h"
#include "PhysicEntity.h"
#include "ModulePhysics.h"

SpringLauncherEntity::SpringLauncherEntity(ModulePhysics* physics, int x, int y, Module* listener, Sound spring)
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
void SpringLauncherEntity::Update()
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