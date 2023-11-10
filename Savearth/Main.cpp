#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib> // rand() 함수를 사용하기 위해 포함
#include <ctime>   // srand() 함수를 사용하기 위해 포함

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4
#define INFO_STATE 5

using namespace std;

void init();
int keyControl();
void titleDraw();
int menuDraw();
void infoDraw();
void gotoxy(int, int);

int currentState = 0;
int dotX = 10;
int dotY = 5;


void init() {
    system("mode con cols = 30 lines = 20 | title 게임제목");

    COORD bufferSize = { 50, 20 };
    SMALL_RECT windowSize = { 0, 0, 79, 29 }; 

    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleScreenBufferSize(console, bufferSize);
    SetConsoleWindowInfo(console, TRUE, &windowSize);

    /*HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO ConsoleCursor;
    ConsoleCursor.bVisible = 0;
    ConsoleCursor.dwSize = 1;
    SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);*/
}

void titleDraw() {
    cout << "\n\n\n\n\n\n\n";
    cout << "               ┌----------------------------------┐\n";
    cout << "               |                                  |\n"; 
    cout << "               |                                  |\n";
    cout << "               |                                  |\n";
    cout << "               |                                  |\n";
    cout << "               |                                  |\n";
    cout << "               |                                  |\n";
    cout << "               |                                  |\n";
    cout << "               |                                  |\n";
    cout << "               └__________________________________┘\n";

}

void infoDraw() {
    system("cls");
    cout << "\n\n\n\n\n\n\n";
    cout << "               ┌----------------------------------┐\n";
    cout << "               |                                  |\n";
    cout << "               |              조작법              |\n";
    cout << "               |                                  |\n";
    cout << "               |          W,A,S,D : 방향키        |\n";
    cout << "               |                                  |\n";
    cout << "               |           SPACE : 선택           |\n";
    cout << "               |                                  |\n";
    cout << "               |                                  |\n";
    cout << "               └__________________________________┘\n";
    
    
    while (1) {
        if (keyControl() == SUBMIT) {
            break;
        }
    }
}

void startDraw() {
    system("cls");

    cout << "\n\n\n\n\n\n\n";
    for (int i = 0; i < 10; ++i) {
        //cout << "                   ";
        for (int j = 0; j < 10; ++j) {
            if (i == dotY && j == dotX) {
                cout << ". "; // "."의 위치에 출력
            }
            else {
                int randNum = rand() % 2;
                if (randNum == 0) {
                    cout << "□ "; 
                }
                else {
                    cout << "■ "; 
                }
            }
        }
        cout << endl;
    }

    while (1) {
        int key = keyControl();
        if (key != -1) {
            // 방향키에 따라 "."의 위치를 업데이트
            if (key == UP && dotY > 0) {
                dotY--;
            }
            else if (key == DOWN && dotY < 9) {
                dotY++;
            }
            else if (key == LEFT && dotX > 0) {
                dotX--;
            }
            else if (key == RIGHT && dotX < 9) {
                dotX++;
            }
        }
        //else if (key == SUBMIT) {
        //    // 스페이스바를 눌렀을 때 반복문 종료
        //    break;
        //}
        system("cls"); // 화면을 지우고 새로 그림
        cout << "\n\n\n\n\n\n\n";
        for (int i = 0; i < 10; ++i) {
            //cout << "                   ";
            for (int j = 0; j < 10; ++j) {
                if (i == dotY && j == dotX) {
                    cout << ". ";
                }
                else {
                    int randNum = rand() % 2;
                    if (randNum == 0) {
                        cout << "□ ";
                    }
                    else {
                        cout << "■ ";
                    }
                }
            }
            cout << endl;
        }
    }
}

int keyControl() {
    char temp = _getch();

    if (temp == 224) {
        temp = _getch();
        switch (temp) {
        case 72: // 화살표 위
            return UP;
        case 80: // 화살표 아래
            return DOWN;
        case 75: // 화살표 왼쪽
            return LEFT;
        case 77: // 화살표 오른쪽
            return RIGHT;
        }
    }
    else if (temp == ' ') {
        return SUBMIT;
    }
    else if (temp == 'w' || temp == 'W') {
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

    return -1; // 유효하지 않은 입력인 경우 -1을 반환
}

void gotoxy(int x, int y) {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos; //COORD: Windows API에서 사용되는 구조체로, 2차원 좌표를 나타냄
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(consoleHandle, pos);
}

int menuDraw() {
    int x = 30;
    int y = 12;
    gotoxy(x - 2, y);
    cout << "> 게임시작";
    gotoxy(x, y + 1);
    cout << "게임 방법";
    gotoxy(x, y + 2);
    cout << "종료";

    while (true) {
        int n = keyControl();
        switch (n) {
        case UP: {
            if (y > 12) {
                gotoxy(x - 2, y);
                cout << " ";
                gotoxy(x - 2, --y);
                cout << ">";
            }
            break;
        }
        case DOWN: {
            if (y < 14) {
                gotoxy(x - 2, y);
                cout << " ";
                gotoxy(x - 2, ++y);
                cout << ">";
            }
            break;
        }
        case SUBMIT: {
            if (y - 12 == INFO_STATE) {
                currentState = INFO_STATE;
                return INFO_STATE;
            }
            return y - 12;
        }
        }
    }
}

int main() {

    init();
    while (1) {
        titleDraw();
        int menuCode = menuDraw();
        if (menuCode == 0) {
            startDraw();
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
