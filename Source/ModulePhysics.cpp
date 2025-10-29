#include "Globals.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModulePhysics.h"

#include "p2Point.h"

#include <math.h>



ModulePhysics::ModulePhysics(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	debug = true;
}

// Destructor
ModulePhysics::~ModulePhysics()
{
}

bool ModulePhysics::Start()
{
	LOG("Creating Physics 2D environment");

	world = new b2World(b2Vec2(GRAVITY_X, -GRAVITY_Y));
	
	return true;
}

update_status ModulePhysics::PreUpdate()
{
	float deltaTime = GetFrameTime();

	if (GetFPS() == 60) {
		if (deltaTime > 1.0f / 60.0f)
			deltaTime = 1.0f / 60.0f;
	}
	else if (GetFPS() == 30) {
		if (deltaTime > 1.0f / 30.0f)
			deltaTime = 1.0f / 30.0f;
	}

	world->Step(deltaTime, 6, 2);
	return UPDATE_CONTINUE;
}

//
update_status ModulePhysics::PostUpdate()
{
	

	if (IsKeyPressed(KEY_F1))
	{
		debug = !debug;
	}

	if (!debug)
	{
		return UPDATE_CONTINUE;
	}

	// Bonus code: this will iterate all objects in the world and draw the circles
	// You need to provide your own macro to translate meters to pixels
	for (b2Body* b = world->GetBodyList(); b; b = b->GetNext())
	{
		for(b2Fixture* f = b->GetFixtureList(); f; f = f->GetNext())
		{
			switch(f->GetType())
			{
				// Draw circles ------------------------------------------------
				case b2Shape::e_circle:
				{
					b2CircleShape* shape = (b2CircleShape*)f->GetShape();
					b2Vec2 pos = f->GetBody()->GetPosition();
					
					DrawCircle(METERS_TO_PIXELS(pos.x), METERS_TO_PIXELS(pos.y), (float)METERS_TO_PIXELS(shape->m_radius), Color{0, 0, 0, 128});
				}
				break;

				// Draw polygons ------------------------------------------------
				case b2Shape::e_polygon:
				{
					b2PolygonShape* polygonShape = (b2PolygonShape*)f->GetShape();
					int32 count = polygonShape->m_count;
					b2Vec2 prev, v;

					for(int32 i = 0; i < count; ++i)
					{
						v = b->GetWorldPoint(polygonShape->m_vertices[i]);
						if(i > 0)
							DrawLine(METERS_TO_PIXELS(prev.x), METERS_TO_PIXELS(prev.y), METERS_TO_PIXELS(v.x), METERS_TO_PIXELS(v.y), RED);

						prev = v;
					}

					v = b->GetWorldPoint(polygonShape->m_vertices[0]);
					DrawLine(METERS_TO_PIXELS(prev.x), METERS_TO_PIXELS(prev.y), METERS_TO_PIXELS(v.x), METERS_TO_PIXELS(v.y), RED);
				}
				break;

				// Draw chains contour -------------------------------------------
				case b2Shape::e_chain:
				{
					b2ChainShape* shape = (b2ChainShape*)f->GetShape();
					b2Vec2 prev, v;

					for(int32 i = 0; i < shape->m_count; ++i)
					{
						v = b->GetWorldPoint(shape->m_vertices[i]);
						if(i > 0)
							DrawLine(METERS_TO_PIXELS(prev.x), METERS_TO_PIXELS(prev.y), METERS_TO_PIXELS(v.x), METERS_TO_PIXELS(v.y), GREEN);
						prev = v;
					}

					v = b->GetWorldPoint(shape->m_vertices[0]);
					DrawLine(METERS_TO_PIXELS(prev.x), METERS_TO_PIXELS(prev.y), METERS_TO_PIXELS(v.x), METERS_TO_PIXELS(v.y), GREEN);
				}
				break;

				// Draw a single segment(edge) ----------------------------------
				case b2Shape::e_edge:
				{
					b2EdgeShape* shape = (b2EdgeShape*)f->GetShape();
					b2Vec2 v1, v2;

					v1 = b->GetWorldPoint(shape->m_vertex0);
					v1 = b->GetWorldPoint(shape->m_vertex1);
					DrawLine(METERS_TO_PIXELS(v1.x), METERS_TO_PIXELS(v1.y), METERS_TO_PIXELS(v2.x), METERS_TO_PIXELS(v2.y), BLUE);
				}
				break;
			}

			
		}
	}
	
	return UPDATE_CONTINUE;
}


// Called before quitting
bool ModulePhysics::CleanUp()
{
	LOG("Destroying physics world");

	// Delete the whole physics world!
	

	return true;
}

