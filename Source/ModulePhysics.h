#pragma once

#include "Module.h"
#include "Globals.h"

#include "box2d\box2d.h"
#include "p2Point.h"

#define GRAVITY_X 0.0f
#define GRAVITY_Y -7.0f

inline float PIXEL_TO_METERS(float x)
{
	return ((float)x) / 50.0f;
}

inline float METERS_TO_PIXELS(float x)
{
	return ((float)x) * 50.0f;
}

class PhysBody
{
public:
	PhysBody() : listener(NULL), body(NULL)
	{
	}

	void GetPosition(int& x, int& y) const;
	void GetPhysicPosition(int& x, int& y) const;
	float GetRotation() const;
	bool Contains(int x, int y) const;
	int RayCast(int x1, int y1, int x2, int y2, float& normal_x, float& normal_y) const;

public:
	int width, height;
	b2Body* body;
	Module* listener;
};

// Module --------------------------------------
class ModulePhysics : public Module, public b2ContactListener // TODO
{
public:
	ModulePhysics(Application* app, bool start_enabled = true);
	~ModulePhysics();

	bool Start();
	update_status PreUpdate();
	update_status PostUpdate();
	bool CleanUp();

	PhysBody* CreateCircle(int x, int y, int radius);
	PhysBody* CreateCircleSensor(int x, int y, int radius);
	PhysBody* CreateRectangle(int x, int y, int width, int height);
	PhysBody* CreateRectangleSensor(int x, int y, int width, int height);
	PhysBody* CreateChain(int x, int y, const int* points, int size);
	PhysBody* CreateCircularBumper(int x, int y, int radius);
	PhysBody* CreateBumper(int x, int y, const int* points, int size);

	PhysBody* CreateSpringLauncher(int x, int y, b2Body*& outBase);
	b2World* GetWorld() { return world; }

	PhysBody* CreateLeftFlipper(int x, int y, b2RevoluteJoint*& joint);
	PhysBody* CreateRightFlipper(int x, int y, b2RevoluteJoint*& joint);


	// b2ContactListener ---
	void StartContact(b2Contact* contact);

private:

	b2World* world = nullptr;
	bool debug;
};