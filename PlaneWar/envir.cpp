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
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
			{
				gotoxy(j, i);
				cout << wall;
			}
		}
	}
}
void envir::setWall(char wall) {
	this->wall = wall;
}