PhysBody* ModulePhysics::CreateCircularBumper(int x, int y, int radius) {
	// Create Bumper BODY at position x,y
	b2BodyDef body;
	body.type = b2_staticBody;
	body.position.Set(PIXEL_TO_METERS(x), PIXEL_TO_METERS(y));

	// Add BODY to the world
	b2Body* b = world->CreateBody(&body);

	// Create Bumper SHAPE
	b2CircleShape bumpershape;
	bumpershape.m_radius = PIXEL_TO_METERS(radius);
	bumpershape.m_p.Set(PIXEL_TO_METERS(0), PIXEL_TO_METERS(0));

	// Create Bumper FIXTURE
	b2FixtureDef fixture;
	fixture.shape = &bumpershape;
	fixture.density = 1.0f;
	fixture.restitution = 1.3f;

	// Add fixture to the Bumper BODY
	b->CreateFixture(&fixture);

	// Create our custom PhysBody class
	PhysBody* pbody = new PhysBody();
	pbody->body = b;
	body.userData.pointer = reinterpret_cast<uintptr_t>(pbody);
	pbody->width = pbody->height = radius;

	// Return our PhysBody class
	return pbody;
}

PhysBody* ModulePhysics::CreateBumper(int x, int y, const int* points, int size)
{
	b2BodyDef body;
	body.type = b2_staticBody;
	body.position.Set(PIXEL_TO_METERS(x), PIXEL_TO_METERS(y));

	b2Body* b = world->CreateBody(&body);

	b2ChainShape bumpershape;
	b2Vec2* p = new b2Vec2[size / 2];

	for (int i = 0; i < size / 2; ++i)
	{
		p[i].x = PIXEL_TO_METERS(points[i * 2 + 0]);
		p[i].y = PIXEL_TO_METERS(points[i * 2 + 1]);
	}

	bumpershape.CreateLoop(p, size / 2);

	b2FixtureDef fixture;
	fixture.shape = &bumpershape;
	fixture.density = 1.0f;
	fixture.restitution = 1.7f;

	b->CreateFixture(&fixture);

	delete p;

	PhysBody* pbody = new PhysBody();
	pbody->body = b;
	body.userData.pointer = reinterpret_cast<uintptr_t>(pbody);
	pbody->width = pbody->height = 0;

	return pbody;
}

PhysBody* ModulePhysics::CreateLeftFlipper(int x, int y, b2RevoluteJoint*& joint)
{
	//we created the flipper rectangle
	PhysBody* Leftflipper = CreateRectangle(x, y, 92, 25);
	
	//we created the static pivot body
	b2BodyDef pivotDef;
	pivotDef.type = b2_staticBody;
	pivotDef.position.Set(PIXEL_TO_METERS(x), PIXEL_TO_METERS(y));
	b2Body* pivot = world->CreateBody(&pivotDef);
	
	//we created the revolute joint that connects the pivot with the flipper
	b2RevoluteJointDef jointDef;
	jointDef.bodyA = pivot;				//this is the static pivot
	jointDef.bodyB = Leftflipper->body;		//this is the dynamic flipper
	
	//we set the local anchor points (where the rotation happens)
	jointDef.localAnchorA.Set(0, 0);
	jointDef.localAnchorB.Set(-PIXEL_TO_METERS(40), 0);
	
	//we enabled the rotation limits of the flilpper
	jointDef.enableLimit = true;			//turn on joint angle limits
	jointDef.lowerAngle = -30 * DEGTORAD;	//this is the lowest angle it can rotate to		DEGTORAD changes from degrees to radiants
	jointDef.upperAngle = 30 * DEGTORAD;	//this is the highest angle it can rotate to
	
	//we enabled the motor that powers the fipper movement
	jointDef.enableMotor = true;			//turn on motor funcionality
	jointDef.motorSpeed = 0.0f;				//we will change it dynamically
	jointDef.maxMotorTorque = 900.0f;		//the strenght of the motor
	
	joint = (b2RevoluteJoint*)world->CreateJoint(&jointDef);

	return Leftflipper;
}

