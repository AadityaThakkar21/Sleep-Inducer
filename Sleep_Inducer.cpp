#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to extract p values from Inmate_records.txt and return the array sorted in ascending order
void extractPValues(int arrsort[], int N) {
    ifstream inFile("Inmate_records.txt");
    if (!inFile) {
        cerr << "Error opening input file." << endl;
        return; // Exit function on error
    }

    string line;
    int i = 0;
    while (getline(inFile, line) && i < N) {
        stringstream ss(line);
        string name;
        int earpodID;
        vector<float> sleepTimes;
        int p;
        int musicID;

        ss >> name >> earpodID;
        float sleepTime;
        for (int j = 0; j < 7; ++j) {
            ss >> sleepTime;
            sleepTimes.push_back(sleepTime);
        }
        ss >> p >> musicID;

        arrsort[i++] = p;
    }

    inFile.close();

    // Sort the array in ascending order
    sort(arrsort, arrsort + N);
}

int main() {
    int N;
    cout << "Enter the number of lines to process: ";
    cin >> N;

    int arrsort[N];

    // Call extractPValues to populate and sort the array
    extractPValues(arrsort, N);

    // Display the sorted array
    cout << "P values sorted in ascending order:" << endl;
    for (int i = 0; i < N; ++i) {
        cout << arrsort[i] << " ";
    }
    cout << endl;

    return 0;
}
