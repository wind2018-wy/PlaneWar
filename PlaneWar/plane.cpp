#include"plane.h"
#include"support.h"
#include"bullet.h"
#include<Windows.h>
#include<iostream>
#include<conio.h>

planeBody::planeBody() { setXY(27, 10); }
planeBody::~planeBody() {}
void planeBody::setXY(int x, int y) {
	this->x = x;
	this->y = y;
}
void plane::move(char ch) {
	switch (ch) {
	case 'w':
		if (y == 1)break;
		clearBody();
		this->y--;
		break;
	case 's':
		if (y == 24)break;
		clearBody();
		this->y++;
		break;
	case 'a':
		if (x == 2)break;
		clearBody();
		this->x--;
		break;
	case 'd':
		if (x == 66)break;
		clearBody();
		this->x++;
		break;
	case 'q':
		if (x < 4)break;
		clearBody();
		this->x -= 2;
		break;
	case 'e':
		if (x > 64)break;
		clearBody();
		this->x += 2;
		break;
	default:
		break;
	}
}
void planeBody::settip(int w, int h) { tipw = w, tiph = h; }
int planeBody::getX() {
	return this->x;
}
int planeBody::getY() {
	return this->y;
}
void pushBodyA(int x, int y) {
	gotoxy(x, y);
	std::cout << "/=\\";
	gotoxy(x - 1, y + 1);
	std::cout << "<<*>>";
	gotoxy(x, y + 2);
	std::cout << "* *";
}
void pushBodyB(int x, int y) {
	gotoxy(x, y);
	std::cout << "* *";
	gotoxy(x - 1, y + 1);
	std::cout << "--|--";
	gotoxy(x + 1, y + 2);
	std::cout << "^";
}
void planeBody::addBody() {
	body[0] = pushBodyA;//自己的飞机
	body[1] = pushBodyB;//这是敌机机身
}
void planeBody::drawBody(int a) {
	void (*okBody)(int,int) = body[a];
	(*okBody)(x, y);
}
void planeBody::clearBody(int bodyType) {
	clearPartialLine(y, x, 3);
	clearPartialLine(y+1, x-1, 5);
	clearPartialLine(y+2, x, 3);
}
plane::plane() {
	speed = 1;
	score = 0;
}
plane::~plane() {}
void plane::act(char ch) {
	move(ch);
}
enemyPlane::enemyPlane() :y(1),speedBin(1) { 
	randomGenerator ranX(2,65);
	x = ranX.generate();
	speed = 1000;
}
void enemyPlane::setDeadLine(int temp) {
	for (int i = 0; i < 10; i++) {
		deadLine[i] = { -1,-1 };
	}
}
void enemyPlane::draw(int j) {
	planeType = j;
	void (*okBody)(int, int) = body[planeType];
	(*okBody)(x, y);
	speedBin++;
	if (speed == speedBin) {
		if (planeType == 1) {
			clearPartialLine(y, x, 3);
			clearPartialLine(y+1, x-1, 5);
			clearPartialLine(y+2, x+1, 1);
		}
		y++;
		void (*okBody)(int, int) = body[planeType];
		(*okBody)(x, y);
		moveContour();
		speedBin = 1;
	}
}
void enemyPlane::getNew(int j) {
	planeType = j;
	setContour();
	randomGenerator ranX(2,65);
	x = ranX.generate();
	y = 1;
}
void enemyPlane::setContour() {
	if (planeType == 1) {
		deadLine[0] = {x-1,y+1};
		deadLine[1] = {x,y+1};
		deadLine[2] = {x+2,y+1};
		deadLine[3] = {x+3,y+1};
		deadLine[4] = {x+1,y+2};
	}
}
void enemyPlane::moveContour() {
	if (planeType == 1) {
		for (int i = 0; i < 5; i++) {
			deadLine[i].y++;
		}
	}
}
bool enemyPlane::checkBomb(axis t) {
	gotoxy(1, 4);
	if (planeType==1) {
		gotoxy(1, 5);
		for (int i = 0; i < 5; i++) {
			if (deadLine[i].x == t.x && deadLine[i].y == t.y)
				return true;
		}
		return false;
	}
}
void enemyPlane::shoot(int type) {
	//if(type=-1)
}
int enemyPlane::gety() {
	return y;
}
int enemyPlane::getx() {
	return x;
}