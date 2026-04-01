// A certain person has earnings from both permanent and freelance jobs. Design a
// Salary class that stores his basic salary and other allowances (50% of the basic salary) for each month. Design a Freelance class that stores the number of jobs done in
// a year, and an array holding the income from each job. Include appropriate member
// functions in both the classes. Write a friend function to display his annual income.
// Demonstrate the classes and function in a program.

#include <iostream>
using namespace std;

class Salary {
private:
    double basicSalary;
    double allowances;

public:
    Salary(double basic) : basicSalary(basic), allowances(0.5 * basic) {}

    double getAnnualSalary() const {
        return (basicSalary + allowances) * 12;
    }

    double getBasicSalary() const {
        return basicSalary;
    }

    double getAllowances() const {
        return allowances;
    }

    friend double calculateAnnualIncome(const Salary& salary, const class Freelance& freelance);
};

class Freelance {

private:
    int numJobs;
    double* jobIncomes;

public:
    Freelance(int jobs) : numJobs(jobs) {
        jobIncomes = new double[numJobs];
    }

    ~Freelance() {
        delete[] jobIncomes;
    }

    void setJobIncome(int index, double income) {
        if (index >= 0 && index < numJobs) {
            jobIncomes[index] = income;
        }
    }

    double getTotalFreelanceIncome() const {
        double total = 0;
        for (int i = 0; i < numJobs; i++) {
            total += jobIncomes[i];
        }
        return total;
    }

    friend double calculateAnnualIncome(const Salary& salary, const Freelance& freelance);
};

double calculateAnnualIncome(const Salary& salary, const Freelance& freelance) {
    return salary.getAnnualSalary() + freelance.getTotalFreelanceIncome();
}

int main() {
    double basicSalary;
    int numJobs;

    cout << "Enter basic salary: ";
    cin >> basicSalary;

    Salary salary(basicSalary);

    cout << "Enter number of freelance jobs: ";
    cin >> numJobs;

    Freelance freelance(numJobs);

    for (int i = 0; i < numJobs; i++) {
        double income;
        cout << "Enter income for job " << (i + 1) << ": ";
        cin >> income;
        freelance.setJobIncome(i, income);
    }

    double annualIncome = calculateAnnualIncome(salary, freelance);
    cout << "Total Annual Income: " << annualIncome << endl;

    return 0;
}