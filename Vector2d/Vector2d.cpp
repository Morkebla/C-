#include<iostream>
#include<cmath>

class Vector2
{
public:
    float x;
    float y;
    Vector2(float x, float y);
    Vector2();
    double magnitude()const
{
    return std::sqrt(x*x + y*y);
}
void normalize()
{
    double length = magnitude();
    if (length != 0)
    {
        x /= length;
        y /= length;
    }
}
    friend Vector2 operator+(Vector2 const& v1, Vector2 const& v2)
    {
        return Vector2(v1.x  + v2.x, v1.y + v2.y);
    }
    friend Vector2 operatorMlt(Vector2 const& v1, Vector2 const& v2)
    {
        return Vector2(v1.x * v2.x,v1.y * v2.y);
    }
};

float DotProduct(const Vector2& v1, const Vector2& v2)
{
    return v1.x * v2.x + v1.y * v2.y;
}


Vector2::Vector2()
{
    this->x = 0;
    this->y = 0;
}

Vector2::Vector2(float x, float y)
{
    this->x = x;
    this->y = y;
    double mag = magnitude();
    std::cout << "The magnitude of the vector (" << x << ", " << y << ") is " << mag << std::endl;
}



int main()
{
    Vector2 vec(5, 4);
    Vector2 vec1(3, -2);
    float result = DotProduct(vec, vec1);
    std::cout << result;
}