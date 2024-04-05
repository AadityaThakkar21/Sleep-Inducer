#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <ctime>
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

int main() {
    const int N = 5; // Assuming N is 5 for this example
    Time times[N]; // Array to store average sleep times

    ifstream MyReadFile("Inmate_records.txt");
    string myText;

    if (MyReadFile.is_open()) {
        int idx = 0;
        while (getline(MyReadFile, myText) && idx < N) {
            stringstream ss(myText);
            string name;
            int earpodID;
            Time sleepTimes[7]; // Array to store 7 sleep times

            ss >> name >> earpodID;
            for (int i = 0; i < 7; i++) {
                int hours, minutes;
                char colon;
                ss >> hours >> colon >> minutes;
                sleepTimes[i].set(hours, minutes);
            }

            // Calculate average sleep time
            Time avgSleepTime = Time::calculateAverage(sleepTimes, 7);
            times[idx++] = avgSleepTime;
        }
        MyReadFile.close();

        // Display average sleep times
        cout << "Average Sleep Times:\n";
        for (int i = 0; i < N; i++) {
            cout << "Inmate " << i + 1 << ": ";
            times[i].printTime();
            cout << endl;
        }
    } else {
        cout << "Unable to open file";
    }

    return 0;
}
