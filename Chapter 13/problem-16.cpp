// The following table lists the freezing and boiling points of several substances.
// Substance Freezing Point Boiling Point
// Ethyl alcohol −173 172
// Oxygen −362 −306
// Water 32 212
// Design a class that stores a temperature in a temperature member variable and has the
// appropriate accessor and mutator functions. In addition to appropriate constructors,
// the class should have the following member functions:
// •	 isEthylFreezing—This function should return the bool value true if the temperature stored in the temperature field is at or below the freezing point of ethyl
// alcohol. Otherwise, the function should return false.
// •	 isEthylBoiling—This function should return the bool value true if the temperature stored in the temperature field is at or above the boiling point of ethyl alcohol.
// Otherwise, the function should return false.
// •	 isOxygenFreezing—This function should return the bool value true if the temperature stored in the temperature field is at or below the freezing point of oxygen.
// Otherwise, the function should return false.
// •	 isOxygenBoiling—This function should return the bool value true if the temperature stored in the temperature field is at or above the boiling point of oxygen.
// Otherwise, the function should return false.
// •	 isWaterFreezing—This function should return the bool value true if the temperature stored in the temperature field is at or below the freezing point of water.
// Otherwise, the function should return false.
// •	 isWaterBoiling—This function should return the bool value true if the temperature stored in the temperature field is at or above the boiling point of water.
// Otherwise, the function should return false.
// Write a program that demonstrates the class. The program should ask the user to enter
// a temperature, then display a list of the substances that will freeze at that temperature,
// and those that will boil at that temperature. For example, if the temperature is −20
// the class should report that water will freeze and oxygen will boil at that temperature.

#include <iostream>
using namespace std;

class Temperature {

private:
    double temp;

public:
    Temperature() {
        temp = 0.0;
    }

    Temperature(double t) {
        temp = t;
    }

    void setTemperature(double t) {
        temp = t;
    }

    double getTemperature() {
        return temp;
    }

    bool isEthylFreezing() {
        return temp <= -173;
    }

    bool isEthylBoiling() {
        return temp >= 172;
    }

    bool isOxygenFreezing() {
        return temp <= -362;
    }

    bool isOxygenBoiling() {
        return temp >= -306;
    }

    bool isWaterFreezing() {
        return temp <= 32;
    }

    bool isWaterBoiling() {
        return temp >= 212;
    }
};

int main() {
    Temperature temperature;
    double temp;

    cout << "Enter a temperature: ";
    cin >> temp;
    temperature.setTemperature(temp);

    cout << "At " << temp << " degrees:" << endl;

    if (temperature.isEthylFreezing()) {
        cout << "- Ethyl alcohol will freeze." << endl;
    }
    if (temperature.isEthylBoiling()) {
        cout << "- Ethyl alcohol will boil." << endl;
    }
    if (temperature.isOxygenFreezing()) {
        cout << "- Oxygen will freeze." << endl;
    }
    if (temperature.isOxygenBoiling()) {
        cout << "- Oxygen will boil." << endl;
    }
    if (temperature.isWaterFreezing()) {
        cout << "- Water will freeze." << endl;
    }
    if (temperature.isWaterBoiling()) {
        cout << "- Water will boil." << endl;
    }

    return 0;
}