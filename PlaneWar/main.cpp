#include"envir.h"
#include"plane.h"
#include"support.h"
#include"bullet.h"
#include<Windows.h>
#include<conio.h>
#include<thread>
#include<iostream>
#include<vector>
int main() {
	hideConsoleCursor();
	envir e;
	plane a;
	e.draw();
	std::vector<bullet>bullets(30, bullet(0, 0));
	for (int i = 0; i < 30; i++) {
		bullets[i].addBullet();
	}
	gotoxy(1, 1);
	a.addBody();
	std::cout << "������ͬһʱ���ڳ��ֵл�����";
	int eneC; std::cin >> eneC;
	system("cls");
	e.draw();
	bullet::score -= eneC;
	std::vector<enemyPlane>enemies(eneC);
	for (int i = 0; i < eneC; i++) {
		enemies[i].addBody();
		enemies[i].setDeadLine(-1);
	}
	

	while (1) {

		//�鿴ÿ���ӵ���״̬������
		for (int i = 0; i < 30; i++) {
			if (bullets[i].gety() != 0) {
				bullet& aa = bullets[i];
				gotoxy(aa.getx(), aa.gety());
				int tx = aa.getx(), ty = aa.gety();
				aa.flyBullet(1);
			}
		}
		//�鿴�л���״̬
		for (int i = 0; i < eneC; i++) {
			int eneBodyType = 1;
			if (enemies[i].gety() >= e.getHeight() - 4) {
				//�л�������һ��
				if (eneBodyType == 1) {
					int ty = enemies[i].gety(), tx = enemies[i].getx();
					clearPartialLine(ty, tx, 3);
					clearPartialLine(ty + 1, tx - 1, 5);
					clearPartialLine(ty + 2, tx + 1, 1);
				}
				enemies[i].getNew(eneBodyType);
				enemies[i].setContour();
			}
			else {
				if (enemies[i].checkBomb(bullet::goal)) {
					//�л���ը��һ��
					if (eneBodyType == 1) {
						int ty = enemies[i].gety(), tx = enemies[i].getx();
						clearPartialLine(ty, tx, 3);
						clearPartialLine(ty + 1, tx - 1, 5);
						clearPartialLine(ty + 2, tx + 1, 1);
					}
					enemies[i].getNew(eneBodyType);
					enemies[i].setContour();
					bullet::score++;
				}
			}
			//����λ����һ��
			enemies[i].draw(eneBodyType);
			if (enemies[i].eneBullet.eneFlyBullet()/*����д�л��ӵ��ͺţ�����û���Թ�*/) {
				enemies[i].eneBullet.setNewEneBullet(enemies[i].getx(), enemies[i].gety(), 0);
				//enemies[i].eneBullet.setNewEneBullet(enemies[i].getx(), enemies[i].gety(), 1);
				
			}
			for (int w = 0; w < 3; w++) {
				if (enemies[i].eneBullet.getx()+1 == a.theAxis[w].x && enemies[i].eneBullet.gety() == a.theAxis[w].y) {
					bullet::score--;
					enemies[i].eneBullet.setNewEneBullet(enemies[i].getx(), enemies[i].gety(), 0);
					break;
				}
			}
		}
		/*
		for (int i = 2; i < 28; i++) {
			if(lineToClear[i-2])
			clearPartialLine(i, 2, 68);
		}
		*/
		//system("cls");
		//e.draw();
		a.drawBody(0);
		int bulletsCount = 0;

		
		gotoxy(0, 29);
		std::cout << " score: " << bullet::score;
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