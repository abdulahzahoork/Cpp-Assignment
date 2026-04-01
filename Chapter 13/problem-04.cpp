// Write a class named BroadcastStation that has member variables for the following
// data:
// •	 Name of the station
// •	 Frequency
// •	 Type of band (FM or AM)
// •	 The genre of the station (country, sports, rock, classic, etc.)
// The BroadcastStation class should have a constructor that accepts an argument for
// each member variable. The BroadcastStation class should also have accessor and
// mutator functions for each member variable.
// Next, write a class RadioReceiver that represents a basic radio that can store two
// preset channels. The RadioReceiver class should have member variables for:
// •	 The current volume of the radio
// •	 The name, frequency, and type of the current radio channel
// •	 Two instances of the BroadcastStation class for the two preset channels
// The RadioReceiver class should have a constructor with no arguments: all member
// variables should be initialized to factory default settings. The RadioReceiver class
// should have accessor and mutator functions for each member variable.
// Because in a typical radio the volume and frequency are changed by turning a knob,
// also supply mutator functions for the volume and frequency that increase and decrease
// the current value by 1 unit. It should also be possible to store the current radio channel
// in one of the preset channels, and to change the current radio channel by selecting one
// of the preset channels.
// Also write a function that displays the current state of the RadioReceiver, including
// the preset channels.
// Next, demonstrate the correct working of your classes in a program that creates an
// instance of the RadioReceiver and then performs actions with the RadioReceiver.
// Make sure that all information of the RadioReceiver is displayed after each interaction.

#include <iostream>
using namespace std;

class BroadcastStation {

private:
    string name;
    double frequency;
    string bandType;
    string genre;

public: 
    BroadcastStation(string n, double f, string b, string g) {
        name = n;
        frequency = f;
        bandType = b;
        genre = g;
    }

    void setName(string n) {
        name = n;
    }

    void setFrequency(double f) {
        frequency = f;
    }

    void setBandType(string b) {
        bandType = b;
    }

    void setGenre(string g) {
        genre = g;
    }

    string getName() {
        return name;
    }

    double getFrequency() {
        return frequency;
    }

    string getBandType() {
        return bandType;
    }

    string getGenre() {
        return genre;
    }
};

class RadioReceiver {

private:
    int volume;
    string currentChannelName;
    double currentChannelFrequency;
    string currentChannelBandType;
    BroadcastStation preset1;
    BroadcastStation preset2;

public:
    RadioReceiver() : preset1("Preset 1", 0.0, "FM", "None"), preset2("Preset 2", 0.0, "FM", "None") {
        volume = 5;
        currentChannelName = "None";
        currentChannelFrequency = 0.0;
        currentChannelBandType = "FM";
    }

    void setVolume(int v) {
        volume = v;
    }

    void setCurrentChannel(string name, double frequency, string bandType) {
        currentChannelName = name;
        currentChannelFrequency = frequency;
        currentChannelBandType = bandType;
    }

    void setPreset1(BroadcastStation station) {
        preset1 = station;
    }

    void setPreset2(BroadcastStation station) {
        preset2 = station;
    }

    int getVolume() {
        return volume;
    }

    string getCurrentChannelName() {
        return currentChannelName;
    }

    double getCurrentChannelFrequency() {
        return currentChannelFrequency;
    }

    string getCurrentChannelBandType() {
        return currentChannelBandType;
    }

    BroadcastStation getPreset1() {
        return preset1;
    }

    BroadcastStation getPreset2() {
        return preset2;
    }

    void increaseVolume() {
        volume++;
    }

    void decreaseVolume() {
        volume--;
    }

    void displayStatus() {
        cout << "Current Volume: " << volume << endl;
        cout << "Current Channel: " << currentChannelName << " (" << currentChannelFrequency << " " << currentChannelBandType << ")" << endl;
        cout << "Preset 1: " << preset1.getName() << " (" << preset1.getFrequency() << " " << preset1.getBandType() << ", Genre: " << preset1.getGenre() << ")" << endl;
        cout << "Preset 2: " << preset2.getName() << " (" << preset2.getFrequency() << " " << preset2.getBandType() << ", Genre: " << preset2.getGenre() << ")" << endl;
    }
};

int main() {
    RadioReceiver radio;

    BroadcastStation station1("Rock FM", 101.5, "FM", "Rock");
    BroadcastStation station2("Country AM", 550.0, "AM", "Country");

    radio.setPreset1(station1);
    radio.setPreset2(station2);

    radio.displayStatus();

    cout << "\nChanging current channel to Preset 1..." << endl;
    radio.setCurrentChannel(radio.getPreset1().getName(), radio.getPreset1().getFrequency(), radio.getPreset1().getBandType());
    radio.displayStatus();

    cout << "\nIncreasing volume..." << endl;
    radio.increaseVolume();
    radio.displayStatus();

    cout << "\nChanging current channel to Preset 2..." << endl;
    radio.setCurrentChannel(radio.getPreset2().getName(), radio.getPreset2().getFrequency(), radio.getPreset2().getBandType());
    radio.displayStatus();

    cout << "\nDecreasing volume..." << endl;
    radio.decreaseVolume();
    radio.displayStatus();

    return 0;
}