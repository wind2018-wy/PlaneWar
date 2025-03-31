#include"envir.h"
#include"plane.h"
#include"support.h"
#include"bullet.h"
#include<Windows.h>
#include<conio.h>
#include<thread>
#include<iostream>
#include<vector>
using namespace std;
int main() {
	envir e;
	plane a;
	vector<bullet>bullets(30, bullet(0, 0));
	for (int i = 0; i < 30; i++) {
		bullets[i].addBullet();
	}
	a.addBody();
	while (1) {
		system("cls");
		e.draw();
		a.drawBody(0);

		for (int i = 0; i < 30; i++) {
			if (bullets[i].gety()) {
				bullet& aa = bullets[i];
				gotoxy(aa.getx(), aa.gety());
				aa.flyBullet();
			}
		}
		if (_kbhit()) {
			char ch = _getch();
			a.act(ch);
			if (ch == ' ') {
				gotoxy(1, 1);

				for (int i = 0; i < 30; i++) {
					if (!bullets[i].gety()) {

						gotoxy(1, 2);
						bullet& aa = bullets[i];
						aa.setxy(a.getX(), a.getY());
						break;
					}
					else { continue; }
				}
			}
		}
		Sleep(10);
	}
	gotoxy(0, 29);
	return 0;
}