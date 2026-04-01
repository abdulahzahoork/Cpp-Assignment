// Design a class Time that represents time in 12-hour format. The class should store time
// in four variables:
// •	 hours
// •	 minutes
// •	 seconds
// •	 am_pm that determines whether it is am or pm
// The class should have member variables to input time in 12-hour format. It should
// display time in the following two formats:
// 1. 12-hour format (e.g., 8:15:33 pm)
// 2. 24-hour format (e.g., 20:15:33)
// Demonstrate the class in a complete program.
// Input Validation: Accept hours only within the range of 0 to 12. Accept minutes and
// seconds only within the range of 0 to 59. Accept only the values “am” or “pm” for
// am_pm. If the hour is 12, the user should not be asked to input the value of am_pm;
// instead am_pm should be automatically assigned “pm”.

#include <iostream>
#include <string>
using namespace std;

class Time {

private:
    int hours;
    int minutes;
    int seconds;
    string am_pm;

public:
    void setTime(int h, int m, int s, string ap) {
        if (h < 0 || h > 12) {
            cout << "Invalid Hours!" << endl;
            return;
        } else if (m < 0 || m > 59) {
            cout << "Invalid Minutes!" << endl;
            return;
        } else if (s < 0 || s > 59) {
            cout << "Invalid Seconds!" << endl;
            return;
        } else if (ap != "am" && ap != "pm") {
            cout << "Invalid AM/PM!" << endl;
            return;
        }

        hours = h;
        minutes = m;
        seconds = s;

        if (hours == 12) {
            am_pm = "pm";
        } else {
            am_pm = ap;
        }
    }

    void print12Hour() {
        cout << hours << ":" << minutes << ":" << seconds << " " << am_pm << endl;
    }

    void print24Hour() {
        int h24 = hours % 12 + (am_pm == "pm" ? 12 : 0);
        cout << h24 << ":" << minutes << ":" << seconds << endl;
    }
};

int main() {
    Time time;
    int h, m, s;
    string ap;

    cout << "Enter hours: ";
    cin >> h;
    cout << "Enter minutes: ";
    cin >> m;
    cout << "Enter seconds: ";
    cin >> s;
    cout << "Enter am/pm: ";
    cin >> ap;

    time.setTime(h, m, s, ap);
    cout << "12-hour format: ";
    time.print12Hour();
    cout << "24-hour format: ";
    time.print24Hour();

    return 0;
}