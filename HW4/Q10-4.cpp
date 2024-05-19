/*
 * Program Description:
 * This program demonstrates the implementation of a Subscriber class, which represents a user subscribed to channels.
 * It provides functionality to create subscribers with different parameters, modify subscriber information,
 * and perform input/output operations for subscribers.
 */

#include<iostream>

using namespace std;

class Subscriber {
public:
    // Constructors
    Subscriber(string name, int num, string* list) : name(name), numChannels(num) {
        setChannelList(list);
    }
    Subscriber(string name, int num) : name(name), numChannels(num), channelList(nullptr) {}
    Subscriber(string name) : name(name), numChannels(0), channelList(nullptr) {}
    Subscriber() : name("None"), numChannels(0), channelList(nullptr) {}

    // Mutators
    void setName(string name) { this->name = name; }
    void setNumChannels(int num) { numChannels = num; }
    void setChannelList(string* list) {
        delete[] channelList;
        channelList = new string[numChannels];
        for (int i = 0; i < numChannels; i++) {
            channelList[i] = list[i];
        }
    }

    // Accessors
    string getName() const { return name; }
    int getNumChannels() const { return numChannels; }
    string* getChannlList() const { return channelList; }

    // Overloaded operators: <<, >>, =
    friend istream& operator >>(istream& input, Subscriber& user); // Allows user input of arbitrary number of channels
    friend ostream& operator <<(ostream& output, const Subscriber& user); // Outputs the name and the list of all channels
    Subscriber& operator =(const Subscriber& other); // Makes copy of the list of channels

    // Reset subscriber: numChannels to 0, channelList to nullptr
    void resetSubscriber() {
        numChannels = 0;
        delete[] channelList;
        channelList = nullptr;
    }

    // Destructor
    ~Subscriber() { delete[] channelList; channelList = nullptr; }
private:
    string name;
    int numChannels;
    string* channelList;
};

int main() {
    // Test constructors
    cout << "Test constructors:\n";
    string testConstruct[2] = { "Foot ball", "Basketball" };
    Subscriber testC3("iAmConstructor3", 2, testConstruct);
    cout << "3 parameter constructor: \n" << testC3 << endl;
    Subscriber testC2("iAmConstructor2", 2);
    cout << "2 parameter constructor: \n" << testC2 << endl;
    Subscriber testC1("iAmConstructor1");
    cout << "1 parameter constructor: \n" << testC1 << endl;
    Subscriber testC0;
    cout << "0 parameter constructor(default): \n" << testC0 << endl;

    // Test mutators
    cout << "Test mutators(same to constructor3):\n";
    testC3.setName("Alan");
    testC3.setNumChannels(2);
    testC3.setChannelList(testConstruct);
    cout << testC3;

    // Test accessors
    cout << "\nTest accessors(same to constructor3):\n";
    cout << "User: " << testC3.getName() << endl;
    cout << "Number of channels: " << testC3.getNumChannels() << endl;
    cout << "List of subscribed channels: \n";
    for (int i = 0; i < testC3.getNumChannels(); i++) {
        cout << *(testC3.getChannlList() + i);
    }
    cout << endl << testC3;

    // Test <<, >>, = operator overloading
    cout << "\nTest <<, >>, = operator overloading:\n";
    Subscriber testInput, testAssign;
    cin >> testInput;
    cout << "You have entered.\n" << testInput << endl;

    cout << "\nTest assignment:\n";
    testAssign = testInput;
    cout << "Should be same as above.\n" << testInput << endl;

    // Test reset
    cout << "\nTest reset.\n";
    testAssign.resetSubscriber();
    cout << testAssign;

    return 0;
}

// Operator Overloading: >>
istream& operator >>(istream& input, Subscriber& user) {
    cout << "Enter user name\n> ";
    input >> user.name;
    cout << "Enter number of channels\n> ";
    input >> user.numChannels;
    cout << "Enter list of all channels:\n";
    user.channelList = new string[user.numChannels];
    for (int i = 0; i < user.numChannels; i++) {
        input >> user.channelList[i];
    }
    return input;
}

// Operator Overloading: <<
ostream& operator <<(ostream& output, const Subscriber& user) {
    output << "User name: " << user.name << endl;
    if (user.numChannels == 0 || user.channelList == nullptr) {
        cout << "None channell on the list.\n";
        return output;
    }
    cout << "Channel list:\n";
    for (int i = 0; i < user.numChannels; i++) {
        output << user.channelList[i] << endl;
    }
    return output;
}

// Operator Overloading: =
Subscriber& Subscriber::operator =(const Subscriber& other) {
    if (this != &other) {
        name = other.name;
        numChannels = other.numChannels;
        delete[] channelList;
        channelList = new string[numChannels];
        for (int i = 0; i < numChannels; i++) {
            channelList[i] = other.channelList[i];
        }
    }
    return *this;
}