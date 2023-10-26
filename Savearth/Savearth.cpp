#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

int main() {
    RenderWindow window(VideoMode(1100, 600), "Login and Register",Style::Close);
    

    Font font;
    font.loadFromFile(R"(C:\Windows\Fonts\Arial.ttf)");

    Font hfont;
    hfont.loadFromFile(R"(C:\Windows\Fonts\KoPubDotum)");

    Text loginText("Login", font, 36);
    loginText.setFillColor(Color::White);
    loginText.setPosition(350, 250);

    Text registerText("Sign up", font, 36);
    registerText.setFillColor(Color::White);
    registerText.setPosition(330, 320);

    Text idText("아이디", hfont, 20);
    idText.setFillColor(Color::Black);
    idText.setPosition(50, 60);

    Text pwText("비밀번호", hfont, 20);
    pwText.setFillColor(Color::Black);
    pwText.setPosition(50, 80);

    RectangleShape loginButton(Vector2f(120, 50));
    loginButton.setFillColor(Color::Black);
    loginButton.setPosition(330, 240);

    RectangleShape registerButton(Vector2f(180, 50));
    registerButton.setFillColor(Color::Black);
    registerButton.setPosition(310, 310);

    bool loginWindowVisible = false;
    bool registerWindowVisible = false;

    string inputId;
    string inputPassword;

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }

            if (event.type == Event::MouseButtonPressed) {
                Vector2i mousePos = Mouse::getPosition(window);
                if (loginButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    loginWindowVisible = true;
                }
                if (registerButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    registerWindowVisible = true;
                }
            }
            if (event.type == Event::TextEntered && loginWindowVisible) {
                if (event.text.unicode < 128) {
                    if (event.text.unicode == 8) {
                        if (!inputId.empty()) {
                            inputId.pop_back();
                        }
                    }
                    else if (event.text.unicode == 13) {
                        if (inputId == "user" && inputPassword == "password") {
                            // 로그인 후
                            std::cout << "Login Successful!" << std::endl;
                        }
                        else {
                            std::cout << "Login Failed. Invalid credentials." << std::endl;
                        }
                    }
                    else {
                        inputId += static_cast<char>(event.text.unicode);
                    }
                }
            }
        }
        window.clear(Color::White); // 창의 배경색을 흰색으로 설정
        window.draw(loginButton);
        window.draw(registerButton);
        window.draw(loginText);
        window.draw(registerText);
        window.display();

        if (loginWindowVisible) {
            RenderWindow loginWindow(VideoMode(400, 200), "Login Window",Style::Close);
            Text inputIdText(inputId, font, 10);
            inputIdText.setFillColor(Color::Black);
            inputIdText.setPosition(120, 60);
            loginWindow.draw(inputIdText);
            while (loginWindow.isOpen()) {
                Event loginEvent;
                while (loginWindow.pollEvent(loginEvent)) {
                    if (loginEvent.type == Event::Closed) {
                        loginWindow.close();
                        loginWindowVisible = false;
                    }
                }
                loginWindow.clear(Color::White); // 로그인 창의 배경색을 흰색으로 설정
                loginWindow.draw(idText);
                loginWindow.draw(pwText);
                
                loginWindow.display();
            }
        }

        if (registerWindowVisible) {
            RenderWindow registerWindow(VideoMode(400, 200), "Register Window",Style::Close);
            while (registerWindow.isOpen()) {
                Event registerEvent;
                while (registerWindow.pollEvent(registerEvent)) {
                    if (registerEvent.type == Event::Closed) {
                        registerWindow.close();
                        registerWindowVisible = false;
                    }
                }
                registerWindow.clear(Color::White); // 회원가입 창의 배경색을 흰색으로 설정
                registerWindow.draw(idText);
                registerWindow.draw(pwText);
                // 회원가입 창의 내용을 여기에 추가할 수 있습니다.
                registerWindow.display();
            }
        }
    }

    return 0;
}
//#include<SFML/Graphics.hpp>
//#include<stdlib.h> //srand(), rand()
//#include<time.h> //time()
//#include<stdio.h>
//
//using namespace sf;
//
//int main() {
//
//
//
//    //창 만드는 클래스
//    RenderWindow window(VideoMode(1100, 600), "Savearth", Style::Titlebar | Style::Close);
//    RenderWindow swindow(VideoMode(1100, 600), "second Savearth", Style::None);
//
//    //버튼
//    RectangleShape button(Vector2f(100.f, 40.f));
//    button.setPosition(50.f, 50.f);
//    button.setFillColor(Color::Blue);
//
//
//    //RectangleShape gaugebar(Vector2f(800, 70));
//    //gaugebar.setFillColor(Color::Green); //기본 창 색깔
//
//    /*RectangleShape store;
//    store.setFillColor(Color::White);
//    Color bluecolor(154, 208, 255);
//    store.setOutlineColor(bluecolor);
//    store.setPosition(800, 0);
//    store.setSize(Vector2f(300 + 2 * 5, 600 + 2 * 5));
//    store.setOutlineThickness(4);*/
//
//    while (window.isOpen() || swindow.isOpen()) {
//        Event e;
//        while (window.pollEvent(e)) {
//            //윈도우의 x를 눌렀을 때 창이 닫아지도록
//            if (e.type == Event::Closed) {
//                window.close();
//            }
//            else if (e.type == Event::MouseButtonPressed)
//            {
//                if (e.mouseButton.button == Mouse::Left)
//                {
//                    Vector2f mousePos = window.mapPixelToCoords(Vector2i(e.mouseButton.x, e.mouseButton.y));
//                    if (button.getGlobalBounds().contains(mousePos))
//                    {
//                        swindow.setVisible(true);
//                        window.setVisible(false);
//                    }
//                }
//            }
//        }
//        Event sevent;
//        while (swindow.pollEvent(sevent))
//        {
//            if (sevent.type == Event::Closed)
//                swindow.close();
//            else if (sevent.type == Event::MouseButtonPressed)
//            {
//                if (sevent.mouseButton.button == Mouse::Left)
//                {
//                    Vector2f mousePos = swindow.mapPixelToCoords(Vector2i(sevent.mouseButton.x, sevent.mouseButton.y));
//                    if (button.getGlobalBounds().contains(mousePos))
//                    {
//                        window.setVisible(!window.isOpen());
//                    }
//                }
//            }
//        }
//
//        window.clear(Color::White);//창 색깔 변경
//        /*window.draw(gaugebar);
//        window.draw(store);*/
//        window.draw(button);
//        window.display(); //프레임 출력
//    }
//}
