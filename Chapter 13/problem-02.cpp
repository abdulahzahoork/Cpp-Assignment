// Write a class named Employee that has the following member variables:
// •	 name—a string that holds the employee’s name
// •	 idNumber—a n int variable that holds the employee’s ID number
// •	 department—a string that holds the name of the department where the employee
// works
// •	 position—a string that holds the employee’s job title
// The class should have the following constructors:
// •	 A constructor that accepts the following values as arguments and assigns them to
// the appropriate member variables: employee’s name, employee’s ID number, department, and position.
// •	 A constructor that accepts the following values as arguments and assigns them to the
// appropriate member variables: employee’s name and ID number. The department
// and position fields should be assigned an empty string ("").
// •	 A default constructor that assigns empty strings ("") to the name, department, and
// position member variables, and 0 to the idNumber member variable.
// Write appropriate mutator functions that store values in these member variables and
// accessor functions that return the values in these member variables. Once you have
// written the class, write a separate program that creates three Employee objects to hold
// the following data:
// Name ID Number Department Position
// Susan Meyers 47899 Accounting Vice President
// Mark Jones 39119 IT Programmer
// Joy Rogers 81774 Manufacturing Engineer
// The program should store this data in the three objects and then display the data for
// each employee on the screen.

#include <iostream>
using namespace std;

class Employee {

private:
    string name;
    int idNumber;
    string department;
    string position;

public: 
    Employee(string n, int id, string dept, string pos) {
        name = n;
        idNumber = id;
        department = dept;
        position = pos;
    }

    Employee(string n, int id) {
        name = n;
        idNumber = id;
        department = "";
        position = "";
    }

    Employee() {
        name = "";
        idNumber = 0;
        department = "";
        position = "";
    }

    void setName(string n) {
        name = n;
    }

    void setIdNumber(int id) {
        idNumber = id;
    }

    void setDepartment(string dept) {
        department = dept;
    }

    void setPosition(string pos) {
        position = pos;
    }

    string getName() {
        return name;
    }

    int getIdNumber() {
        return idNumber;
    }

    string getDepartment() {
        return department;
    }

    string getPosition() {
        return position;
    }
};

int main() {
    Employee emp1("Susan Meyers", 47899, "Accounting", "Vice President");
    Employee emp2("Mark Jones", 39119, "IT", "Programmer");
    Employee emp3("Joy Rogers", 81774, "Manufacturing", "Engineer");

    cout << "Name: " << emp1.getName() << endl;
    cout << "ID Number: " << emp1.getIdNumber() << endl;
    cout << "Department: " << emp1.getDepartment() << endl;
    cout << "Position: " << emp1.getPosition() << endl;
    cout << endl;

    cout << "Name: " << emp2.getName() << endl;
    cout << "ID Number: " << emp2.getIdNumber() << endl;
    cout << "Department: " << emp2.getDepartment() << endl;
    cout << "Position: " << emp2.getPosition() << endl;
    cout << endl;

    cout << "Name: " << emp3.getName() << endl;
    cout << "ID Number: " << emp3.getIdNumber() << endl;
    cout << "Department: " << emp3.getDepartment() << endl;
    cout << "Position: " << emp3.getPosition() << endl;

    return 0;
}