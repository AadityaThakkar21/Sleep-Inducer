#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <sstream>
#include <cmath>
using namespace std;

class Time {
public:
    int hours;
    int minutes;

    Time() : hours(0), minutes(0) {}
    Time(int h, int m) : hours(h), minutes(m) {}

    void set(int h, int m) {
        hours = h;
        minutes = m;
    }
    void check(){
        if(hours>=24){
            hours-=24;
        }
    }
    void printTime() const {
        //check();
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
        return (hours >= 20 && hours < 24);
    }

    bool isMidnight() const {
        return (hours == 24 && minutes == 0);
    }
    
    bool operator>=(const Time& other) const {
    if (hours > other.hours) {
        return true;
    } else if (hours == other.hours && minutes >= other.minutes) {
        return true;
    }
    return false;
}
};

int randomInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

void generateRandomTime(Time& sleepTime) {
    sleepTime.set(randomInt(20, 22), randomInt(0, 59));
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
        Time sleepTime;
        generateRandomTime(sleepTime); // Generate random sleep time
        int p = randomInt(0, 60);
        int musicID = randomInt(1, 5); // Changed to 5 for consistency with your previous code

        outFile << name << " " << earpodID;
        for (int j = 0; j < 7; ++j) {
            generateRandomTime(sleepTime); // Generate random sleep time
        int p = randomInt(0, 60);
        int musicID = randomInt(1, 5); // Changed to 5 for consistency with your previous code
            outFile << " ";
            sleepTime.printTime();
            cout<<" ";
            outFile<<sleepTime.hours<<":";
            if(sleepTime.minutes<10){
                outFile<<"0";
            }
            outFile<<sleepTime.minutes<<" ";
        }
        cout<<endl;
        outFile << " " << p << " " << musicID << endl;
    }

    outFile.close();
}

void updateInmateRecords() {
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
        ss >> hours;
            ss.ignore();
            ss>> minutes;
        outFile << name << " " << earpodID<<" ";
        for (int i = 1; i < 7; ++i) {
            ss >> hours;
            ss.ignore();
            ss>> minutes;
            outFile<<hours<<":";
            if(minutes<10){
                outFile<<"0";
            }
            outFile<<minutes<<" ";
        }
        ss >> p >> musicID;

        Time sleepTime;
        generateRandomTime(sleepTime); // Generate random sleep time

        outFile<< sleepTime.hours<<":"<<sleepTime.minutes;
        outFile  << " "<<p << " " << musicID << endl;
    }

    inFile.close();
    outFile.close();
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
    
    string names[N];
    Time times[N]; // Array to store average sleep times for each inmate
    int Parray[N]; // Array to store P values for each inmate
    int musicIDarray[N]; // Array to store musicID values for each inmate
    Time Musicstop[N]; // Array to store average time + P for each inmate
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
        cout << "Please make sure that the file, which you are going to upload is of the name 'Inmate_records.txt'\n";
        cout << "Is your File named 'Inmate_records.txt' ? Enter 'Y' or 'y' for yes, press any other character to choose as no: \n";
        char fileCheck;
        cin >> fileCheck;
        if (fileCheck != 'Y' && fileCheck != 'y') {
            cout << "Please change the name to 'Inmate_records.txt' and run the program again\n";
            return 0;
        }
    }

    cout << "How much incrementation do you want to take every cycle? Enter the value: ";
    cin >> incrementation;
    cout << "The time will increment every " << incrementation << " minutes." << endl;

    // Read inmate records and calculate required information
    ifstream MyReadFile("Inmate_records.txt");
    string myText;

    if (MyReadFile.is_open()) {
        // string names[N];
        // Time times[N], Musicstop[N];
        // int Parray[N], musicIDarray[N];

        int idx = 0;
        while (getline(MyReadFile, myText) && idx < N) {
            stringstream ss(myText);
            string name;
            int earpodID, hours, minutes, p, musicID;

            ss >> name >> earpodID;
            names[idx] = name;
            
            int totalHours = 0, totalMinutes = 0;
            
for (int i = 0; i < 7; i++) {
    ss >> hours; // Read hours
    ss.ignore(); // Ignore the column ':'
    ss >> minutes; // Read minutes

    // Check for invalid time values
    if (hours < 0 || hours >= 24 || minutes < 0 || minutes >= 60) {
        cerr << "Invalid time value: " << hours << ":" << minutes << endl;
        break; // Exit the loop if the time value is invalid
    }

    totalHours += hours;
    totalMinutes += minutes;
}

        // Calculate average time for the inmate
    int averageHours = totalHours / 7;
    int averageMinutes = totalMinutes / 7;

    times[idx].set(averageHours, averageMinutes);

            ss >> p >> musicID;
            Parray[idx] = p;
            musicIDarray[idx] = musicID;

            // Calculate Musicstop by adding average time and P
            Musicstop[idx] = times[idx];
            Musicstop[idx].incrementMinutes(Parray[idx]);


            idx++;
        }
        MyReadFile.close();

        // Now 'times' array contains the average sleep times for each inmate
        cout << "There are currently " << N << " inmates in " << M << " dorms" << endl;
        cout << "The Present Inmates average Sleep times are:" << endl;
        for (int i = 0; i < N; i++) {
            cout << names[i] << ": ";
            times[i].printTime();
            cout << endl;
        }

        cout << "Time taken by each inmate to fall asleep are:" << endl;
        for (int i = 0; i < N; i++) {
            cout << names[i] << ": " << Parray[i] << " minutes" << endl;
        }

        cout << "Music for each inmate will Automatically stop at:" << endl;
        for (int i = 0; i < N; i++) {
            cout << names[i] << ": ";
            Musicstop[i].check();
            
            Musicstop[i].printTime();
            cout << endl;
        }
    }
    else {
        cout << "Unable to open file";
    }

        Time currentTime(20, 0);
        bool musicPlaying[N] = {false}; // Array to track if music is playing for each inmate
        bool musicStopped = true; // Initialize musicStopped flag outside the loop

        while (currentTime.isWithinRange() && !currentTime.isMidnight()) {
            cout << "Currently the time is ";
            currentTime.printTime();
            cout << endl;

            musicStopped = true; // Flag to check if music has stopped for all inmates

        for (int i = 0; i < N; i++) {
            if (currentTime >= times[i] && !musicPlaying[i]) {
                cout << "Music has been started playing for " << names[i] << " at ";
                times[i].printTime();
                cout << endl;
                musicPlaying[i] = true; // Update musicPlaying status
                musicStopped = false; // Music is playing, so update flag
            }
            if (musicPlaying[i] && currentTime >= Musicstop[i]) {
                cout << "Music Has stopped playing for " << names[i] << " at ";
                Musicstop[i].printTime();
                cout << endl;
                musicPlaying[i] = false; // Update musicPlaying status
                musicStopped = false; // Music is playing, so update flag
            }
            if (!musicPlaying[i]) {
                musicStopped = false; // Music is not stopped for at least one inmate
            }
            else {
                cout << "Music is currently playing for " << names[i] << endl;
            }
        }

        if (musicStopped) {
            cout << "Music is not being played to anyone right now" << endl;
        }

        currentTime.incrementMinutes(incrementation);
        cout << incrementation<<" minutes has passed..." << endl;
    }

    updateInmateRecords();
    cout << "Inmate records updated and saved to 'Inmate_records_updated.txt'." << endl;
    return 0;
}
