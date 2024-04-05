#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <sstream>
#include <cmath>
using namespace std;

class Time {
private:
    int hours;
    int minutes;

public:
    Time() : hours(0), minutes(0) {}
    Time(int h, int m) : hours(h), minutes(m) {}

    void set(int h, int m) {
        hours = h;
        minutes = m;
    }

    void printTime() const {
        std::cout << hours << ":";
        if (minutes < 10) {
            std::cout << "0";
        }
        std::cout << minutes;
    }

    void incrementMinutes(int minutesToAdd) {
        minutes += minutesToAdd;
        if (minutes >= 60) {
            minutes %= 60;
            hours++;
        }
    }

    bool isWithinRange() const {
        return (hours >= 21 && hours < 24);
    }

    bool isMidnight() const {
        return (hours == 24 && minutes == 0);
    }

    static Time calculateAverage(const Time* times, int size) {
        int totalMinutes = 0;
        for (int i = 0; i < size; i++) {
            totalMinutes += times[i].hours * 60 + times[i].minutes;
        }

        int averageMinutes = totalMinutes / size;
        int avgHours = averageMinutes / 60;
        int avgMinutes = averageMinutes % 60;

        return Time(avgHours, avgMinutes);
    }
};

int randomInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

void generateRandomArray(int Finalarr[], int N) {
    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < N; ++i) {
        Finalarr[i] = randomInt(1, 100);
    }
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
        Time sleepTime(randomInt(21, 24), randomInt(0, 59));
        int p = randomInt(0, 60);
        int musicID = randomInt(1, 9);

        outFile << name << " " << earpodID;
        for (int j = 0; j < 7; ++j) {
            outFile << " ";
            sleepTime.printTime();
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

    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);
        string name;
        int earpodID;
        int hours, minutes;
        int p;
        int musicID;

        ss >> name >> earpodID;
        for (int i = 0; i < 7; ++i) {
            ss >> hours >> minutes;
        }
        ss >> p >> musicID;

        outFile << name << " " << earpodID;
        for (int i = 0; i < 7; ++i) {
            outFile << " ";
            Time sleepTime(hours, minutes);
            sleepTime.printTime();
        }
        outFile << " " << p << " " << musicID << endl;
    }

    inFile.close();
    outFile.close();
}

int main()
{
    cout << "Enter number of inmates:\n";
    int N, M;
    cin >> N;
    cout << "Enter number of Dorms:\n";
    cin >> M;
    int Noofpeopleperdorm = ceil(static_cast<double>(N) / M);
    char UserRandomtaken;
    cout << "Do you want to randomize the sleep time of inmates? Enter 'Y' or 'y' for yes, press any other character to choose as no: ";
    cin >> UserRandomtaken;

    if (UserRandomtaken == 'Y' || UserRandomtaken == 'y') {
        cout << "Sleep time will be randomized\n";
        generateInmateRecords(N);
    }
    else {
        cout << "Sleep time will not be randomized\n";
        cout << "Please make sure that file, which you are going to upload is of name " << "'inmate_records.txt'\n";
    }

    ifstream MyReadFile("Inmate_records.txt");
    string myText;

    if (MyReadFile.is_open()) {
        while (getline(MyReadFile, myText)) {
            vector<string> tokens;
            stringstream uuu(myText);
            string intermediate;

            while (getline(uuu, intermediate, ' ')) {
                tokens.push_back(intermediate);
            }
        }
        MyReadFile.close();
    }
    else {
        cout << "Unable to open file";
    }
    
    Time currentTime(21, 0);

    while (currentTime.isWithinRange() && !currentTime.isMidnight()) {
        currentTime.printTime();
        currentTime.incrementMinutes(15);
    }
    
    Time averageTime = Time::calculateAverage(times, 7);

    int Finalarr[N];
    generateRandomArray(Finalarr, N);
    updateInmateRecords(Finalarr, N);
    cout << "Inmate records updated and saved to 'Inmate_records_updated.txt'." << endl;
    return 0;
}
