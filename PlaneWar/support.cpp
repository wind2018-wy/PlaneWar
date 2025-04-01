#include"support.h"
#include<iostream>
#include<chrono>
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
        x = csbi.dwCursorPosition.X; // 获取列号
        y = csbi.dwCursorPosition.Y; // 获取行号
    }
}
randomGenerator::randomGenerator()
    : gen(std::chrono::system_clock::now().time_since_epoch().count()),
    dist(2, 65) {
}
int randomGenerator::generate() {
    return dist(gen);
}char getChar(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // 获取控制台句柄
    if (hConsole == INVALID_HANDLE_VALUE) {
        std::cerr << "Failed to get console handle!" << std::endl;
        return '\0';
    }

    COORD coord = { static_cast<SHORT>(x), static_cast<SHORT>(y) }; // 设置坐标
    DWORD numCharsRead = 0;
    char buffer = '\0';

    // 读取指定位置的字符
    if (!ReadConsoleOutputCharacterA(hConsole, &buffer, 1, coord, &numCharsRead)) {
        std::cerr << "Failed to read character from console!" << std::endl;
        return '\0';
    }

    return buffer; // 返回读取到的字符
}
void clearPartialLine(int line, int startColumn, int length) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // 获取控制台句柄
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi); // 获取当前控制台信息

    COORD cursorPosition;
    DWORD written;

    cursorPosition.X = startColumn - 1; // 光标移动到起始列（从 0 开始）
    cursorPosition.Y = line - 1;       // 光标移动到指定行（从 0 开始）
    SetConsoleCursorPosition(hConsole, cursorPosition); // 设置光标位置

    FillConsoleOutputCharacter(hConsole, ' ', length, cursorPosition, &written); // 填充空格
    FillConsoleOutputAttribute(hConsole, csbi.wAttributes, length, cursorPosition, &written); // 恢复颜色
}
void hideConsoleCursor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // 获取控制台句柄
    CONSOLE_CURSOR_INFO cursorInfo;

    // 获取当前光标信息
    GetConsoleCursorInfo(hConsole, &cursorInfo);

    // 修改光标信息以隐藏光标
    cursorInfo.bVisible = FALSE; // 设置为不可见
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

void showConsoleCursor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // 获取控制台句柄
    CONSOLE_CURSOR_INFO cursorInfo;

    // 获取当前光标信息
    GetConsoleCursorInfo(hConsole, &cursorInfo);

    // 修改光标信息以显示光标
    cursorInfo.bVisible = TRUE; // 设置为可见
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}