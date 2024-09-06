#include <iostream>
#include <stdexcept>

class Stack
{
private:
    int* arr;
    int size;
    int capacity;
public:
    Stack() : arr(nullptr), size(0), capacity(4) {
        arr = new int[capacity];
    }
    ~Stack()
    {
        delete[]arr;
    }

    void Push(int value)
    {
        if (size == capacity)
        {
            capacity *= 2;
            int* newArray = new int[capacity];

            std::copy(arr, arr + size, newArray);

            delete[] arr;

            arr = newArray;
        }
        arr[size] = value;
        size++;
    }
    void Pop()
    {
        if (size == 0) { throw std::out_of_range("Stack is Empty"); }
        size--;
        if (size < capacity / 4) 
        {
            capacity /= 2;
            int* newArray = new int[capacity];
            std::copy(arr, arr + size, newArray);
            delete[] arr;
            arr = newArray;
        }
    }
    int Top()const
    {
        if (size == 0) { throw std::out_of_range("Stack is Empty"); }
        return arr[size - 1];
    }
    bool IsEmpty()
    {
        return size == 0;
    }
    int Size()
    {
        return size;
    }
};


int main()
{
    Stack stack;

    // Push some elements
    stack.Push(10);
    stack.Push(20);
    stack.Push(30);

    std::cout << "Top element: " << stack.Top() << std::endl;

    // Pop an element
    stack.Pop();
    std::cout << "Top element after pop: " << stack.Top() << std::endl;

    // Check stack size and if it's empty
    std::cout << "Stack size: " << stack.Size() << std::endl;
    std::cout << "Is stack empty? " << (stack.IsEmpty() ? "Yes" : "No") << std::endl;
}