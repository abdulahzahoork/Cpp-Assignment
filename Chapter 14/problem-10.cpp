// A corporation has six divisions, each responsible for sales to different geographic locations. Design a DivSales class that keeps sales data for a division, with the following
// members:
// •	 An array with four elements for holding four quarters of sales figures for the division.
// •	 A private static variable for holding the total corporate sales for all divisions for the
// entire year.
// •	 A member function that takes four arguments, each assumed to be the sales for a
// quarter. The value of the arguments should be copied into the array that holds the
// sales data. The total of the four arguments should be added to the static variable
// that holds the total yearly corporate sales.
// •	 A function that takes an integer argument within the range of 0–3. The argument is
// to be used as a subscript into the division quarterly sales array. The function should
// return the value of the array element with that subscript.
// Write a program that creates an array of six DivSales objects. The program should
// ask the user to enter the sales for four quarters for each division. After the data are
// entered, the program should display a table showing the division sales for each quarter.
// The program should then display the total corporate sales for the year.
// Input Validation: Only accept positive values for quarterly sales figures.

#include <iostream>
using namespace std;

class DivSales {

private:
    double quarterlySales[4];
    static double totalCorporateSales;

public:
    void setSales(double q1, double q2, double q3, double q4) {
        if (q1 < 0 || q2 < 0 || q3 < 0 || q4 < 0) {
            cout << "Sales figures must be positive!" << endl;
            return;
        }
        quarterlySales[0] = q1;
        quarterlySales[1] = q2;
        quarterlySales[2] = q3;
        quarterlySales[3] = q4;
        totalCorporateSales += (q1 + q2 + q3 + q4);
    }

    double getQuarterlySales(int quarter) const {
        if (quarter < 0 || quarter > 3) {
            cout << "Invalid quarter! Returning 0." << endl;
            return 0;
        }
        return quarterlySales[quarter];
    }

    static double getTotalCorporateSales() {
        return totalCorporateSales;
    }


};

double DivSales::totalCorporateSales = 0;

int main() {
    DivSales divisions[6];

    for (int i = 0; i < 6; i++) {
        double q1, q2, q3, q4;
        cout << "Enter sales for Division " << (i + 1) << " (Q1 Q2 Q3 Q4): ";
        cin >> q1 >> q2 >> q3 >> q4;
        divisions[i].setSales(q1, q2, q3, q4);
    }

    cout << "\nDivision Sales Table:" << endl;
    cout << "Division\tQ1\tQ2\tQ3\tQ4" << endl;
    for (int i = 0; i < 6; i++) {
        cout << (i + 1) << "\t\t" 
             << divisions[i].getQuarterlySales(0) << "\t" 
             << divisions[i].getQuarterlySales(1) << "\t" 
             << divisions[i].getQuarterlySales(2) << "\t" 
             << divisions[i].getQuarterlySales(3) << endl;
    }

    cout << "\nTotal Corporate Sales for the Year: " << DivSales::getTotalCorporateSales() << endl;

    return 0;
}