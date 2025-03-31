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
void planeBody::move(char ch) {
	switch (ch) {
	case 'w':
		this->y--;
		break;
	case 's':
		this->y++;
		break;
	case 'a':
		this->x--;
		break;
	case 'd':
		this->x++;
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
void pushBodyB(int,int);
void planeBody::addBody() {
	body[0] = pushBodyA;
}
void planeBody::drawBody(int a) {
	int x=this->x, y=this->y;
	void (*okBody)(int,int) = body[a];
	(*okBody)(x, y);
}
plane::plane() {
	speed = 1;
	score = 0;
}
plane::~plane() {}
void plane::act(char ch) {
	if (ch == 'a' || ch == 's' || ch == 'd' || ch == 'w')move(ch);
}
void plane::shoot(int x, int y) {
	bullet one(x,y);
	one.addBullet();
	while (one.gety() >= 0) {
		gotoxy(one.getx(), one.gety());
		one.flyBullet();
		Sleep(50);
		system("cls");
	}
}