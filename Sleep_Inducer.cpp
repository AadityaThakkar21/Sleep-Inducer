#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
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

    string names[] = {"Rishik", "Venkat", "Sara", "John", "Emma", "Alex", "Sophia", "Daniel", "Emily", "David",
                      "Michael", "Ethan", "Olivia", "Isabella", "James", "Alexander", "Benjamin", "Elijah", "William", "Lucas",
                      "Matthew", "Aiden", "Mia", "Charlotte", "Abigail", "Ella", "Avery", "Scarlett", "Grace", "Amelia",
                      "Logan", "Lucas", "Jackson", "Christopher", "Mason", "Evelyn", "Aria", "Chloe", "Liam", "Zoe"};

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
        generateInmateRecords(N);
    }
    else if (UserRandomtaken == 'N' || UserRandomtaken == 'n') {
        cout << "Sleep time will not be randomized";
    }
    else {
        cout << "Irrelevant char entered by user";
    }

    return 0;
}
