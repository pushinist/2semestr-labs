/*
–еализуйте класс String дл€ работы со строками.

” вас должны быть реализованы:

1. Ѕазовый конструктор

2.  онструктор копировани€ (правило 3-х)

3. ќператор присваивани€ копированием (правило 3-х)

4. ƒеструктор (правило 3-х)

5. ќператоры + и +=

6. ќператор [] Ц чтение и изменение элемента

7. ќператоры <, >, ==

8. ќператоры ввода и вывода в поток

9. ћетод find Ц поиск первого вхождени€ символа в строку слева

10. ћетод length Ц длина строки

11. ћетод c_str Ц получить массив char

12. ћетод at дл€ получени€ доступа (чтение и изменение) к элементу строки с проверкой на выход за пределы строки
*/


#include <iostream>

    class String
    {
    private:
        size_t i_size;
        char* i_str = nullptr;


    public:
        String() = default;
        // онструктор копировани€ (правило 3-х)
        String(const char* str) : i_size(strlen(str)), i_str(new char[i_size + 1]) 
        {
            std::copy(str, str + i_size + 1, i_str);
        }

        String(String& old) : String(old.i_str)
        {

        }
        //ќператор присваивани€ копированием (правило 3-х)
        String& operator = (const String& other)
        {
            if (i_str != nullptr)
                delete[] i_str;
            i_size = other.i_size;
            i_str = new char[i_size + 1];
            std::copy(other.i_str, other.i_str + i_size + 1, this->i_str);
            return *this;
        }
        //ќператор +=
        String& operator += (const String& term)
        {
            i_size = this->i_size + term.i_size;
            auto temp = i_str;
            i_str = new char[i_size + 1];
            std::copy(temp, temp + strlen(temp), i_str);
            std::copy(term.i_str, term.i_str + term.i_size + 1, i_str + strlen(temp));
            delete[] temp;
            return *this;
        }
        //ќператор +
        String operator + (const String& term)
        {
            String tmp;
            tmp = *this;
            tmp += term;
            return tmp;
        }
        // ќператор ==
        bool operator == (const String& str2)
        {
            return std::strcmp(this->i_str, str2.i_str) == 0;
        }
        // ќператор >
        bool operator > (const String& str2)
        {
            return std::strcmp(this->i_str, str2.i_str) > 0;
        }
        // ќператор <
        bool operator < (const String& str2)
        {
            return std::strcmp(this->i_str, str2.i_str) < 0;
        }
        // ќператор []
        char& operator [] (size_t i)
        {
            return i_str[i];
        }
        // ћетод find Ц поиск первого вхождени€ символа в строку слева
        char* Find(const char& req)
        {
            for (int i = 0; i < i_size; i++)
            {
                if (i_str[i] == req)
                {
                    return (char*)i_str[i];
                }
            }
        }
        // ћетод length Ц длина строки
        size_t& Length()
        {
            return i_size;
        }
        // ћетод c_str Ц получить массив char
        char* C_str()
        {
            return i_str;
        }
        // ќператор вывода
        void print()
        {
            for (int i = 0; i < i_size; i++)
            {
                std::cout << i_str[i];
            }
            std::cout << '\n';
        }
        // ћетод at дл€ получени€ доступа (чтение и изменение) к элементу строки 
        char* at(size_t i)
        {
            if (i <= i_size)
            {
                return (char*)i_str[i];
            }
        }
        //ƒеструктор (правило 3-х)
        ~String()
        {
            if (i_str != nullptr)
            {
                delete[] i_str;
            }
        }
        
        friend std::ostream& operator << (std::ostream& output, String& s);
        
        friend std::istream& operator >> (std::istream& input, String& str);

    };
    // ќператор вывода
    std::ostream& operator << (std::ostream& output, String& str)
    {
        output << str.i_str;
        return output;
    }
    // ќператор ввода
    std::istream& operator >> (std::istream& input, String& str)
    {
        char* tmp = new char[1000000000];
        input >> tmp;
        str.i_size = strlen(tmp);
        str.i_str = new char[str.i_size + 1];
        std::copy(tmp, tmp + strlen(tmp) + 1, str.i_str);
        delete[] tmp;
        return input;
    }


int main()
{
    String s("Hello, world!");
    s.print();
    String s1(" 111111111");
    s += s1;
    s.print();
    String s2;
    s2 = s + s1;
    s2.print();
    char z = s2[7];
    std::cout << s2[7] << "\t" << z << "\n";
    String s3;
    std::cin >> s3;
    std::cout << s3;
    return 0;
}
