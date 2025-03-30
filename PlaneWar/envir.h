#pragma once
class envir {
private:
	char wall;
	int width, height;
public:
	envir(int=70,int=28);
	~envir();
	void draw();
	void setWall(char wall);

	char getWall();
	int getWidth();
	int getHeight();
};