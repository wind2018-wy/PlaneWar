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
	std::cout << "请输入同一时间内出现敌机数量";
	int eneC; std::cin >> eneC;
	gotoxy(1, 2);
	std::cout << "请输入敌机的总数";
	int totalEneC; std::cin >> totalEneC;
	if (eneC > totalEneC) {
		gotoxy(1, 3);
		std::cout << "敌机数量不合法";
		return 0;
	}
	int eneCount = 0;
	system("cls");
	e.draw();
	bullet::score -= eneC;
	std::vector<enemyPlane>enemies(eneC);
	for (int i = 0; i < eneC; i++) {
		enemies[i].addBody();
		enemies[i].setDeadLine(-1);
		eneCount--;
	}
	

	while (1) {

		//查看每颗子弹的状态并清理
		for (int i = 0; i < 30; i++) {
			if (bullets[i].gety() != 0) {
				bullet& aa = bullets[i];
				gotoxy(aa.getx(), aa.gety());
				int tx = aa.getx(), ty = aa.gety();
				aa.flyBullet(1);
			}
		}
		//查看敌机的状态
		for (int i = 0; i < eneC; i++) {
			int eneBodyType = 1;
			if (enemies[i].gety() >= e.getHeight() - 4) {
				//敌机到底清一下
				if (eneBodyType == 1) {
					int ty = enemies[i].gety(), tx = enemies[i].getx();
					clearPartialLine(ty, tx, 3);
					clearPartialLine(ty + 1, tx - 1, 5);
					clearPartialLine(ty + 2, tx + 1, 1);
				}
				enemies[i].getNew(eneBodyType);
				enemies[i].setContour();
				eneCount++;
			}
			else {
				if (enemies[i].checkBomb(bullet::goal)) {
					//敌机爆炸清一下
					if (eneBodyType == 1) {
						int ty = enemies[i].gety(), tx = enemies[i].getx();
						clearPartialLine(ty, tx, 3);
						clearPartialLine(ty + 1, tx - 1, 5);
						clearPartialLine(ty + 2, tx + 1, 1);
					}
					enemies[i].getNew(eneBodyType);
					enemies[i].setContour();
					bullet::score++;
					eneCount++;
				}
			}
			//其他位置清一下
			enemies[i].draw(eneBodyType);
			if (enemies[i].eneBullet.eneFlyBullet()/*这里写敌机子弹型号，但还没有试过*/) {
				enemies[i].eneBullet.setNewEneBullet(enemies[i].getx(), enemies[i].gety(), 0);
				//enemies[i].eneBullet.setNewEneBullet(enemies[i].getx(), enemies[i].gety(), 1);

			}
			for (int w = 0; w < 3; w++) {
				if (enemies[i].eneBullet.getx() + 1 == a.theAxis[w].x && enemies[i].eneBullet.gety() == a.theAxis[w].y) {
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
		if (eneCount == totalEneC) {
			break;
		}
	}
	for (int i = 1; i < 27; i++) {
		clearPartialLine(i, 1, 67);
	}
	for (int i = 28; i < 30; i++) {
		clearPartialLine(i, 1, 67);
	}
	gotoxy(1, 1);
	std::cout << "游戏结束，您的得分是：" << bullet::score
		<< std::endl << "·请按任意键退出";
	gotoxy(0, 27);
	return 0;
}