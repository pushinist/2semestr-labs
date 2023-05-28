//Разработайте класс для логирования работы программы.


/*
Предусмотрите следующие возможности:

1. Вывод в консоль и в файл

2. Возможность отключения части логов

3. Логи разного уровня (Info, Debug, Error и т.п.)

4. Вывод времени записи лога

Оформите класс таким образом, чтобы его потом можно было использовать в других проектах 
(пространство имен, разбиение на файлы).
*/


#include <iostream>
#include "Log.hpp"

int main()
{
    std::cout << "Hello World!\n";
    pushLogger::Log::Log(pushLogger::LogLevel::DEBUG);
    pushLogger::Log::Report(pushLogger::LogType::INFO, "test");
    pushLogger::Log::Report(pushLogger::LogType::DEBUG, "test");
    pushLogger::Log::Report(pushLogger::LogType::ERROR, "test");

}