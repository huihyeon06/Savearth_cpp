#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib> // rand() �Լ��� ����ϱ� ���� ����
#include <ctime>   // srand() �Լ��� ����ϱ� ���� ����

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
    system("mode con cols = 30 lines = 20 | title ��������");

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
    cout << "               ��----------------------------------��\n";
    cout << "               |                                  |\n"; 
    cout << "               |                                  |\n";
    cout << "               |                                  |\n";
    cout << "               |                                  |\n";
    cout << "               |                                  |\n";
    cout << "               |                                  |\n";
    cout << "               |                                  |\n";
    cout << "               |                                  |\n";
    cout << "               ��__________________________________��\n";

}

void infoDraw() {
    system("cls");
    cout << "\n\n\n\n\n\n\n";
    cout << "               ��----------------------------------��\n";
    cout << "               |                                  |\n";
    cout << "               |              ���۹�              |\n";
    cout << "               |                                  |\n";
    cout << "               |          W,A,S,D : ����Ű        |\n";
    cout << "               |                                  |\n";
    cout << "               |           SPACE : ����           |\n";
    cout << "               |                                  |\n";
    cout << "               |                                  |\n";
    cout << "               ��__________________________________��\n";
    
    
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
                cout << ". "; // "."�� ��ġ�� ���
            }
            else {
                int randNum = rand() % 2;
                if (randNum == 0) {
                    cout << "�� "; 
                }
                else {
                    cout << "�� "; 
                }
            }
        }
        cout << endl;
    }

    while (1) {
        int key = keyControl();
        if (key != -1) {
            // ����Ű�� ���� "."�� ��ġ�� ������Ʈ
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
        //    // �����̽��ٸ� ������ �� �ݺ��� ����
        //    break;
        //}
        system("cls"); // ȭ���� ����� ���� �׸�
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
                        cout << "�� ";
                    }
                    else {
                        cout << "�� ";
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
        case 72: // ȭ��ǥ ��
            return UP;
        case 80: // ȭ��ǥ �Ʒ�
            return DOWN;
        case 75: // ȭ��ǥ ����
            return LEFT;
        case 77: // ȭ��ǥ ������
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

    return -1; // ��ȿ���� ���� �Է��� ��� -1�� ��ȯ
}

void gotoxy(int x, int y) {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos; //COORD: Windows API���� ���Ǵ� ����ü��, 2���� ��ǥ�� ��Ÿ��
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(consoleHandle, pos);
}

int menuDraw() {
    int x = 30;
    int y = 12;
    gotoxy(x - 2, y);
    cout << "> ���ӽ���";
    gotoxy(x, y + 1);
    cout << "���� ���";
    gotoxy(x, y + 2);
    cout << "����";

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
