#pragma once
class planeBody {
private:
	int x, y;
	int width, height;
	int speed;
	int life;
	int score;
	int bulletType;
	int bulletSpeed;
	int bulletPower;
	int bulletNum;
public:
	planeBody();
	~planeBody();
	void draw();
	void move(int x, int y);
	void setPos(int x, int y);
	void setBulletSpeed(int speed);
	int getX();
	int getY();
};