PhysBody* ModulePhysics::CreateRightFlipper(int x, int y, b2RevoluteJoint*& joint)
{
	//we created the flipper rectangle
	PhysBody* Rightflipper = CreateRectangle(x, y, 92, 25);

	//we created the static pivot body
	b2BodyDef pivotDef;
	pivotDef.type = b2_staticBody;
	pivotDef.position.Set(PIXEL_TO_METERS(x), PIXEL_TO_METERS(y));
	b2Body* pivot = world->CreateBody(&pivotDef);

	//we created the revolute joint that connects the pivot with the flipper
	b2RevoluteJointDef jointDef;
	jointDef.bodyA = pivot;				//this is the static pivot
	jointDef.bodyB = Rightflipper->body;		//this is the dynamic flipper

	//we set the local anchor points (where the rotation happens)
	jointDef.localAnchorA.Set(0, 0);
	jointDef.localAnchorB.Set(PIXEL_TO_METERS(40), 0);

	//we enabled the rotation limits of the flilpper
	jointDef.enableLimit = true;			//turn on joint angle limits
	jointDef.lowerAngle = -30 * DEGTORAD;	//this is the lowest angle it can rotate to
	jointDef.upperAngle = 30 * DEGTORAD;	//this is the highest angle it can rotate to

	//we enabled the motor that powers the fipper movement
	jointDef.enableMotor = true;			//turn on motor funcionality
	jointDef.motorSpeed = 0.0f;				//we will change it dynamically
	jointDef.maxMotorTorque = 900.0f;		//the strenght of the motor

	joint = (b2RevoluteJoint*)world->CreateJoint(&jointDef);

	return Rightflipper;
}

PhysBody* ModulePhysics::CreateCircle(int x, int y, int radius)
{
	b2BodyDef body;
	body.type = b2_dynamicBody;
	body.position.Set(PIXEL_TO_METERS(x), PIXEL_TO_METERS(y));

	b2Body* b = world->CreateBody(&body);

	b2CircleShape shape;
	shape.m_radius = PIXEL_TO_METERS(radius);
	b2FixtureDef fixture;
	fixture.shape = &shape;
	fixture.density = 1.0f;
	fixture.friction = 0.3f;
	fixture.restitution = 0.1f;

	b->CreateFixture(&fixture);

	PhysBody* pbody = new PhysBody();
	pbody->body = b;
	body.userData.pointer = reinterpret_cast<uintptr_t>(pbody);
	pbody->width = pbody->height = radius;

	return pbody;
}

PhysBody* ModulePhysics::CreateRectangle(int x, int y, int width, int height)
{
	b2BodyDef body;
	body.type = b2_dynamicBody;
	body.position.Set(PIXEL_TO_METERS(x), PIXEL_TO_METERS(y));

	b2Body* b = world->CreateBody(&body);
	b2PolygonShape box;
	box.SetAsBox(PIXEL_TO_METERS(width) * 0.5f, PIXEL_TO_METERS(height) * 0.5f);

	b2FixtureDef fixture;
	fixture.shape = &box;
	fixture.density = 1.0f;

	b->CreateFixture(&fixture);

	PhysBody* pbody = new PhysBody();
	pbody->body = b;
	body.userData.pointer = reinterpret_cast<uintptr_t>(pbody);
	pbody->width = (int)(width * 0.5f);
	pbody->height = (int)(height * 0.5f);

	return pbody;
}

PhysBody* ModulePhysics::CreateRectangleSensor(int x, int y, int width, int height)
{
	b2BodyDef body;
	body.type = b2_staticBody;
	body.position.Set(PIXEL_TO_METERS(x), PIXEL_TO_METERS(y));

	b2Body* b = world->CreateBody(&body);

	b2PolygonShape box;
	box.SetAsBox(PIXEL_TO_METERS(width) * 0.5f, PIXEL_TO_METERS(height) * 0.5f);

	b2FixtureDef fixture;
	fixture.shape = &box;
	fixture.density = 1.0f;
	fixture.isSensor = true;

	b->CreateFixture(&fixture);

	PhysBody* pbody = new PhysBody();
	pbody->body = b;
	body.userData.pointer = reinterpret_cast<uintptr_t>(pbody);
	pbody->width = width;
	pbody->height = height;

	return pbody;
}

PhysBody* ModulePhysics::CreateCircleSensor(int x, int y, int radius)
{
	b2BodyDef body;
	body.type = b2_staticBody;
	body.position.Set(PIXEL_TO_METERS(x), PIXEL_TO_METERS(y));

	b2Body* b = world->CreateBody(&body);

	b2CircleShape shape;
	shape.m_radius = PIXEL_TO_METERS(radius);

	b2FixtureDef fixture;
	fixture.shape = &shape;
	fixture.density = 1.0f;
	fixture.restitution = 0.1f;
	fixture.isSensor = true;

	b->CreateFixture(&fixture);

	PhysBody* pbody = new PhysBody();
	pbody->body = b;
	body.userData.pointer = reinterpret_cast<uintptr_t>(pbody);
	pbody->width = pbody->height = radius;

	return pbody;
}

