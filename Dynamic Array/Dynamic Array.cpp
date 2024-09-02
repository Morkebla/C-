#include <iostream>
#include <cmath>

class DynamicArray
{
private:
    int* arr;
    int size;
    int capacity;

public:
    DynamicArray() : arr(nullptr), size(0), capacity(4) {
        arr = new int[capacity];
    }
    ~DynamicArray()
    {
        delete[] arr;
    }
    void PushBack(int value)
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
    void PushBack()
    {
        if (size < capacity / 4)
        {
            capacity /= 2;
            int* newArray = new int[capacity];

            std::copy(arr, arr + size, newArray);

            delete[] arr;
            arr = newArray;
        }
        size--;
    }
    int Get(int index)const
    {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        return arr[index];
    }
    void Remove(int index)
    {
        if (index < 0 || index >= size) { throw std::out_of_range("Index out of bounds"); }
        int Iterations = 0;
        int* newArray = new int[size - 1];
        for (int i = 0; i < size; i++)
        {
            if (i != index)
            {
                newArray[Iterations] = arr[i];
                Iterations++;
            }
        }
        delete[] arr;
        arr = newArray;
        size--;
    }
    int Size()const
    {
        return size;
    }
    int Capacity()const
    {
        return capacity;
    }
    const int& operator[](int index)const
    {
        if (index < 0 || index >= size) { throw std::out_of_range("Index out of bounds"); }
        return arr[index];
    }
    int& operator[](int index)
    {
        if (index < 0 || index >= size) { throw std::out_of_range("Index out of bounds"); }
        return arr[index];
    }
};

int main() {
    DynamicArray arr;

    arr.PushBack(10);
    arr.PushBack(20);
    arr.PushBack(30);
    arr.PushBack(40);

    std::cout << "Array elements: ";
    for (int i = 0; i < arr.Size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    arr.PushBack(50);  // Should trigger a resize

    std::cout << "Array after pushing back 50: ";
    for (int i = 0; i < arr.Size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    arr.PushBack();  // Remove the last element

    std::cout << "Array after popping back: ";
    for (int i = 0; i < arr.Size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    arr.Remove(1);  // Remove element at index 1

    std::cout << "Array after removing index 1: ";
    for (int i = 0; i < arr.Size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
