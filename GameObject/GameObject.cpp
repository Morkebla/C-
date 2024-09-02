#include <cmath>
#include <iostream>

class Vector2 {
public:
    float x;
    float y;

    // Default constructor
    Vector2() : x(0), y(0) {}

    // Parameterized constructor
    Vector2(float x, float y) : x(x), y(y) {}

    // Calculate magnitude
    double Magnitude() const {
        return std::sqrt(x * x + y * y);
    }

    // Normalize the vector
    void normalize() {
        float length = Magnitude();
        if (length != 0) {
            x /= length;
            y /= length;
        }
    }
};

class GameObject {
public:
    // Constructors
    GameObject() : position(0, 0), velocity(0, 0) {}
    GameObject(float posX, float posY, float velX, float velY)
        : position(posX, posY), velocity(velX, velY) {}

    // Update the position based on velocity
    void update() {
        position.x += velocity.x;
        position.y += velocity.y;
    }

    // Getters
    float getPositionX() const {
        return position.x;
    }

    float getPositionY() const {
        return position.y;
    }

    float getVelocityX() const {
        return velocity.x;
    }

    float getVelocityY() const {
        return velocity.y;
    }

    // Setters
    void setPositionX(float posX) {
        position.x = posX;
    }

    void setPositionY(float posY) {
        position.y = posY;
    }

    void setVelocityX(float velX) {
        velocity.x = velX;
    }

    void setVelocityY(float velY) {
        velocity.y = velY;
    }

    // Print method to display position and velocity
    void print() const {
        std::cout << "Position: (" << position.x << ", " << position.y << ")"
            << " Velocity: (" << velocity.x << ", " << velocity.y << ")" << std::endl;
    }

private:
    Vector2 position;
    Vector2 velocity;
};

int main() {
    GameObject obj(0, 0, 1, 1);

    // Display initial state
    obj.print();

    // Update the object and display new state
    obj.update();
    obj.print();

    obj.update();
    obj.print();

}
