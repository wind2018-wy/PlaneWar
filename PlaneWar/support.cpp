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
        x = csbi.dwCursorPosition.X; // ��ȡ�к�
        y = csbi.dwCursorPosition.Y; // ��ȡ�к�
    }
}
randomGenerator::randomGenerator()
    : gen(std::chrono::system_clock::now().time_since_epoch().count()),
    dist(2, 65) {
}
int randomGenerator::generate() {
    return dist(gen);
}char getChar(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // ��ȡ����̨���
    if (hConsole == INVALID_HANDLE_VALUE) {
        std::cerr << "Failed to get console handle!" << std::endl;
        return '\0';
    }

    COORD coord = { static_cast<SHORT>(x), static_cast<SHORT>(y) }; // ��������
    DWORD numCharsRead = 0;
    char buffer = '\0';

    // ��ȡָ��λ�õ��ַ�
    if (!ReadConsoleOutputCharacterA(hConsole, &buffer, 1, coord, &numCharsRead)) {
        std::cerr << "Failed to read character from console!" << std::endl;
        return '\0';
    }

    return buffer; // ���ض�ȡ�����ַ�
}
void clearPartialLine(int line, int startColumn, int length) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // ��ȡ����̨���
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi); // ��ȡ��ǰ����̨��Ϣ

    COORD cursorPosition;
    DWORD written;

    cursorPosition.X = startColumn - 1; // ����ƶ�����ʼ�У��� 0 ��ʼ��
    cursorPosition.Y = line - 1;       // ����ƶ���ָ���У��� 0 ��ʼ��
    SetConsoleCursorPosition(hConsole, cursorPosition); // ���ù��λ��

    FillConsoleOutputCharacter(hConsole, ' ', length, cursorPosition, &written); // ���ո�
    FillConsoleOutputAttribute(hConsole, csbi.wAttributes, length, cursorPosition, &written); // �ָ���ɫ
}
void hideConsoleCursor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // ��ȡ����̨���
    CONSOLE_CURSOR_INFO cursorInfo;

    // ��ȡ��ǰ�����Ϣ
    GetConsoleCursorInfo(hConsole, &cursorInfo);

    // �޸Ĺ����Ϣ�����ع��
    cursorInfo.bVisible = FALSE; // ����Ϊ���ɼ�
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

void showConsoleCursor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // ��ȡ����̨���
    CONSOLE_CURSOR_INFO cursorInfo;

    // ��ȡ��ǰ�����Ϣ
    GetConsoleCursorInfo(hConsole, &cursorInfo);

    // �޸Ĺ����Ϣ����ʾ���
    cursorInfo.bVisible = TRUE; // ����Ϊ�ɼ�
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}