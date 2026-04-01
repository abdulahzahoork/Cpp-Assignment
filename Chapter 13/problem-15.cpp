// Design a class that will determine the monthly payment on a home mortgage. The
// monthly payment with interest compounded monthly can be calculated as follows:
// Payment = (Loan * (Rate / 12) * Term) / (Term -1)
// where
// Term = (1 + (Rate / 12)) ^ (Years * 12)
// Payment = the monthly payment
// Loan = the dollar amount of the loan
// Rate = the annual interest rate
// Years = the number of years of the loan
// The class should have member functions for setting the loan amount, interest rate, and
// number of years of the loan. It should also have member functions for returning the
// monthly payment amount and the total amount paid to the bank at the end of the loan
// period. Implement the class in a complete program.
// Input Validation: Do not accept negative numbers for any of the loan values.

#include <iostream>
#include <cmath>
using namespace std;

class Mortgage {

private:
    double loan;
    double rate;
    int years;

public:
    void setLoan(double l) {
        if (l < 0) {
            cout << "Invalid Loan Amount!" << endl;
            return;
        }
        loan = l;
    }

    void setRate(double r) {
        if (r < 0) {
            cout << "Invalid Interest Rate!" << endl;
            return;
        }
        rate = r;
    }

    void setYears(int y) {
        if (y < 0) {
            cout << "Invalid Number of Years!" << endl;
            return;
        }
        years = y;
    }

    double getMonthlyPayment() {
        double monthlyRate = rate / 12 / 100;
        int term = pow(1 + monthlyRate, years * 12);
        return (loan * monthlyRate * term) / (term - 1);
    }

    double getTotalPayment() {
        return getMonthlyPayment() * years * 12;
    }
};

int main() {
    Mortgage mortgage;
    double loan, rate;
    int years;

    cout << "Enter the loan amount: ";
    cin >> loan;
    mortgage.setLoan(loan);

    cout << "Enter the annual interest rate (in %): ";
    cin >> rate;
    mortgage.setRate(rate);

    cout << "Enter the number of years for the loan: ";
    cin >> years;
    mortgage.setYears(years);

    cout << "Monthly Payment: $" << mortgage.getMonthlyPayment() << endl;
    cout << "Total Payment: $" << mortgage.getTotalPayment() << endl;

    return 0;
}