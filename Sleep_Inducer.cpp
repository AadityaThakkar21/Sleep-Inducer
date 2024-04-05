#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <sstream>
#include <cmath>
using namespace std;

int randomInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Function to generate a random array of integers
void generateRandomArray(int Finalarr[], int N) {
    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < N; ++i) {
        Finalarr[i] = randomInt(1, 100); // Change 100 to the desired maximum value for the array elements
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

// Function to update the Inmate_records.txt file
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
        vector<float> sleepTimes;
        int p;
        int musicID;

        ss >> name >> earpodID;
        float sleepTime;
        for (int i = 0; i < 7; ++i) {
            ss >> sleepTime;
            sleepTimes.push_back(sleepTime);
        }
        ss >> p >> musicID;

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

#include <iostream>

class Time {
private:
    int hours;
    int minutes;

public:
    Time(int h, int m) : hours(h), minutes(m) {}

    void printTime() const {
        std::cout << "Time: ";
        if (hours < 10) {
            std::cout << "0";
        }
        std::cout << hours << ":";
        if (minutes < 10) {
            std::cout << "0";
        }
        std::cout << minutes << std::endl;
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


int main()
{   
    cout<<"Enter number of inmates:\n";
    int N,s,M; // Here N is the no of Inmates
    cin >> N;
 // Here M is the no of sleeping dorms
     cout<<"Enter number of Dorms:\n";

    cin >> M;
     s = static_cast<int>(ceil(static_cast<double>(N) / M));
    int Noofpeopleperdorm = s; // Here Noofpeopleperdorm is the no of people living per dorm

    char UserRandomtaken;
    cout << "Do you want to randomize the sleep time of inmates? Enter' Y' or 'y 'for yes, press any other charecter to choose as no: ";
    cin >> UserRandomtaken;

    if (UserRandomtaken == 'Y' || UserRandomtaken == 'y') {
        cout << "Sleep time will be randomized\n";
        generateInmateRecords(N);
    }
    else  {
        cout << "Sleep time will not be randomized\n";
        cout<<"Please make sure that file, which you are going to upload is of name "<<"'inmate_records.txt'\n";
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
            // cout<<tokens[0];

            // for (const auto& token : tokens) {
            //     cout << token << endl; 
            //  }
        }
        MyReadFile.close();
    } else {
        cout << "Unable to open file";
    }

    Time currentTime(21, 0);

    while (currentTime.isWithinRange() && !currentTime.isMidnight()) {
        currentTime.printTime();
        currentTime.incrementMinutes(15);
    }

    int Finalarr[N];
    generateRandomArray(Finalarr, N);
    updateInmateRecords(Finalarr, N);
    cout << "Inmate records updated and saved to 'Inmate_records_updated.txt'." << endl;
    return 0;
}

/*Output:
Sophia 4589 21:10 21:10 21:10 21:10 21:10 21:10 21:10 47 7
Krupa 7852 22:45 22:45 22:45 22:45 22:45 22:45 22:45 23 3
John 6143 21:59 21:59 21:59 21:59 21:59 21:59 21:59 11 9
Sai 2387 23:25 23:25 23:25 23:25 23:25 23:25 23:25 14 5
Eswar 7031 22:05 22:05 22:05 22:05 22:05 22:05 22:05 54 8
*/
