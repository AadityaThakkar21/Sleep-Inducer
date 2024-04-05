#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function to generate a random float number between min and max
float randomFloat(float min, float max) {
    return min + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(max-min)));
}

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
            sleepTimes[j] = randomFloat(0.0, 24.0);
        }
        int p = randomInt(0, 60);

        outFile << name << " " << earpodID;
        for (int j = 0; j < 7; ++j) {
            outFile << " " << sleepTimes[j];
        }
        outFile << " " << p << endl;
    }

    outFile.close();
}

int main()
{
    int N; // Here N is the Number of Inmates
    cin >> N;

    int M; // Here M is the Number of sleeping dorms
    cin >> M;

    int Noofpeopleperdorm = N / M; // Here Noofpeopleperdorm is the Number of people living per dorm

    char UserRandomtaken;
    cout << "Do you want to randomize the sleep time of inmates? Enter Y/N: ";
    cin >> UserRandomtaken;

    if (UserRandomtaken == 'Y' || UserRandomtaken == 'y') {
        cout << "Sleep time will be randomized";
    }
    else if (UserRandomtaken == 'N' || UserRandomtaken == 'n') {
        cout << "Sleep time will not be randomized";
    }
    else {
        cout << "Irrelevant char entered by user";
        
    generateInmateRecords(N);

    cout << "Inmate records generated and saved to 'Inmate_records.txt'." << endl;
    return 0;
}
