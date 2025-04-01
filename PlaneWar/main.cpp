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
	hideConsoleCursor();
	envir e;
	plane a;
	e.draw();
	vector<bullet>bullets(30, bullet(0, 0));
	for (int i = 0; i < 30; i++) {
		bullets[i].addBullet();
	}
	gotoxy(1, 1);
	a.addBody();
	cout << "请输入同一时间内出现敌机数量";
	int eneC; cin >> eneC;
	bullet::score -= eneC;
	vector<enemyPlane>enemies(eneC);
	for (int i = 0; i < eneC; i++) {
		enemies[i].addBody();
		enemies[i].setDeadLine(-1);
	}
	
	while (1) {
		for (int i = 2; i < 28; i++) {
			clearPartialLine(i, 2, 68);
		}
		//system("cls");
		//e.draw();
		a.drawBody(0);
		int bulletsCount = 0;

		for (int i = 0; i < eneC; i++) {
			int j = 1;
			if (enemies[i].gety() >= e.getHeight()-3) {
				enemies[i].getNew(j);
				enemies[i].setContour();
			}
			else {
				if (enemies[i].checkBomb(bullet::goal)) {
					enemies[i].getNew(j);
					enemies[i].setContour();
					bullet::score++;
				}
			}
			enemies[i].draw(j);
		}

		for (int i = 0; i < 30; i++) {
			if (bullets[i].gety()!=0) {
				bullet& aa = bullets[i];
				gotoxy(aa.getx(), aa.gety());
				aa.flyBullet(1);
				bulletsCount++;
			}
		}
		gotoxy(0, 29);
		cout << "the count of  bullets is " << bulletsCount;
		cout << " score: " << bullet::score;
		if (_kbhit()) {
			char ch = _getch();
			a.act(ch);

			if (ch == ' ') {
				for (int i = 0; i < 30; i++) {
					if (!bullets[i].gety()) {

						bullet& aa = bullets[i];
						aa.setxy(a.getX(), a.getY());
						break;
					}
					else { continue; }
				}
			}
		}
	}
	gotoxy(0, 29);
	return 0;
}