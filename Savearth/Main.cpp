#include <iostream>
#include <conio.h>
#include <windows.h>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4

using namespace std;

void init();
int keyControl();
void titleDraw();
int menuDraw();
void infoDraw();
void gotoxy(int, int);

int main() {
    init();
    while (1) {
        titleDraw();
        int menuCode = menuDraw();
        if (menuCode == 0) {
            
        }
        else if (menuCode == 1) {
            infoDraw();
        }
        else if (menuCode == 2) {
            return 0;
        }
        system("cls");
    }

    return 0;
}

void init() {
    system("mode con cols = 20 lines = 20 | title 게임제목");

    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO ConsoleCursor;
    ConsoleCursor.bVisible = 0;
    ConsoleCursor.dwSize = 1;
    SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}

void titleDraw() {
    cout << "----------------------------------------\n";
    cout << "-------                         --------\n";
    cout << "-------                         --------\n";
    cout << "-------                         --------\n";
}

void infoDraw() {
    system("cls");
    cout<<"\n\n";
    cout<<"---------------------------------------------------------\n";
    cout<<"                         조작법                            \n";
    cout<<"                    W A S D : 방향키\n";
    cout << "                    SPACE : 선택\n";
    
    
    while (1) {
        if (keyControl() == SUBMIT) {
            break;
        }
    }
}

int keyControl() {
    char temp = _getch();

    if (temp == 'w' || temp == 'W') {
        return UP;
    }
    else if (temp == 'a' || temp == 'A') {
        return LEFT;
    }
    else if (temp == 's' || temp == 'S') {
        return DOWN;
    }
    else if (temp == 'd' || temp == 'D') {
        return RIGHT;
    }
    else if (temp == ' ') {
        return SUBMIT;
    }

    return -1; // 유효하지 않은 입력인 경우 -1을 반환
}

void gotoxy(int x, int y) {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(consoleHandle, pos);
}

int menuDraw() {
    int x = 14;
    int y = 8;
    gotoxy(x - 2, y);
    cout << "> 게임시작";
    gotoxy(x, y + 1);
    cout << "랭킹보기";
    gotoxy(x, y + 2);
    cout << "종료";

    while (true) {
        int n = keyControl();
        switch (n) {
        case UP: {
            if (y > 8) {
                gotoxy(x - 2, y);
                cout << " ";
                gotoxy(x - 2, --y);
                cout << ">";
            }
            break;
        }
        case DOWN: {
            if (y < 10) {
                gotoxy(x - 2, y);
                cout << " ";
                gotoxy(x - 2, ++y);
                cout << ">";
            }
            break;
        }
        case SUBMIT: {
            return y - 8;
        }
        }
    }
}
