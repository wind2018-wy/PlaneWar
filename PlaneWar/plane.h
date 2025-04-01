#pragma once
#include"bullet.h"
#include<vector>
#include<functional>
class planeBody {
private:
	int width, height;
	int tipw, tiph;
	int life;
public:
	void(* body[5])(int,int) = { nullptr };
	int x, y;
	planeBody();
	~planeBody();
	void addBody();
	void setXY(int x, int y);
	void settip(int = 1, int = 0);
	void drawBody(int);
	void setPos(int x, int y);

	int getX();
	int getY();
};
class plane :public planeBody{
private:
	int speed;
	int score;
	int planeType;
public:
	plane();
	~plane();
	void move(char);
	void act(char);
	void shoot(int, int);
};
class enemyPlane :public planeBody {
private:
	axis deadLine[10]{ -1,-1 };
	int x, y;
	int eneSpeed;
	int planeType;
	int speed;
	int speedBin;
public:
	void setDeadLine(int);
	enemyPlane();
	~enemyPlane(){}
	void setxy(int, int);
	int getx();
	int gety();
	void draw(int);
	void getNew(int);
	void setContour();
	void moveContour();
	bool checkBomb(axis);
};