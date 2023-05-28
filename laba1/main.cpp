/*
Создайте класс AnimatedText, который позволит создавать анимированный вывод текста. 
Класс должен содержать строку text и переменную duration, 
которая указывает время вывода всей строки на экран.
*/


#include <iostream>
#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>

class AnimatedText {
private:
    std::string _text;
    double _duration;
    double _start_time = 0;
    std::string _curOut;
    int _curPos = 1;
public:
    AnimatedText(const std::string& newText, int newDuration) {
        _text = newText;
        _duration = newDuration;
        _curOut += _text[0];
    }
    std::string value(double sec) {
        if ((sec - _start_time) >= (_duration / _text.size()) && _curPos < _text.size()) {
            _start_time = sec;
            _curOut += _text[_curPos++];
        }
        return _curOut;
    }
};

int main() {
    AnimatedText sample("Hello, world!", 13);


    sf::RenderWindow window(sf::VideoMode(1000, 500), "laba1");
    sf::Text text;
    sf::Font font;
    font.loadFromFile("bold.ttf");
    text.setFont(font);
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(36);
    text.setPosition(100, 100);
    std::chrono::time_point<std::chrono::system_clock> startTime = std::chrono::system_clock::now();
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        std::chrono::time_point<std::chrono::system_clock> curTime = std::chrono::system_clock::now();
        double sec = std::chrono::duration_cast<std::chrono::seconds>(curTime - startTime).count();
        text.setString(sample.value(sec));
        window.clear();
        window.draw(text);
        window.display();
    }
}