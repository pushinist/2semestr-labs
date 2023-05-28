/*
Реализуйте класс Complex для работы с комплексными числами. Он должен включать:

1. Базовый конструктор

2. Конструктор копирования

3. Оператор присваивания копированием

4. Деструктор

5. Операторы += и +, *= и *

6. Оператор ++ префиксный и постфиксный (увеличение действительной части числа на 1)

7. Операторы ввода и вывода
*/


#include <iostream>

class Complex
{
private:
    double _a = 0;
    double _b = 0;
public:
    Complex() = default;
    // Базовый конструктор
    Complex(double a, double b) : _a(a), _b(b) {}

    Complex(const Complex& number) : Complex(number._a, number._b) {}
    //Оператор присваивания
    Complex& operator = (const Complex& number)
    {
        this->_a = number._a;
        this->_b = number._b;
        return *this;
    }
    // Оператор +=
    Complex& operator += (const Complex& number)
    {
        this->_a += number._a;
        this->_b += number._b;
        return *this;
    }
    // Оператор +
    Complex operator + (const Complex& number)
    {
        Complex temp;
        temp = *this;
        temp += number;
        return temp;
    }
    // Оператор умножения на комплексное число
    Complex& operator *= (const Complex& number)
    {
        auto temp = *this;
        this->_a = temp._a * number._a - temp._b * number._b;
        this->_b = temp._a * number._b + temp._b * number._a;
        return *this;
    }
    // Оператор умножения на действиетельное число
    Complex& operator *= (double c)
    {
        this->_a *= c;
        this->_b *= c;
        return *this;
    }
    // Оператор *
    Complex operator * (const Complex& number)
    {
        Complex temp = *this;
        temp *= number;
        return temp;
    }
    // Оператор 
    Complex& operator ++()
    {
        this->_a += 1;
        return *this;
    }

    Complex operator ++(int i)
    {
        Complex tmp = *this;
        this->_a += 1;
        return tmp;
    }

    friend std::ostream& operator << (std::ostream& output, Complex& s);

    friend std::istream& operator >> (std::istream& input, Complex& s);

    void Print()
    {
        std::cout << "(" << _a << "," << _b << ")";
    }

    ~Complex() = default;
};

std::ostream& operator << (std::ostream& output, Complex& num)
{
    output << "(" << num._a << "," << num._b << ")";
    return output;
}
std::istream& operator >> (std::istream& input, Complex& num)
{
    input >> num._a >> num._b;
    return input;
}

int main()
{
    Complex a;
    Complex b(3, -1);
    Complex c(b);
    c += b;
    c.Print();
    a = c + b;
    a.Print();
    c *= b;
    std::cout << c;
    Complex d;
    std::cin >> d;
    std::cout << d;
}
