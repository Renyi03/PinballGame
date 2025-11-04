#pragma once

#include "raylib.h"
#include "ModuleGame.h"
#include "PhysicEntity.h"

class ModulePhysics;
class Module;

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

    Board(ModulePhysics* physics, int _x, int _y, Module* _listener);
    void Update() override;
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
    BoardRightWall(ModulePhysics* physics, int _x, int _y, Module* _listener);
    void Update() override;
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
	BoardTube(ModulePhysics* physics, int _x, int _y, Module* _listener);
	void Update() override;
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
	BoardLeftWall(ModulePhysics* physics, int _x, int _y, Module* _listener);
	void Update() override;
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
	BoardNearFlippersR(ModulePhysics* physics, int _x, int _y, Module* _listener);
	void Update() override;
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
	BoardNearFlippersL(ModulePhysics* physics, int _x, int _y, Module* _listener);
	void Update() override;
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
	BoardTriangleR(ModulePhysics* physics, int _x, int _y, Module* _listener);
	void Update() override;
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
	BoardTriangleL(ModulePhysics* physics, int _x, int _y, Module* _listener);
	void Update() override;
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
	BoardRhombus(ModulePhysics* physics, int _x, int _y, Module* _listener);
	void Update() override;
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
	BoardOvalR(ModulePhysics* physics, int _x, int _y, Module* _listener);
	void Update() override;
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
	BoardOvalL(ModulePhysics* physics, int _x, int _y, Module* _listener);
	void Update() override;
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
	BoardLeftPassage(ModulePhysics* physics, int _x, int _y, Module* _listener);
	void Update() override;
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
	BoardSmallOvalR(ModulePhysics* physics, int _x, int _y, Module* _listener);
	void Update() override;
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
	BoardSmallOvalL(ModulePhysics* physics, int _x, int _y, Module* _listener);
	void Update() override;
private:
	Texture2D texture;

};
