// Programming Challenge 2
// Assuming a year has 365 days, write a class named DayOfYear that takes an integer
// representing a day of the year and translates it to a string consisting of the month followed by day of the month. For example,
// Day 2 would be January 2.
// Day 32 would be February 1.
// Day 365 would be December 31.
// The constructor for the class should take as parameter an integer representing the day
// of the year, and the class should have a member function print() that prints the day
// in the month–day format. The class should have an integer member variable to represent the day, and should have static member variables holding string objects that can
// be used to assist in the translation from the integer format to the month–day format.
// Test your class by inputting various integers representing days and printing out their
// representation in the month–day format.

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
            dayOfYear = 1; // Default to January 1
        } else {
            dayOfYear = day;
        }
    }

    void print() {
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
};

string DayOfYear::months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
int DayOfYear::daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    int day;

    cout << "Enter a day of the year (1-365): ";
    cin >> day;

    DayOfYear date(day);
    cout << "Day " << day << " would be ";
    date.print();

    return 0;
}