#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

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
        int sleepTimes[7];
        for (int j = 0; j < 7; ++j) {
            sleepTimes[j] = randomInt(1, 9); // Generate random sleep time between 1 and 9
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

/*Output:
John 2549 2 4 6 7 8 3 1 24 8
Sophia 8235 3 5 7 9 2 8 6 42 2
Daniel 1789 1 9 2 3 7 5 4 15 7
Emma 6193 8 6 5 4 2 9 3 35 3
*/
