#pragma once
class planeBody {
public:
	planeBody();
	~planeBody();
	void draw();
	void move(int x, int y);
	void setPos(int x, int y);
	int getX();
	int getY();
};