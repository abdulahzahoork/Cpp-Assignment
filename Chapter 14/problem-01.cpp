// Design a Participant class used for listing candidates who have registered for a seminar. The class should record the following data about each participant:
// •	 Name of the participant, including the first name and last name.
// •	 The organisation with which the participant is associated.
// The class should have two other member variables, total_candidates and serial_
// number. The variable total_candidates should record the total number of candidates
// registered and the variable serial_number should record the serial number of the
// participants.
// The class should include the following member functions:
// •	 constructor—increments total_candidates and assigns serial_number as the
// current value of the total number of registered candidates to the last candidate.
// •	 setRecord—inputs the other member variables.
// •	 getRecord—displays the record of a participant.
// •	 showTotal—displays the total number of participants.
// Demonstrate the class in a full program.

#include <iostream>
using namespace std;

class Participant {

private:
    string firstName;
    string lastName;
    string organisation;
    static int total_candidates;
    int serial_number;

public:
    Participant() {
        total_candidates++;
        serial_number = total_candidates;
    }

    void setRecord() {
        cout << "Enter first name: ";
        cin >> firstName;
        cout << "Enter last name: ";
        cin >> lastName;
        cout << "Enter organisation: ";
        cin >> organisation;
    }

    void getRecord() {
        cout << "Serial Number: " << serial_number << endl;
        cout << "Name: " << firstName << " " << lastName << endl;
        cout << "Organisation: " << organisation << endl;
    }

    static void showTotal() {
        cout << "Total Participants: " << total_candidates << endl;
    }
};

int Participant::total_candidates = 0;

int main() {
    Participant p1, p2;

    p1.setRecord();
    p2.setRecord();

    cout << "\nParticipant 1 Record:" << endl;
    p1.getRecord();

    cout << "\nParticipant 2 Record:" << endl;
    p2.getRecord();

    Participant::showTotal();

    return 0;
}