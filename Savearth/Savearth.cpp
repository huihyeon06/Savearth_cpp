#include<SFML/Graphics.hpp>
#include<stdlib.h> //srand(), rand()
#include<time.h> //time()
#include<stdio.h>

using namespace sf;

int main() {



    //창 만드는 클래스
    RenderWindow window(VideoMode(1100, 600), "Savearth", Style::Titlebar | Style::Close);

    RectangleShape gaugebar(Vector2f(800, 70));
    gaugebar.setFillColor(Color::Green); //기본 창 색깔

    RectangleShape store;
    store.setFillColor(Color::White);
    Color bluecolor(154, 208, 255);
    store.setOutlineColor(bluecolor);
    store.setPosition(800, 0);
    store.setSize(Vector2f(300 + 2 * 5, 600 + 2 * 5));
    store.setOutlineThickness(4);

    while (window.isOpen()) {
        Event e;
        while (window.pollEvent(e)) {
            //윈도우의 x를 눌렀을 때 창이 닫아지도록
            if (e.type == Event::Closed)
                window.close();
        }

        window.clear(Color::White);//창 색깔 변경
        window.draw(gaugebar);
        window.draw(store);
        window.display(); //프레임 출력
    }
}