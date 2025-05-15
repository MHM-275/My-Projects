#pragma once

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct mobile {
    string manufacturer;  // Manufacturer: Company
    string model;
    string OS;            // OS: Operating System
    float size;           // size: Size of Screen in Inches
    int price;
};

const int Mobiles = 7;
mobile mobArray[Mobiles];
void readfile() {
    ifstream inFile("D:/input.txt");
    if (!inFile) {
        cout << "File not found: "  << endl;
    }
    else {
        cout << "File found successfully: " << endl;
        for (int i = 0; i < Mobiles; i++) {
            getline(inFile, mobArray[i].manufacturer);
            getline(inFile, mobArray[i].model);
            getline(inFile, mobArray[i].OS);
            inFile >> mobArray[i].size;
            inFile >> mobArray[i].price;
            inFile.ignore(); // Ignore newline
        }
    }
    inFile.close();
}

void printDetails(mobile m) {
    cout << "Details of Mobile:" << endl;
    cout << "Manufacturer: " << m.manufacturer << endl;
    cout << "Model: " << m.model << endl;
    cout << "OS: " << m.OS << endl;
    cout << "Size: " << m.size << " inches" << endl;
    cout << "Price: $" << m.price << endl;
}

void Sorting() {
    for (int i = 0; i < Mobiles - 1; i++) {
        for (int j = 0; j < Mobiles - i - 1; j++) {
            if (mobArray[j].price < mobArray[j + 1].price) {
                mobile temp = mobArray[j];
                mobArray[j] = mobArray[j + 1];
                mobArray[j + 1] = temp;
            }
        }
    }
}


void writefile(const string& filename) {
    ofstream outFile(filename);
    if (!outFile) {
        cout << "Error creating file: " << filename << endl;
    }
    else {
        cout << "File created successfully: " << filename << endl;
        for (int i = 0; i < Mobiles; i++) {
            outFile << mobArray[i].manufacturer << endl;
            outFile << mobArray[i].model << endl;
            outFile << mobArray[i].OS << endl;
            outFile << mobArray[i].size << endl;
            outFile << mobArray[i].price << endl;
        }
        outFile.close();
    }
}
