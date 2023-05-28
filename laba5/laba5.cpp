// Реализуйте спецификацию шаблона для вектора из булевских значений.
/*
Предусмотрите следующие операции:

1. Метод добавления в конец вектора

2. Метод и оператор получения и изменения значения по индексу

3. Метод size

4. Метод insert и erase
*/


#include <iostream>
#include <vector>




template<class T>
class Bvector {
public:
    Bvector() {}
};

template<>
class Bvector<bool>
{
private:
    int bSize = 0;
    char* arr = new char[bSize + 1];

    void IncreaseArr()
    {
        char* tmp = new char[sizeof(arr) + 1];
        std::copy(arr, arr + sizeof(arr), tmp);
        delete[] arr;
        arr = new char[sizeof(tmp) + 1];
        std::copy(tmp, tmp + sizeof(tmp), arr);
        delete[] tmp;
    }
public:
    //Конструктор
    Bvector()
    {
        arr[0] = 1;
        for (int i = 0; i < 8; ++i)
        {
            arr[0] = (0 << i) & arr[0];
        }
    }
    //оператор получения значения по индексу
    bool operator [] (int index) const {
        return ((arr[index / 8] >> (index % 8)) & 1);
    }
    //Метод изменения значения по индексу
    void ChangeEl(int index, bool el)
    {
        if (index >= bSize)
            PushBack(el);
        else
            arr[index / 8] = (~(1 << (index % 8))) & arr[index / 8] | (el << (index % 8));
    }
    //Метод Size
    int Size()
    {
        return bSize;
    }
    //Метод PushBack для метода ChangeEl
    void PushBack(bool el)
    {
        if ((bSize) / 8 >= sizeof(arr))
        {
            this->IncreaseArr();
        }
        ChangeEl(bSize++, el);
    }
    // Метод insert
    void insert(int index, bool el)
    {
        bool a = 0;
        bool tmp;
        int tmpbSize = bSize;
        for (int i = 0; i < tmpbSize - index; ++i)
        {
            if (i == 0)
                tmp = (*this)[index];
            else
                tmp = a;
            if (i != tmpbSize - index - 1)
                a = (*this)[index + i + 1];
            ChangeEl(index + i + 1, tmp);
        }
        ChangeEl(index, el);
    }
    //Метод Erase
    void Erase(int index, int amo)
    {
        int tindex = index % 8;
        if (tindex < bSize && tindex >= 0 && (index + amo) < bSize)
        {
            for (int i = index; i < bSize; ++i)
            {
                ChangeEl(i, (*this)[i + amo]);
            }
            bSize -= amo;
        }
    }

    ~Bvector()
    {
        delete[] arr;
    }
};

int main()
{
    Bvector<bool> test;
    for (int i = 0; i < 8; ++i)
        std::cout << test[i] << " ";
    std::cout << "only one element, zero" << "\n";
    test.PushBack(1);
    test.insert(1, 1);
    test.ChangeEl(1, 1);
    
    
    for (int i = 0; i < 8; ++i)
        std::cout << test[i] << " ";
    std::cout << " " << "\n";
    for (int i = 0; i < 5; ++i)
    {
        test.PushBack(1);
    }
    for (int i = 0; i < 8; ++i)
        std::cout << test[i] << " ";
    std::cout << "\n";
    test.Erase(3, 2);
    for (int i = 0; i < 8; ++i)
        std::cout << test[i] << " ";
    std::cout << "\n";
}