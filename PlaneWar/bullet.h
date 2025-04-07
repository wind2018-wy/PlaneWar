#pragma once
#include"support.h"
#include<vector>
#include<functional>
class bullet {
private:
	int x, y;
	int bulletPower;
	int bulletNum;
protected:
	std::vector<std::function<void()>> bulletType;
public:
	static axis goal;
	static int score;
	bullet(int, int);
	bullet(){}
	int speedBin;
	int bulletSpeed;
	int getx();
	int gety();
	void addBullet();
	void flyBullet(int);
	bool eneFlyBullet(int=0);
	void setNewEneBullet(int x, int y,int=0);
	void setBulletSpeed(int speed);
	void setxy(int, int);
};