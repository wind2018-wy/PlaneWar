#include"support.h"
void gotoxy(int x, int y) {
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void getxy(int& x, int& y) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    if (GetConsoleScreenBufferInfo(hConsole, &csbi)) {
        x = csbi.dwCursorPosition.X; // ��ȡ�к�
        y = csbi.dwCursorPosition.Y; // ��ȡ�к�
    }
}