#pragma once
#include<Windows.h>
#include<random>
void gotoxy(int x, int y);
void getxy(int& x, int& y);
// ���ݵ�ǰʱ����������
class randomGenerator {
public:
    randomGenerator();
    int generate(); // ����һ�������
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
// ����� 2 ���дӵ� 6 �п�ʼ�� 5 ���ַ�
//clearPartialLine(2, 6, 5);

void hideConsoleCursor();
void showConsoleCursor();