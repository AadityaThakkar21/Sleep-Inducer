#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to update the Inmate_records.txt file
void updateInmateRecords(const vector<int>& Arr, int N) {
    ifstream inFile("Inmate_records.txt");
    if (!inFile) {
        cerr << "Error opening input file." << endl;
        return;
    }

    ofstream outFile("Inmate_records_updated.txt");
    if (!outFile) {
        cerr << "Error creating output file." << endl;
        inFile.close();
        return;
    }

    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);
        string name;
        int earpodID;
        vector<float> sleepTimes;
        int p;
        int musicID;

        ss >> name >> earpodID;
        float sleepTime;
        for (int i = 0; i < 7; ++i) {
            ss >> sleepTime;
            sleepTimes.push_back(sleepTime);
        }
        ss >> p >> musicID;

        // Rearrange sleep times according to Arr
        for (int i = 0; i < 7; ++i) {
            sleepTimes[i] = (i < 6) ? sleepTimes[Arr[i]] : Arr[6]; // Update 7th sleep time according to Arr[N]
        }

        // Write updated record to output file
        outFile << name << " " << earpodID;
        for (int i = 0; i < 7; ++i) {
            outFile << " " << sleepTimes[i];
        }
        outFile << " " << p << " " << musicID << endl;
    }

    inFile.close();
    outFile.close();
}

int main() {
    // Sample Arr and N for testing
    vector<int> Arr = {3, 0, 2, 1, 5, 4, 6}; // Example Arr[]
    int N = 4; // Number of lines to update

    updateInmateRecords(Arr, N);

    cout << "Inmate records updated and saved to 'Inmate_records_updated.txt'." << endl;

    return 0;
}
