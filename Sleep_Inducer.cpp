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

    bool operator>(const Time& other) const {
        if (hours > other.hours) {
            return true;
        } else if (hours == other.hours && minutes > other.minutes) {
            return true;
        }
        return false;
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

void generateRandomTime(Time& sleepTime) {
    sleepTime.set(randomInt(21, 24), randomInt(0, 59));
}

void generateInmateRecords(int N) {
    // Your existing code for generating inmate records here
}

void updateInmateRecords() {
    // Your existing code for updating inmate records here
}

int main()
{
    int N, M, incrementation;
    cout << "Enter number of inmates:\n";
    cin >> N;
    cout << "You have stated there are " << N << " inmates." << endl;
    cout << "Enter number of Dorms:\n";
    cin >> M;
    cout << "You have kept " << M << " Dorms for inmates to stay." << endl;
    int Noofpeopleperdorm = ceil(static_cast<double>(N) / M);
    char UserRandomtaken;
    cout << "Do you want to randomize the sleep time of inmates? Enter 'Y' or 'y' for yes, press any other character to choose as no: ";
    cin >> UserRandomtaken;

    if (UserRandomtaken != 'Y' && UserRandomtaken != 'y') {
        cout << "Sleep time will not be randomized" << endl;
        cout << "Please make sure that file, which you are going to upload is of name inmate_records.txt" << endl;
        cout << "Is your File named 'inmate_records.txt' ? Enter 'Y' or 'y' for yes, press any other character to choose as no: ";
        char fileCheck;
        cin >> fileCheck;
        if (fileCheck != 'Y' && fileCheck != 'y') {
            cout << "Please change the name to 'inmate_records.txt' and run the program again" << endl;
            return 0;
        }
    }

    cout << "How much incrementation do you want to take every cycle? Enter the value: ";
    cin >> incrementation;
    cout << "The time will increment every " << incrementation << " minutes." << endl;

    // Read data from inmate_records.txt and display relevant information
    ifstream MyReadFile("inmate_records.txt");
    string myText;

    if (MyReadFile.is_open()) {
        while (getline(MyReadFile, myText)) {
            stringstream ss(myText);
            string name;
            int earpodID;
            Time sleepTimes[7]; // Array to store sleep times for each inmate
            int p;
            int musicID;

            ss >> name >> earpodID;
            for (int i = 0; i < 7; i++) {
                int hours, minutes;
                char colon;
                ss >> hours >> colon >> minutes;
                sleepTimes[i].set(hours, minutes);
            }

            cout << name << ": ";
            sleepTimes[0].printTime(); // Display the sleep time for the first day

            // Calculate Musicstop by adding average time and P
            Time Musicstop = sleepTimes[0];
            Musicstop.incrementMinutes(incrementation);
            cout << " Music for each inmate will Automatically stop at: ";
            Musicstop.printTime();
            cout << endl;
        }
        MyReadFile.close();
    }
    else {
        cout << "Unable to open file";
    }

    return 0;
}
