#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to generate a random int number between min and max
int randomInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Function to generate a random array of integers
void generateRandomArray(int Finalarr[], int N) {
    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < N; ++i) {
        Finalarr[i] = randomInt(1, 100); // Change 100 to the desired maximum value for the array elements
    }
}

// Function to update the Inmate_records.txt file
void updateInmateRecords(int Finalarr[], int N) {
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

        // Rearrange sleep times according to Finalarr
        for (int i = 0; i < 7; ++i) {
            sleepTimes[i] = (i < 6) ? sleepTimes[Finalarr[i]] : Finalarr[6]; // Update 7th sleep time according to Finalarr[N]
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
    int N;
    cout << "Enter the number of elements for the array: ";
    cin >> N;

    int Finalarr[N];
    generateRandomArray(Finalarr, N);

    cout << "Random array generated with " << N << " elements:" << endl;
    for (int i = 0; i < N; ++i) {
        cout << Finalarr[i] << " ";
    }
    cout << endl;

    updateInmateRecords(Finalarr, N);

    cout << "Inmate records updated and saved to 'Inmate_records_updated.txt'." << endl;

    return 0;
}
