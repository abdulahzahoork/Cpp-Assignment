// Design an Inventory class that can hold information and calculate data for items in a
// retail store’s inventory. The class should have the following private member variables:
// Variable Name Description
// itemNumber An int that holds the item’s item number.
// quantity An int for holding the quantity of the items on hand.
// cost A double for holding the wholesale per-unit cost of the item
// totalCost A double for holding the total inventory cost of the item
// (calculated as quantity times cost).
// The class should have the following public member functions:
// Member Function Description
// Default Constructor Sets all the member variables to 0.
// Constructor #2 Accepts an item’s number, cost, and quantity as arguments.
// The function should copy these values to the appropriate
// member variables and then call the setTotalCost function.
// setItemNumber Accepts an integer argument that is copied to the
// itemNumber member variable.
// setQuantity Accepts an integer argument that is copied to the
// quantity member variable.
// setCost Accepts a double argument that is copied to the cost
// member variable.
// setTotalCost Calculates the total inventory cost for the item (quantity
// times cost) and stores the result in totalCost.
// getItemNumber Returns the value in itemNumber.
// getQuantity Returns the value in quantity.
// getCost Returns the value in cost.
// getTotalCost Returns the value in totalCost.
// Demonstrate the class in a driver program.
// Input Validation: Do not accept negative values for item number, quantity, or cost.

#include <iostream>
using namespace std;

class Inventory {

private:
    int itemNumber;
    int quantity;
    double cost;
    double totalCost;

public: 
    Inventory() {
        itemNumber = 0;
        quantity = 0;
        cost = 0.0;
        totalCost = 0.0;
    }

    Inventory(int itemNum, int qty, double c) {
        setItemNumber(itemNum);
        setQuantity(qty);
        setCost(c);
        setTotalCost();
    }

    void setItemNumber(int itemNum) {
        if (itemNum < 0) {
            cout << "Invalid Item Number!" << endl;
            return;
        }
        itemNumber = itemNum;
    }

    void setQuantity(int qty) {
        if (qty < 0) {
            cout << "Invalid Quantity!" << endl;
            return;
        }
        quantity = qty;
    }

    void setCost(double c) {
        if (c < 0) {
            cout << "Invalid Cost!" << endl;
            return;
        }
        cost = c;
    }

    void setTotalCost() {
        totalCost = quantity * cost;
    }

    int getItemNumber() {
        return itemNumber;
    }

    int getQuantity() {
        return quantity;
    }

    double getCost() {
        return cost;
    }

    double getTotalCost() {
        return totalCost;
    }
};

int main() {
    Inventory item1(1001, 10, 5.50);
    Inventory item2(1002, 20, 3.75);
    Inventory item3(1003, 15, 8.25);

    cout << "Item Number: " << item1.getItemNumber() << ", Quantity: " << item1.getQuantity() << ", Cost: $" << item1.getCost() << ", Total Cost: $" << item1.getTotalCost() << endl;
    cout << "Item Number: " << item2.getItemNumber() << ", Quantity: " << item2.getQuantity() << ", Cost: $" << item2.getCost() << ", Total Cost: $" << item2.getTotalCost() << endl;
    cout << "Item Number: " << item3.getItemNumber() << ", Quantity: " << item3.getQuantity() << ", Cost: $" << item3.getCost() << ", Total Cost: $" << item3.getTotalCost() << endl;

    return 0;
}