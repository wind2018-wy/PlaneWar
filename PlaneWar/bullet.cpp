#include"bullet.h"
#include"support.h"
#include<iostream>
bullet::bullet(int x, int y) { this->x = x; this->y = y; bulletSpeed = 10; speedBin = bulletSpeed; }
axis bullet::goal = { -1,-1 };
int bullet::score = 0;
void pushBulletA();
void pushBulletB();
void bullet::addBullet() {
	bulletType.push_back(pushBulletA);
	bulletType.push_back(pushBulletB);
}
void pushBulletA() {
	std::cout << " ��";
}
void pushBulletB() {
	int x, y;
	getxy(x, y);
	std::cout << "\\+/";
	gotoxy(x + 1, y + 1);
	std::cout << "|";
	gotoxy(x, y);
}
void bullet::flyBullet(int a) {
	bulletNum = a;
	if (speedBin >= bulletSpeed) {
		y--;
		speedBin = 1;
	}
	speedBin++;
	bulletType[a]();

	if (a == 0||a==1) {
		if (getChar(x + 1, y) != ' ') {
			goal = { x + 1,y };
			if (getChar(x + 1, y) == '^' || getChar(x + 1, y) == '-') {
				y = 0;
			}
		}
	}
}
int bullet::getx() { return x; }
int bullet::gety() { return y; }
void bullet::setxy(int x, int y) { this->x = x; this->y = y; }