PhysBody* ModulePhysics::CreateChain(int x, int y, const int* points, int size)
{
	b2BodyDef body;
	body.type = b2_staticBody;
	body.position.Set(PIXEL_TO_METERS(x), PIXEL_TO_METERS(y));

	b2Body* b = world->CreateBody(&body);

	b2ChainShape shape;
	b2Vec2* p = new b2Vec2[size / 2];

	for (int i = 0; i < size / 2; ++i)
	{
		p[i].x = PIXEL_TO_METERS(points[i * 2 + 0]);
		p[i].y = PIXEL_TO_METERS(points[i * 2 + 1]);
	}

	shape.CreateLoop(p, size / 2);

	b2FixtureDef fixture;
	fixture.shape = &shape;

	b->CreateFixture(&fixture);

	delete p;

	PhysBody* pbody = new PhysBody();
	pbody->body = b;
	body.userData.pointer = reinterpret_cast<uintptr_t>(pbody);
	pbody->width = pbody->height = 0;

	return pbody;
}


PhysBody* ModulePhysics::CreateSpringLauncher(int x, int y, b2Body*& outBase) {
	
	b2BodyDef baseDef;
	baseDef.type = b2_staticBody;
	baseDef.position.Set(PIXEL_TO_METERS(x), PIXEL_TO_METERS(y));
	b2Body* base = world->CreateBody(&baseDef);

	// for taking the base to the game class
	outBase = base;

	//plunger
	b2BodyDef plungerDef;
	plungerDef.type = b2_dynamicBody;
	plungerDef.position.Set(PIXEL_TO_METERS(x), PIXEL_TO_METERS(y + 20));
	b2Body* plunger = world->CreateBody(&plungerDef);

	b2PolygonShape plungerShape;
	plungerShape.SetAsBox(PIXEL_TO_METERS(10), PIXEL_TO_METERS(20));

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &plungerShape;
	fixtureDef.density = 3.0f;
	fixtureDef.friction = 0.5f;
	plunger->CreateFixture(&fixtureDef);

	PhysBody* body = new PhysBody();
	body->body = plunger;
	body->width = 20;
	body->height = 40;
	return body;
}

void ModulePhysics::StartContact(b2Contact* contact)
{
	b2BodyUserData dataA = contact->GetFixtureA()->GetBody()->GetUserData();
	b2BodyUserData dataB = contact->GetFixtureB()->GetBody()->GetUserData();

	PhysBody* physA = (PhysBody*)dataA.pointer;
	PhysBody* physB = (PhysBody*)dataB.pointer;

	if (physA && physA->listener != NULL)
		physA->listener->OnCollision(physA, physB);

	if (physB && physB->listener != NULL)
		physB->listener->OnCollision(physB, physA);
}

void PhysBody::GetPosition(int& x, int& y) const
{
	b2Vec2 pos = body->GetPosition();
	x = METERS_TO_PIXELS(pos.x) - (width);
	y = METERS_TO_PIXELS(pos.y) - (height);
}

void PhysBody::GetPhysicPosition(int& x, int& y) const
{
	b2Vec2 pos = body->GetPosition();
	x = METERS_TO_PIXELS(pos.x);
	y = METERS_TO_PIXELS(pos.y);
}

float PhysBody::GetRotation() const
{
	return body->GetAngle();
}

bool PhysBody::Contains(int x, int y) const
{
	b2Vec2 p(PIXEL_TO_METERS(x), PIXEL_TO_METERS(y));

	const b2Fixture* fixture = body->GetFixtureList();

	while (fixture != NULL)
	{
		if (fixture->GetShape()->TestPoint(body->GetTransform(), p) == true)
			return true;
		fixture = fixture->GetNext();
	}

	return false;
}

int PhysBody::RayCast(int x1, int y1, int x2, int y2, float& normal_x, float& normal_y) const
{
	int ret = -1;

	b2RayCastInput input;
	b2RayCastOutput output;

	input.p1.Set(PIXEL_TO_METERS(x1), PIXEL_TO_METERS(y1));
	input.p2.Set(PIXEL_TO_METERS(x2), PIXEL_TO_METERS(y2));
	input.maxFraction = 1.0f;

	const b2Fixture* fixture = body->GetFixtureList();

	while (fixture != NULL)
	{
		if (fixture->GetShape()->RayCast(&output, input, body->GetTransform(), 0) == true)
		{
			// do we want the normal ?

			float fx = (float)(x2 - x1);
			float fy = (float)(y2 - y1);
			float dist = sqrtf((fx * fx) + (fy * fy));

			normal_x = output.normal.x;
			normal_y = output.normal.y;

			return (int)(output.fraction * dist);
		}
		fixture = fixture->GetNext();
	}

	return ret;
}
