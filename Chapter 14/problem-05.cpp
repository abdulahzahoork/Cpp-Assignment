// Design a class named TimeOff. The purpose of the class is to track an employee’s
// sick leave, vacation, and unpaid time off. It should have, as members, the following
// instances of the NumDays class described in Programming Challenge 4:
// maxSickDays A NumDays object that records the maximum number of days of
// sick leave the employee may take.
// sickTaken A NumDays object that records the number of days of sick leave the
// employee has already taken.
// maxVacation A NumDays object that records the maximum number of days of
// paid vacation the employee may take.
// vacTaken A NumDays object that records the number of days of paid vacation
// the employee has already taken.
// maxUnpaid A NumDays object that records the maximum number of days of
// unpaid vacation the employee may take.
// unpaidTaken A NumDays object that records the number of days of unpaid leave
// the employee has taken.
// Additionally, the class should have members for holding the employee’s name and identification number. It should have an appropriate constructor and member functions for
// storing and retrieving data in any of the member objects.
// Input Validation: Company policy states that an employee may not accumulate more
// than 240 hours of paid vacation. The class should not allow the maxVacation object
// to store a value greater than this amount.

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

class TimeOff {
private:
    string employeeName;
    int employeeID;
    NumDays maxSickDays;
    NumDays sickTaken;
    NumDays maxVacation;
    NumDays vacTaken;
    NumDays maxUnpaid;
    NumDays unpaidTaken;

public:
    TimeOff(string name, int id, double maxSick, double maxVac, double maxUnpaid)
        : employeeName(name), employeeID(id), maxSickDays(maxSick), sickTaken(0), maxVacation(maxVac), vacTaken(0), maxUnpaid(maxUnpaid), unpaidTaken(0) {
        if (maxVacation.getHours() > 240) {
            cout << "Max vacation hours cannot exceed 240. Setting to 240." << endl;
            maxVacation.setHours(240);
        }
    }

    void takeSickLeave(double hours) {
        if (sickTaken.getHours() + hours > maxSickDays.getHours()) {
            cout << "Cannot take more sick leave than the maximum allowed." << endl;
        } else {
            sickTaken.setHours(sickTaken.getHours() + hours);
        }
    }

    void takeVacation(double hours) {
        if (vacTaken.getHours() + hours > maxVacation.getHours()) {
            cout << "Cannot take more vacation than the maximum allowed." << endl;
        } else {
            vacTaken.setHours(vacTaken.getHours() + hours);
        }
    }

    void takeUnpaidLeave(double hours) {
        if (unpaidTaken.getHours() + hours > maxUnpaid.getHours()) {
            cout << "Cannot take more unpaid leave than the maximum allowed." << endl;
        } else {
            unpaidTaken.setHours(unpaidTaken.getHours() + hours);
        }
    }

    void displayRecord() const {
        cout << "Employee Name: " << employeeName << endl;
        cout << "Employee ID: " << employeeID << endl;
        cout << "Sick Leave Taken: " << sickTaken.getHours() << " hours" << endl;
        cout << "Vacation Taken: " << vacTaken.getHours() << " hours" << endl;
        cout << "Unpaid Leave Taken: " << unpaidTaken.getHours() << " hours" << endl;
    }
};

int main() {
    TimeOff employee("John Doe", 12345, 80, 240, 160);

    employee.takeSickLeave(16);
    employee.takeVacation(40);
    employee.takeUnpaidLeave(24);

    employee.displayRecord();

    return 0;
}