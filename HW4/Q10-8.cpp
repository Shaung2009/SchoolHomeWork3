/* Test class Television. */
#include <iostream>
#include <string>

using namespace std;

class Television {
private:
    string displayType;
    double dimension;
    string* connectivitySupport;
    int numOfConnectivityModes;

public:
    // Constructor
    Television(string type, double dim, string modes[], int numModes) {
        displayType = type;
        dimension = dim;
        numOfConnectivityModes = numModes;
        connectivitySupport = new string[numModes];
        for (int i = 0; i < numModes; ++i) {
            connectivitySupport[i] = modes[i];
        }
    }

    // Copy constructor
    Television(const Television& tv) {
        displayType = tv.displayType;
        dimension = tv.dimension;
        numOfConnectivityModes = tv.numOfConnectivityModes;
        connectivitySupport = new string[numOfConnectivityModes];
        for (int i = 0; i < numOfConnectivityModes; ++i) {
            connectivitySupport[i] = tv.connectivitySupport[i];
        }
    }

    // Destructor
    ~Television() {
        delete[] connectivitySupport;
        connectivitySupport = NULL;
    }

    // Accessor functions
    string getDisplayType() {
        return displayType;
    }

    double getDimension() {
        return dimension;
    }

    string* getConnectivitySupport() {
        if (connectivitySupport == nullptr) {
            return nullptr;
        }
        return connectivitySupport;
    }

    int getNumOfConnectivityModes() {
        return numOfConnectivityModes;
    }

    // Mutator functions
    void setDisplayType(string type) {
        displayType = type;
    }

    void setDimension(double dim) {
        dimension = dim;
    }

    void setConnectivitySupport(string modes[], int numModes) {
        delete[] connectivitySupport;
        numOfConnectivityModes = numModes;
        connectivitySupport = new string[numModes];
        for (int i = 0; i < numModes; ++i) {
            connectivitySupport[i] = modes[i];
        }
    }
};

int main() {
    string type;
    double dim;
    int numModes;
        
    // Prompt user to enter television's basic information
    cout << "Enter the type of television: ";
    getline(cin, type);
    cout << "Enter the dimension of the television (in inches): ";
    cin >> dim;
    cout << "Enter the number of connectivity modes supported by the television: ";
    cin >> numModes;
    cin.ignore(); // Clear the input buffer

    // Create a television object and set basic information
    string* modes = nullptr;
    if (numModes > 0) {
        modes = new string[numModes];
        cout << "Enter the connectivity modes one by one:" << endl;
        for (int i = 0; i < numModes; ++i) {
            getline(cin, modes[i]);
        }
    }
    Television defaultTV(type, dim, modes, numModes);
    delete[] modes;

    int numOfTVs;
    cout << "Enter the number of televisions to create: ";
    cin >> numOfTVs;

    // Create and set multiple television objects
    for (int i = 0; i < numOfTVs; ++i) {
        Television tvCopy(defaultTV); // Create a copy using the copy constructor
        char customize;
        cout << "Does television " << i + 1 << " need customization? (y/n): ";
        cin >> customize;
        cin.ignore(); // Clear the input buffer

        if (customize == 'y' || customize == 'Y') {
            // User wants customization, prompt for custom information
            string newType;
            double newDim;
            int newNumModes;

            cout << "Enter the new type of television: ";
            getline(cin, newType);
            cout << "Enter the new dimension of the television (in inches): ";
            cin >> newDim;
            cout << "Enter the number of connectivity modes supported by the new television: ";
            cin >> newNumModes;
            cin.ignore(); // Clear the input buffer

            // Set custom information for the television
            tvCopy.setDisplayType(newType);
            tvCopy.setDimension(newDim);
            string* newModes = new string[newNumModes];
            cout << "Enter the new connectivity modes one by one: ";
            for (int j = 0; j < newNumModes; ++j) {
                getline(cin, newModes[j]);
            }
            tvCopy.setConnectivitySupport(newModes, newNumModes);
            delete[] newModes; // Free memory
        }

        // Display television information
        cout << "Basic information of television " << i + 1 << ":" << endl;
        cout << "Type: " << tvCopy.getDisplayType() << endl;
        cout << "Dimension: " << tvCopy.getDimension() << " inches" << endl;
        cout << "Supported connectivity modes:" << endl;
        string* modes = tvCopy.getConnectivitySupport();
        if (modes != nullptr) {
            for (int j = 0; j < tvCopy.getNumOfConnectivityModes(); ++j) {
                cout << modes[j] << endl;
            }
        }
        else {
            cout << "No connectivity modes supported." << endl;
        }
        cout << endl;
    }

    return 0;
}