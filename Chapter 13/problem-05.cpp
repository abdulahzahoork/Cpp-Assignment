// Write a class named RetailItem that holds data about an item in a retail store. The
// class should have the following member variables:
// •	 description—a string that holds a brief description of the item
// •	 unitsOnHand—an int that holds the number of units currently in inventory
// •	 price—a double that holds the item’s retail price
// Write a constructor that accepts arguments for each member variable, appropriate mutator functions that store values in these member variables, and accessor functions that
// return the values in these member variables. Once you have written the class, write a separate program that creates three RetailItem objects and stores the following data in them:
// Description Units On Hand Price
// Item #1 Jacket 12 59.95
// Item #2 Designer Jeans 40 34.95
// Item #3 Shirt 20 24.95

#include <iostream>
using namespace std;

class RetailItem {
private:
    string description;
    int unitsOnHand;
    double price;

public:
    RetailItem(string desc, int units, double p) {
        description = desc;
        unitsOnHand = units;
        price = p;
    }

    void setDescription(string desc) {
        description = desc;
    }

    void setUnitsOnHand(int units) {
        unitsOnHand = units;
    }

    void setPrice(double p) {
        price = p;
    }

    string getDescription() {
        return description;
    }

    int getUnitsOnHand() {
        return unitsOnHand;
    }

    double getPrice() {
        return price;
    }
};

int main() {
    RetailItem item1("Jacket", 12, 59.95);
    RetailItem item2("Designer Jeans", 40, 34.95);
    RetailItem item3("Shirt", 20, 24.95);

    cout << "Description: " << item1.getDescription() << ", Units On Hand: " << item1.getUnitsOnHand() << ", Price: $" << item1.getPrice() << endl;
    cout << "Description: " << item2.getDescription() << ", Units On Hand: " << item2.getUnitsOnHand() << ", Price: $" << item2.getPrice() << endl;
    cout << "Description: " << item3.getDescription() << ", Units On Hand: " << item3.getUnitsOnHand() << ", Price: $" << item3.getPrice() << endl;

    return 0;
}