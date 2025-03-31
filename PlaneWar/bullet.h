#pragma once
#include<vector>
#include<functional>
class bullet {
private:
	int x, y;
	int bulletSpeed;
	int bulletPower;
	int bulletNum;
protected:
	std::vector<std::function<void()>> bulletType;
public:
	bullet(int, int);
	int getx();
	int gety();
	void addBullet();
	void flyBullet();
	void setBulletSpeed(int speed);
	void setxy(int, int);
};