// Design a class that has an array of floating-point numbers. The constructor should
// accept an integer argument and dynamically allocate the array to hold that many
// numbers. The destructor should free the memory held by the array. In addition, there
// should be member functions to perform the following operations:
// •	 Store a number in any element of the array
// •	 Retrieve a number from any element of the array
// •	 Return the highest value stored in the array
// •	 Return the lowest value stored in the array
// •	 Return the average of all the numbers stored in the array
// Demonstrate the class in a program.


#include <iostream>
using namespace std;

class FloatArray {

private: 
    float* arr;
    int size;

public: 
    FloatArray(int s) {
        size = s;
        arr = new float[size];
    }

    ~FloatArray() {
        delete[] arr;
    }

    void store(int index, float value) {
        if (index >= 0 && index < size) {
            arr[index] = value;
        } else {
            cout << "Index out of bounds!" << endl;
        }
    }

    float retrieve(int index) {
        if (index >= 0 && index < size) {
            return arr[index];
        } else {
            cout << "Index out of bounds!" << endl;
            return -1; // Return an invalid value to indicate error
        }
    }

    float getHighest() {
        float highest = arr[0];
        for (int i = 1; i < size; i++) {
            if (arr[i] > highest) {
                highest = arr[i];
            }
        }
        return highest;
    }

    float getLowest() {
        float lowest = arr[0];
        for (int i = 1; i < size; i++) {
            if (arr[i] < lowest) {
                lowest = arr[i];
            }
        }
        return lowest;
    }

    float getAverage() {
        float sum = 0;
        for (int i = 0; i < size; i++) {
            sum += arr[i];
        }
        return sum / size;
    }
};

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    FloatArray floatArray(size);
    float value;

    cout << "Enter " << size << " floating-point numbers:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> value;
        floatArray.store(i, value);
    }

    cout << "Highest value: " << floatArray.getHighest() << endl;
    cout << "Lowest value: " << floatArray.getLowest() << endl;
    cout << "Average value: " << floatArray.getAverage() << endl;

    return 0;
}