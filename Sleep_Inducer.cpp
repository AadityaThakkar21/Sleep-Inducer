#include <bits/stdc++.h>
using namespace std;

int randomInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

void generateInmateRecords(int N) {
    ofstream outFile("Inmate_records.txt");
    if (!outFile) {
        cerr << "Error creating output file." << endl;
        return;
    }

    string names[] = {"Rishik", "Venkat", "Suhas", "John", "Adwaith", "Jayanth", "Sophia", "Krupa", "Sai", "Eswar",
                      "Hari", "Manav", "Madhu", "Arjun", "Ram", "Charan", "Siddharth", "Sri", "Uttam", "Kumar",
                      "Reddy", "Aarohi", "Kriti", "Shetty", "Prabhas", "Rajamouli", "Trivikram", "Bala", "Krishna", "Vinobha",
                      "Lohitha", "Rishi", "Niharaika", "Mahindra", "Nithin", "Aadi", "Ravi", "Soniya", "Lokesh", "Mukesh"};

    int numNames = sizeof(names) / sizeof(names[0]);

    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < N; ++i) {
        string name = names[rand() % numNames];
        int earpodID = randomInt(1000, 9999);
        int sleepTimes[7];
        for (int j = 0; j < 7; ++j) {
            sleepTimes[j] = randomInt(10, 90) / 10; // Generate random sleep time between 1.0 and 9.0
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

    string name;
    int earpodID, sleepTimes[7], p, musicID;
    while (inFile >> name >> earpodID) {
        for (int i = 0; i < 7; ++i) {
            inFile >> sleepTimes[i];
        }
        inFile >> p >> musicID;

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
    cout << "Enter number of inmates: ";
    int N;
    cin >> N;

    char UserRandomtaken;
    cout << "Do you want to randomize the sleep time of inmates? Enter 'Y' or 'y' for yes, any other character for no: ";
    cin >> UserRandomtaken;

    if (UserRandomtaken == 'Y' || UserRandomtaken == 'y') {
        cout << "Sleep time will be randomized\n";
        generateInmateRecords(N);
    } else {
        cout << "Sleep time will not be randomized\n";
        cout << "Please make sure that the input file 'Inmate_records.txt' is correctly formatted.\n";
    }

    int Finalarr[N];
    for (int i = 0; i < N; ++i) {
        Finalarr[i] = i; // Initialize Finalarr with identity permutation initially
    }
    updateInmateRecords(Finalarr, N);
    cout << "Inmate records updated and saved to 'Inmate_records_updated.txt'.\n";
    return 0;
}
