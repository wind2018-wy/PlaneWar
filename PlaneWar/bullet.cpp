#include"bullet.h"
#include"support.h"
#include<iostream>
bullet::bullet(int x, int y) { this->x = x; this->y = y; }
void pushBulletA();
void pushBulletB();
void bullet::addBullet() {
	bulletType.push_back(pushBulletA);
	bulletType.push_back(pushBulletB);
}
void pushBulletA() {
	std::cout << " ¡ö";
}
void pushBulletB() {
	int x, y;
	getxy(x, y);
	std::cout << "\\+/";
	gotoxy(x + 1, y + 1);
	std::cout << "|";
	gotoxy(x, y);
}
void bullet::flyBullet() {
	bulletType[1]();
	y--;
}
int bullet::getx() { return x; }
int bullet::gety() { return y; }
void bullet::setxy(int x, int y) { this->x = x; this->y = y; }