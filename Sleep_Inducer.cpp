#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath> // Include cmath for rounding functions

using namespace std;

// Function to generate a random int number between min and max
int randomInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

void generateInmateRecords(int N) {
    ofstream outFile("Inmate_records.txt");
    if (!outFile) {
        cerr << "Error creating output file." << endl;
        return;
    }

    string names[] = {"Rishik", "Venkat", "Sara", "John", "Emma", "Alex", "Sophia", "Daniel", "Emily", "David"};
    int numNames = sizeof(names) / sizeof(names[0]);

    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < N; ++i) {
        string name = names[rand() % numNames];
        int earpodID = randomInt(1000, 9999);
        float sleepTimes[7];
        for (int j = 0; j < 7; ++j) {
            // Generate a random integer between 10 and 90 and divide by 10 to get float between 1.0 to 9.0
            float rawSleepTime = static_cast<float>(randomInt(10, 90)) / 10.0;
            sleepTimes[j] = round(rawSleepTime); // Round off the sleep time to the nearest whole number
        }
        int p = randomInt(0, 60);
        int musicID = randomInt(1, 9); // Music ID between 1 and 9

        outFile << name << " " << earpodID;
        for (int j = 0; j < 7; ++j) {
            outFile << " " << sleepTimes[j];
        }
        outFile << " " << p << " " << musicID << endl;
    }

    outFile.close();
}

int main() {
    int N;
    cout << "Enter the number of inmate records to generate: ";
    cin >> N;

    generateInmateRecords(N);

    cout << "Inmate records generated and saved to 'Inmate_records.txt'." << endl;

    return 0;
}
