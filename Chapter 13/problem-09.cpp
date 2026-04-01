// All events have a certain number of visitors permitted. When the maximum number of
// visitors is reached, nobody can enter unless somebody leaves the premises.
// For this purpose, most events implement counter systems that increment the number of people every time somebody enters the event, and decrement the number of people when somebody leaves the event. Typically, the entrance is blocked when the event is fully occupied.
// Design a VisitorCounter class that stores both the current and the maximum capacity of the event. The constructor for the class should have one argument: the maximum capacity of the function. For both fields, a member accessor function should be
// implemented. For the mutator, only functions to add a visitor and to remove a visitor
// should be implemented. The mutator to add a visitor should return true as long as the
// maximum capacity is not reached. It should return false when the visitor is not allowed
// to enter because the maximum capacity has been reached.
// Write a program that demonstrates your VisitorCounter class.

#include <iostream>
using namespace std;

class VisitorCounter {

private:
    int currentVisitors;
    int maxCapacity;

public:
    VisitorCounter(int capacity) {
        maxCapacity = capacity;
        currentVisitors = 0;
    }

    int getCurrentVisitors() {
        return currentVisitors;
    }

    int getMaxCapacity() {
        return maxCapacity;
    }

    bool addVisitor() {
        if (currentVisitors < maxCapacity) {
            currentVisitors++;
            return true;
        } else {
            return false;
        }
    }

    void removeVisitor() {
        if (currentVisitors > 0) {
            currentVisitors--;
        }
    }
};

int main() {
    int capacity;
    cout << "Enter maximum capacity of the event: ";
    cin >> capacity;

    VisitorCounter counter(capacity);
    char choice;

    do {
        cout << "Current visitors: " << counter.getCurrentVisitors() << "/" << counter.getMaxCapacity() << endl;
        cout << "Choose an option: (a)dd visitor, (r)emove visitor, (q)uit: ";
        cin >> choice;

        if (choice == 'a') {
            if (counter.addVisitor()) {
                cout << "Visitor added." << endl;
            } else {
                cout << "Cannot add visitor. Maximum capacity reached!" << endl;
            }
        } else if (choice == 'r') {
            counter.removeVisitor();
            cout << "Visitor removed." << endl;
        } else if (choice == 'q') {
            cout << "Exiting program." << endl;
        } else {
            cout << "Invalid option. Please try again." << endl;
        }
    } while (choice != 'q');

    return 0;
}