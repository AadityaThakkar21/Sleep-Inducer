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
