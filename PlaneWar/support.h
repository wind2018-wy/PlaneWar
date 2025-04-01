#pragma once
#include<Windows.h>
#include<random>
void gotoxy(int x, int y);
void getxy(int& x, int& y);
// 根据当前时间生成种子
class randomGenerator {
public:
    randomGenerator();
    int generate(); // 生成一个随机数
private:
    std::mt19937 gen;
    std::uniform_int_distribution<int> dist;
};
//randomGenerator random_int;cout<<random_int.generate();
char getChar(int x, int y);
struct axis {
    int x, y;
};
void clearPartialLine(int line, int startColumn, int length);
// 清除第 2 行中从第 6 列开始的 5 个字符
//clearPartialLine(2, 6, 5);

void hideConsoleCursor();
void showConsoleCursor();