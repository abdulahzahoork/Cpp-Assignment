// Design a Ball class that has member variables for the radius and color of a ball. The
// class should have a member function getVolume that returns the volume of the ball.
// The volume of a sphere with radius r can be calculated using the following formula:
// Volume = 4/3 * pi * r^3
// Create an array of five Ball objects. The program should ask the user for the radius
// and color of each ball object and then display the ball with the maximum volume.

#include <iostream>
#include <string>
using namespace std;

class Ball {

private:
    double radius;
    string color;

public: 
    void setBall(double r, string c) {
        radius = r;
        color = c;
    }

    double getVolume() {
        return (4.0/3.0) * 3.14159 * radius * radius * radius;
    }

    string getColor() {
        return color;
    }
};

int main() {
    Ball balls[5];
    double radius;
    string color;

    for (int i = 0; i < 5; i++) {
        cout << "Enter radius and color of ball " << (i + 1) << ": ";
        cin >> radius >> color;
        balls[i].setBall(radius, color);
    }

    int maxIndex = 0;
    for (int i = 1; i < 5; i++) {
        if (balls[i].getVolume() > balls[maxIndex].getVolume()) {
            maxIndex = i;
        }
    }

    cout << "The ball with the maximum volume is " << balls[maxIndex].getColor() << " with a volume of " << balls[maxIndex].getVolume() << endl;

    return 0;
}