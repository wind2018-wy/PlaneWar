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
	void move(char);
	void addBody();
	void addEnemyBody();
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
public:
	plane();
	~plane();
	void act(char);
	void shoot(int, int);
};
class enemyPlane :public planeBody {
private:

public:

};