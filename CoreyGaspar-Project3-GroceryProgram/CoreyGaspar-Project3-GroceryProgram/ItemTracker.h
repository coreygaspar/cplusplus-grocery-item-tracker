// Author: Corey Gaspar
// Date: 2/15/2025
#pragma once
#ifndef ITEM_TRACKER_H
#define ITEM_TRACKER_H

#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

class ItemTracker {
private:
    std::map<string, int> itemFrequencies;  // Stores item counts

    void LoadData(const string& filename);  // Reads input file

public:
    ItemTracker(const string& filename);  // Constructor to load data
    int GetFrequency(const string& item) const;  // Returns frequency of an item
    void PrintAllFrequencies() const;  // Displays all item counts
    void PrintHistogram() const;  // Displays histogram
    void BackupData(const string& filename) const;  // Saves to frequency.dat
};

#endif
