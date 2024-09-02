#include <iostream>
#include <cmath>
class Rectangle
{
private:
    float width;
    float height;
public:
    Rectangle() : width(0), height(0) {};
    Rectangle(float w, float h) : width(w), height(h) {};

    float Area()const
    {
        return width * height;
    }
    float Perimeter()const
    {
        return 2 * (width + height);
    }
    bool isSquare()const
    {
        return width == height;
    }
    void resize(float newWidth, float newHeight)
    {
        if (newWidth <= 0 || newHeight <= 0){return;}
        width = newWidth;
        height = newHeight;
    }
    friend bool operator==(const Rectangle&  rec1, const Rectangle&  rec2)
    {
        bool areEqual = false;
        if (rec1.height == rec2.height && rec1.width == rec2.width)
        {
            areEqual = true;
        }
        else
        {
            areEqual = false;
        }
        return areEqual;
    }
    friend std::ostream& operator<<(std::ostream& os, const Rectangle& rec)
    {
        os << "Width: " << rec.width << ", Height: " << rec.height;
        return os;
    }
};




int main()
{
    Rectangle r1(5, 10);
    Rectangle r2(5, 5);
    Rectangle r3(7, 10);

    std::cout << "Area of r1: " << r1.Area() << std::endl;
    std::cout << "Perimeter of r1: " << r1.Perimeter() << std::endl;
    std::cout << "Is r1 a square? " << (r1.isSquare() ? "Yes" : "No") << std::endl;
    std::cout << "Is r1 equal to r2? " << (r1 == r2 ? "Yes" : "No") << std::endl;
    std::cout << "Rectangle r1 details: " << r1 << std::endl;
    r2.resize(0, 0);
    std::cout << "Rectangle r2 details: " << r2 << std::endl;
    r2.resize(6, 2);
    std::cout << "Rectangle r2 details: " << r2 << std::endl;
}
