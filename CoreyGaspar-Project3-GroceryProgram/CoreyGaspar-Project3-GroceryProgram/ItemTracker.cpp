// Author: Corey Gaspar
// Date: 2/15/2025

#include <algorithm>  // Needed to use transform()
#include <string>
#include "ItemTracker.h"

using namespace std;

// Helper function to convert a string to lowercase
string ToLowercase(const string& str) {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

// Constructor loads data from the file
ItemTracker::ItemTracker(const string& filename) {
    LoadData(filename);
}

// Reads input file
void ItemTracker::LoadData(const string& filename) {
    ifstream inFile(filename);
    string item;

    if (!inFile) {
        cout << "Error: Unable to open file." << filename << endl; // Error in case file does not open
        return;
    }

    while (inFile >> item) {
        item = ToLowercase(item);  // Converts the items to lowercase before storing in the file
        itemFrequencies[item]++;
    }

    inFile.close();
}

// User inputs item and returns frequency of that item
int ItemTracker::GetFrequency(const string& item) const {
    string lowerItem = ToLowercase(item);  // Convert user input to lowercase

    auto it = itemFrequencies.find(lowerItem);
    if (it != itemFrequencies.end()) {
        return it->second;  // Return the frequency of the item if it is found in the list
    }
    else {
        return 0;  // Return 0 if item is not found in the list
    }
}


// Displays the frequencies of all items
void ItemTracker::PrintAllFrequencies() const {
    for (const auto& pair : itemFrequencies) {
        cout << pair.first << " " << pair.second << endl;
    }
}

// Prints the item frequencies in a histogram format
void ItemTracker::PrintHistogram() const {
    for (const auto& pair : itemFrequencies) {
        cout << pair.first << " ";
        for (int i = 0; i < pair.second; i++) {
            cout << "*";
        }
        cout << endl;
    }
}

// Takes item frequency and adds it to a file called "frequency.dat"
void ItemTracker::BackupData(const string& filename) const {
    ofstream outputFile(filename);

    if (!outputFile) {
        cerr << "Error: Unable to create " << filename << endl;
        return;
    }

    for (const auto& pair : itemFrequencies) {
        outputFile << pair.first << " " << pair.second << endl;
    }

    outputFile.close();
}
