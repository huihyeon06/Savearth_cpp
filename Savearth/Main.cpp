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

const int ROWS = 10;
const int COLS = 10;

class Mini {
private:
    char grid[ROWS][COLS];

    void placeObjects() {
        system("cls");
        srand(static_cast<unsigned int>(time(0)));

        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                if (rand() % 20 == 0) {
                    grid[i][j] = '.';
                }
                else {
                    grid[i][j] = 'ㅁ';
                }
            }
        }
    }

    void printGrid() {
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                std::cout << grid[i][j] << "   ";
            }
            std::cout << std::endl;
        }
    }

public:
    void startMini() {
        placeObjects();
        printGrid();

        Sleep(3000); //30초
        system("cls");

        int guessRow, guessCol;
        std::cout << "위치를 추측해보세요 (행과 열 순서로 입력하세요): ";
        std::cin >> guessRow >> guessCol;

        guessRow--;
        guessCol--;

        if (guessRow < 0 || guessRow >= ROWS || guessCol < 0 || guessCol >= COLS) {
            std::cout << "올바른 범위의 행과 열을 입력하세요." << std::endl;
            return;
        }

        if (grid[guessRow][guessCol] == '.') {
            std::cout << "정답입니다! 해당 위치에 있었습니다." << std::endl;
            Sleep(500); //5초 정지
        }
        else {
            std::cout << "아쉽지만 틀렸습니다." << std::endl;
            Sleep(500); //5초 정지
        }
    }
};

void init() {
    system("mode con cols = 30 lines = 20 | title 게임제목");

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
    cout << "               |            게임방법              |\n";
    cout << "               |                                  |\n";
    cout << "               |            3초안에               |\n";
    cout << "               |    '?' 사이에서 '.'을 찾으시오   |\n";
    cout << "               |                                  |\n";
    cout << "               |   30초안에 몇행 몇열인지 쓰시오  |\n";
    cout << "               |                                  |\n";
    cout << "               |                                  |\n";
    cout << "               └__________________________________┘\n";


    while (1) {
        if (keyControl() == SUBMIT) {
            break;
        }
    }
}


int keyControl() {
    char temp = _getch();

    if (temp == ' ') {
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
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); //콘솔 핸들 가져오기
    COORD pos; //COORD: Windows API에서 사용되는 구조체로, 2차원 좌표를 나타냄
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(consoleHandle, pos);
}

int menuDraw() {
    int x = 24;
    int y = 12;
    gotoxy(x - 2, y);
    cout << "> 게임시작";
    gotoxy(x, y + 1);
    cout << "게임방법";
    gotoxy(x, y + 2);
    cout << "종료";

    while (true) {
        int n = keyControl(); //키보드 이벤트를 키값으로 받아오기
        switch (n) {
        case UP: {
            if (y > 12) {
                gotoxy(x - 2, y); //x-2하는 이유는 ">"를 두칸 이전에 출력하기 위해서이다
                cout << " "; //원래 위치를 지우기
                gotoxy(x - 2, --y); //새로 이동한 위치로 이동
                cout << ">"; //다시 그리기
            }
            break;
        }
        case DOWN: {
            if (y < 14) { //최대 14
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
            Mini mini;
            mini.startMini();
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

