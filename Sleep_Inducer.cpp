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
        float sleepTimes[7];
        for (int j = 0; j < 7; ++j) {
            // Generate a random integer between 10 and 90 and divide by 10 to get float between 1.0 to 9.0
            sleepTimes[j] = static_cast<float>(randomInt(10, 90)) / 10.0;
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
Sara 5284 6.7 2.5 4.2 1.3 9.0 7.1 8.4 18 4
Daniel 7413 1.2 4.7 6.8 5.1 2.3 8.9 3.6 25 7
David 3826 3.5 2.8 7.4 8.9 1.6 5.3 4.7 35 6
Sophia 9201 9.0 1.7 3.4 6.9 5.2 7.8 8.1 42 8
*/
