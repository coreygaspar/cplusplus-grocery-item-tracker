// Author: Corey Gaspar
// Date: 2/15/2025
#include "ItemTracker.h"

using namespace std;

void DisplayMenu() {
    cout << "======================================\n";
    cout << "===== Corner Grocer Item Tracker =====\n";
    cout << "1. Search for an item\n";
    cout << "2. Display all item frequencies\n";
    cout << "3. Display histogram\n";
    cout << "4. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    ItemTracker tracker("InputFile.txt");  // Load file data InputFile.txt
    tracker.BackupData("frequency.dat");  // Create backup file frequency.dat

    int choice;
    string item;

    while (true) {
        DisplayMenu();
        cin >> choice;
        cin.ignore();  // Clear newline from input buffer
        cout << "======================================\n"; // Adds a line at the bottom after user input

        switch (choice) {
        case 1:
            cout << "Enter item name: ";
            getline(cin, item);

            if (tracker.GetFrequency(item) > 0) {
                cout << item << ": " << tracker.GetFrequency(item) << endl;
            }
            else {
                cout << item << " not found in the list." << endl;
            }
            break;
        case 2:
            tracker.PrintAllFrequencies();
            break;
        case 3:
            tracker.PrintHistogram();
            break;
        case 4:
            cout << "Exiting program...\n";
            return 0;
        default:
            cout << "Input is invalid. Please choose from the printed options.\n";
        }
    }
}

