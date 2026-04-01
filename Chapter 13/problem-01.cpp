// Design a class called Date. The class should store a date in three integers: month, day,and year. 
// There should be member functions to print the date in the following forms:
// - 12/25/2018
// - December 25, 2018
// - 25 December 2018
// Demonstrate the class by writing a complete program implementing it.
// Input Validation: Do not accept values for the day greater than 31 or less than 1. 
// Do not accept values for the month greater than 12 or less than 1.


// #include <iostream>
// using namespace std;

// class Date {

// private:
//     int month;
//     int day;
//     int year;

// public: 
//     void setDate(int m, int d, int y) {
//         if (m < 1 || m > 12) {
//             cout << "Invalid month. Please enter a value between 1 and 12." << endl;
//             return;
//         }
//         if (d < 1 || d > 31) {
//             cout << "Invalid day. Please enter a value between 1 and 31." << endl;
//             return;
//         }
//         month = m;
//         day = d;
//         year = y;
//     }

//     void printNumeric() {
//         cout << month << "/" << day << "/" << year << endl;
//     }

//     void printLong() {
//         const char* months[] = {"January", "February", "March", "April", "May", "June",
//                                 "July", "August", "September", "October", "November", "December"};
//         cout << months[month - 1] << " " << day << ", " << year << endl;
//     }

//     void printDayMonthYear() {
//         const char* months[] = {"January", "February", "March", "April", "May", "June",
//                                 "July", "August", "September", "October", "November", "December"};
//         cout << day << " " << months[month - 1] << " " << year << endl;
//     }
// };

// int main() {
//     Date date;
//     int month, day, year;

//     cout << "Enter month (1-12): ";
//     cin >> month;
//     cout << "Enter day (1-31): ";
//     cin >> day;
//     cout << "Enter year: ";
//     cin >> year;

//     date.setDate(month, day, year);

//     cout << "Numeric format: ";
//     date.printNumeric();

//     cout << "Long format: ";
//     date.printLong();

//     cout << "Day Month Year format: ";
//     date.printDayMonthYear();

//     return 0;
// }



#include <iostream>
using namespace std;

class Date {

private: 
    int day;
    int month;
    int year;

public: 

    void setDate(int d, int m, int y) {
        if (d < 1 || d > 31) {
            cout << "Invalid Day!" << endl;
            return;
        } else if (m < 1 || m > 12) {
            cout << "Invalid Month!" << endl;
            return;
        }

        day = d;
        month = m;
        year = y;
    }

    void printNumeric() {
        cout << month << "/" << day << "/" << year << endl;
    }

    void printLong() {
        string months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
        
        cout << months[month-1] << " " << day << ", " << year << endl;
    }

    void printDMY() {
        string months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

        cout << day << " " << months[month-1] << " " << year << endl;
    }
};


int main() {
    Date date;
    int day, month, year;

    cout << "Enter day: ";
    cin >> day;

    cout << "Enter month: ";
    cin >> month;

    cout << "Enter year: ";
    cin >> year;

    cout << endl;
    date.setDate(day, month, year);
    date.printNumeric();
    date.printLong();
    date.printDMY();

    return 0;
}