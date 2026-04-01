// Programming Challenge 3
// Modify the DayOfYear class, written in Programming Challenge 2, to add a constructor that takes two parameters: a string object representing a month and an integer in
// the range 0 through 31 representing the day of the month. The constructor should then
// initialize the integer member of the class to represent the day specified by the month
// and day of month parameters. The constructor should terminate the program with an
// appropriate error message if the number entered for a day is outside the range of days
// for the month given
// Add the following overloaded operators:
// ++ prefix and postfix increment operators. These operators should modify the
// DayOfYear object so it represents the next day. If the day is already the end of
// the year, the new value of the object will represent the first day of the year.
// −− prefix and postfix decrement operators. These operators should modify the
// DayOfYear object so it represents the previous day. If the day is already the
// first day of the year, the new value of the object will represent the last day of
// the year.

#include <iostream>
using namespace std;

class DayOfYear {
private:
    int dayOfYear;
    static string months[12];
    static int daysInMonth[12];

public:
    DayOfYear(int day) {
        if (day < 1 || day > 365) {
            cout << "Invalid day of the year!" << endl;
            dayOfYear = 1; 
        } else {
            dayOfYear = day;
        }
    }
    DayOfYear(const string& month, int day) {
        int monthIndex = -1;
        for (int i = 0; i < 12; i++) {
            if (months[i] == month) {
                monthIndex = i;
                break;
            }
        }

        if (monthIndex == -1) {
            cout << "Invalid month!" << endl;
            dayOfYear = 1; 
            return;
        }

        if (day < 1 || day > daysInMonth[monthIndex]) {
            cout << "Invalid day for the given month!" << endl;
            dayOfYear = 1; 
            return;
        }

        dayOfYear = day;
        for (int i = 0; i < monthIndex; i++) {
            dayOfYear += daysInMonth[i];
        }
    }
    void print() const {
        int monthIndex = 0;
        int remainingDays = dayOfYear;

        while (monthIndex < 12 && remainingDays > daysInMonth[monthIndex]) {
            remainingDays -= daysInMonth[monthIndex];
            monthIndex++;
        }

        if (monthIndex < 12) {
            cout << months[monthIndex] << " " << remainingDays << "."<< endl;
        } else {
            cout << "Invalid day of the year!" << endl;
        }
    }

    void printDayNumber() const {
        cout << "Day number: " << dayOfYear << endl;
    }

    // Prefix increment
    DayOfYear& operator++() {
        dayOfYear++;
        if (dayOfYear > 365) {
            dayOfYear = 1; 
        }
        return *this;
    }
    
    // Postfix increment
    DayOfYear operator++(int) {
        DayOfYear temp = *this; 
        ++(*this); 
        return temp; 
    } 

    // Prefix decrement
    DayOfYear& operator--() {
        dayOfYear--;
        if (dayOfYear < 1) {
            dayOfYear = 365; 
        }
        return *this;
    }

    // Postfix decrement
    DayOfYear operator--(int) {
        DayOfYear temp = *this; 
        --(*this); 
        return temp; 
    }
};

string DayOfYear::months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
int DayOfYear::daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    int day;
    cout << "Enter a day of the year (1-365): ";
    cin >> day;

    DayOfYear date1(day); 

    string month;
    int dayOfMonth;
    cout << "Enter a month: ";
    cin >> month;
    cout << "Enter a day of the month: ";
    cin >> dayOfMonth;
    DayOfYear date2(month, dayOfMonth); 

    cout << "Initial dates:" << endl;
    date1.print();
    date2.printDayNumber();

    // Testing increment and decrement operators
    cout << "Date 1 after prefix increment: ";
    ++date1;
    date1.print();

    cout << "Date 1 after postfix increment: ";
    date1++;
    date1.print();

    cout << "Date 1 after prefix decrement: ";
    --date1;
    date1.print();

    cout << "Date 1 after postfix decrement: ";
    date1--;
    date1.print();

    return 0;
}