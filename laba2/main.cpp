/*
���������� ����� String ��� ������ �� ��������.

� ��� ������ ���� �����������:

1. ������� �����������

2. ����������� ����������� (������� 3-�)

3. �������� ������������ ������������ (������� 3-�)

4. ���������� (������� 3-�)

5. ��������� + � +=

6. �������� [] � ������ � ��������� ��������

7. ��������� <, >, ==

8. ��������� ����� � ������ � �����

9. ����� find � ����� ������� ��������� ������� � ������ �����

10. ����� length � ����� ������

11. ����� c_str � �������� ������ char

12. ����� at ��� ��������� ������� (������ � ���������) � �������� ������ � ��������� �� ����� �� ������� ������
*/


#include <iostream>

    class String
    {
    private:
        size_t i_size;
        char* i_str = nullptr;


    public:
        String() = default;
        //����������� ����������� (������� 3-�)
        String(const char* str) : i_size(strlen(str)), i_str(new char[i_size + 1]) 
        {
            std::copy(str, str + i_size + 1, i_str);
        }

        String(String& old) : String(old.i_str)
        {

        }
        //�������� ������������ ������������ (������� 3-�)
        String& operator = (const String& other)
        {
            if (i_str != nullptr)
                delete[] i_str;
            i_size = other.i_size;
            i_str = new char[i_size + 1];
            std::copy(other.i_str, other.i_str + i_size + 1, this->i_str);
            return *this;
        }
        //�������� +=
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
        //�������� +
        String operator + (const String& term)
        {
            String tmp;
            tmp = *this;
            tmp += term;
            return tmp;
        }
        // �������� ==
        bool operator == (const String& str2)
        {
            return std::strcmp(this->i_str, str2.i_str) == 0;
        }
        // �������� >
        bool operator > (const String& str2)
        {
            return std::strcmp(this->i_str, str2.i_str) > 0;
        }
        // �������� <
        bool operator < (const String& str2)
        {
            return std::strcmp(this->i_str, str2.i_str) < 0;
        }
        // �������� []
        char& operator [] (size_t i)
        {
            return i_str[i];
        }
        // ����� find � ����� ������� ��������� ������� � ������ �����
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
        // ����� length � ����� ������
        size_t& Length()
        {
            return i_size;
        }
        // ����� c_str � �������� ������ char
        char* C_str()
        {
            return i_str;
        }
        // �������� ������
        void print()
        {
            for (int i = 0; i < i_size; i++)
            {
                std::cout << i_str[i];
            }
            std::cout << '\n';
        }
        // ����� at ��� ��������� ������� (������ � ���������) � �������� ������ 
        char* at(size_t i)
        {
            if (i <= i_size)
            {
                return (char*)i_str[i];
            }
        }
        //���������� (������� 3-�)
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
    // �������� ������
    std::ostream& operator << (std::ostream& output, String& str)
    {
        output << str.i_str;
        return output;
    }
    // �������� �����
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
