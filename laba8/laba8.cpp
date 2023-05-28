/*
Вашей задачей будет создать шаблонный класс для реализации стека. В нем нужно предусмотреть методы:

1. Конструктор с указанием размера стека

2. Метод size

3. Метод empty – возвращает true или false

4. Метод push, чтобы положить в элемент в стек

5. Метод pop, чтобы извлечь элемент из стека

6. Метод top, чтобы посмотреть верхний элемент стека, но не извлекать его.

Добавьте обработку некорректных ситуаций через исключения:

1. Невозможно выделить необходимый участок памяти под стек (std::bad_alloc).

2. Невозможно добавить новый элемент в стек (например, std::overflow_error)

3. Невозможно извлечь элемент из стека, так как стек пустой (например, std::out_of_range)

4. Невозможно посмотреть элемент на вершине стека, так как стек пустой (например, std::logic_error).
*/


#include <iostream>

template <class T>
class Stack
{
private:
    int i_MaxSize = 0;
    int i_Size = 0;
    T* i_Elements;
public:
    // Конструктор
    Stack(int msize)
    {
        i_MaxSize = msize;
        try
        {
            i_Elements = new T[msize];
        }
        catch (const std::bad_alloc) // Исключение: невозможно выделить память
        {
            std::cerr << "Constructor ERROR: too big size";
        }
    }
    // Метод Size
    int Size()
    {
        return i_Size;
    }
    // Метод Empty
    bool Empty()
    {
        return i_Size == 0;
    }
    // Метод Push
    bool Push(T NewElement)
    {
        if (i_Size < i_MaxSize)
        {
            i_Elements[i_Size] = NewElement;
            ++i_Size;
        }
        else
        {
            throw std::overflow_error("Push ERROR: stack is full"); // Исключение: невозможность добавления нового элемента
        }
    }
    // Метод Pop
    T Pop()
    {
        if (i_Size != 0)
        {
            T tmp = i_Elements[0];
            for (int i = 0; i < i_MaxSize - 1; ++i)
            {
                i_Elements[i] = i_Elements[i + 1];
            }
            --i_Size;
            return tmp;
        }
        else
        {
            throw std::out_of_range("Pop ERROR: stack is empty");
        }
    }
    // Метод Top
    T& Top()
    {
        if (i_Size != 0)
        {
            return i_Elements[i_Size - 1];
        }
        else
        {
            throw std::logic_error("Top ERROR: stack is empty");
        }
    }
    // Деструктор
    ~Stack()
    {
        delete[] i_Elements;
    }

};

int main()
{
    Stack<int> stack(25);
    for (int i = 176; i < 200; ++i)
    {
        stack.Push(i);
    }
    std::cout << stack.Size() << "\n";
    std::cout << stack.Pop() << "\n";
    std::cout << stack.Size() << "\n";
    std::cout << stack.Top() << "\n";
    std::cout << stack.Size() << "\n";
    std::cout << stack.Empty() << "\n";
}