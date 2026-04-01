// Design a class called NumDays. The class’s purpose is to store a value that represents a
// number of work hours and convert it to a number of days. For example, 8 hours would
// be converted to 1 day, 12 hours would be converted to 1.5 days, and 18 hours would
// be converted to 2.25 days. The class should have a constructor that accepts a number
// of hours, as well as member functions for storing and retrieving the hours and days.
// The class should also have the following overloaded operators:
// + Addition operator. When two NumDays objects are added together, the overloaded + operator should return the sum of the two objects’ hours members.
// − Subtraction operator. When one NumDays object is subtracted from another,
// the overloaded − operator should return the difference of the two objects’ hours
// members.
// ++ Prefix and postfix increment operators. These operators should increment the
// number of hours stored in the object. When incremented, the number of days
// should be automatically recalculated.
// −− Prefix and postfix decrement operators. These operators should decrement the
// number of hours stored in the object. When decremented, the number of days
// should be automatically recalculated.

#include <iostream>
using namespace std;

class NumDays {
private:
    double hours;
    double days;

public:
    NumDays(double h) {
        hours = h;
        days = hours / 8.0; 
    }

    void setHours(double h) {
        hours = h;
        days = hours / 8.0; 
    }

    double getHours() const {
        return hours;
    }

    double getDays() const {
        return days;
    }

    // Addition operator
    NumDays operator+(const NumDays& other) const {
        return NumDays(hours + other.hours);
    }

    // Subtraction operator
    NumDays operator-(const NumDays& other) const {
        return NumDays(hours - other.hours);
    }

    // Prefix increment
    NumDays& operator++() {
        hours++;
        days = hours / 8.0; 
        return *this;
    }

    // Postfix increment
    NumDays operator++(int) {
        NumDays temp = *this; 
        ++(*this); 
        return temp; 
    }

    // Prefix decrement
    NumDays& operator--() {
        hours--;
        days = hours / 8.0; 
        return *this;
    }

    // Postfix decrement
    NumDays operator--(int) {
        NumDays temp = *this; 
        --(*this); 
        return temp; 
    }
};

int main() {
    NumDays nd1(16); 
    NumDays nd2(24); 

    cout << "nd1: " << nd1.getHours() << " hours, " << nd1.getDays() << " days" << endl;
    cout << "nd2: " << nd2.getHours() << " hours, " << nd2.getDays() << " days" << endl;

    NumDays sum = nd1 + nd2;
    cout << "\nSum: " << sum.getHours() << " hours, " << sum.getDays() << " days" << endl;

    NumDays difference = nd1 - nd2;
    cout << "Difference: " << difference.getHours() << " hours, " << difference.getDays() << " days" << endl;

    ++nd1; 
    cout << "\nAfter prefix incrementing nd1: " << nd1.getHours() << " hours, " << nd1.getDays() << " days" << endl;

    nd2++; 
    cout << "After postfix incrementing nd2: " << nd2.getHours() << " hours, " << nd2.getDays() << " days" << endl;

    --nd1; 
    cout << "\nAfter prefix decrementing nd1: " << nd1.getHours() << " hours, " << nd1.getDays() << " days" << endl;

    nd2--; 
    cout << "After postfix decrementing nd2: " << nd2.getHours() << " hours, " << nd2.getDays() << " days" << endl;

    return 0;
}