#include"envir.h"
#include"support.h"
#include<iostream>
using namespace std;
envir::envir(int width, int height) {
	this->width = width;
	this->height = height;
	this->wall = '.';
}
envir::~envir() {}
void envir::draw() {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			if (i == 0 || i == width - 1 || j == 0 || j == height - 1)
			{
				gotoxy(i, j);
				cout << wall;
			}
			else {
				gotoxy(i, j);
				cout << ' ';
			}
		}
	}
}
void envir::setWall(char wall) {
	this->wall = wall;
}
int envir::getHeight() {
	return height;
}