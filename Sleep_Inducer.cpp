#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to extract p values from Inmate_records.txt and return the lowest one by one
int getLowestP(int arr[], int N) {
    ifstream inFile("Inmate_records.txt");
    if (!inFile) {
        cerr << "Error opening input file." << endl;
        return -1; // Return -1 on error
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

        arr[i++] = p;
    }

    inFile.close();

    // Sort the array in ascending order
    sort(arr, arr + N);

    return arr[0]; // Return the lowest value
}

int main() {
    int N;
    cout << "Enter the number of lines to process: ";
    cin >> N;

    int arr[N];
    int lowestP;

    // Call getLowestP in a while loop to get lowest value one by one
    while ((lowestP = getLowestP(arr, N)) != -1) {
        cout << "Lowest p value: " << lowestP << endl;
    }

    return 0;
}
