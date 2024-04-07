#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <sstream>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;
using std::left;

const int MAX_DORMS = 100;
const int MAX_INMATES_PER_DORM = 100;
struct ChannelControl {
    bool occupied;
    int dormIndex;
    int musicID;
    vector<int> earpodID;

    ChannelControl() : occupied(false), dormIndex(-1), musicID(-1) {}
};
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
        cout << hours << ":";
        if (minutes < 10) {
            cout << "0";
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
    int currentEarpodID = 1000; // Initialize currentEarpodID

    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < N; ++i) {
        string name = names[rand() % numNames];
        Time sleepTime;
        generateRandomTime(sleepTime); // Generate random sleep time
        int p = randomInt(10, 59);
        int musicID = randomInt(1, 5); // Changed to 5 for consistency with your previous code

        // Ensure earpodID is within 4 digits and starts from 1000
        if (currentEarpodID >= 10000) {
            cerr << "Error: Maximum earpodID limit reached." << endl;
            break;
        }
        int earpodID = currentEarpodID++;

        outFile << left;
        outFile << setw(10) << name << " " << earpodID << " ";

        for (int j = 0; j < 7; ++j) {
            generateRandomTime(sleepTime); // Generate random sleep time
            int p = randomInt(0, 60);
            int musicID = randomInt(1, 5); // Changed to 5 for consistency with your previous code

            outFile << " ";
            outFile << sleepTime.hours << ":";
            if (sleepTime.minutes < 10) {
                outFile << "0";
            }
            outFile << sleepTime.minutes << " ";
        }
        outFile << " " << setw(3) << p << " " << musicID << endl;
    }

    outFile.close();
}

void generateDormRecords(int M, int numberofchannels) {
    ofstream outFile("Dorm_records.txt");
    if (!outFile) {
        cerr << "Error creating output file." << endl;
        return;
    }

    char dormName = 'A'; // Start with DormA and increment for each dorm
    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < M; ++i) {
        outFile << "Dorm" << dormName << " "; // Output Dorm name
        dormName++; // Increment dorm name for the next dorm
    }
    outFile << endl;

    for (int j = 0; j < numberofchannels; ++j) {
        outFile << j + 10 << " "; // Generate channel numbers starting from 10
    }
    outFile << endl;

    for (int k = 1; k < 6; ++k) {
        outFile << k << " "; // Generate music ID numbers starting from 1
    }
    outFile << endl;

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
    // int x;
    while (getline(inFile, line)) {
        stringstream ss(line);
        string name;
        int earpodID;
        int hours, minutes;
        int p;
        int musicID;
        ss>>left;
        ss >> name >> earpodID;
        ss >> hours;
            ss.ignore();
            // x=hours*60;
            ss>> minutes;
            // x+=minutes;
            outFile<<left;
        outFile << setw(10)<<name << " " << earpodID<<" ";
        for (int i = 1; i < 7; ++i) {
            ss >> hours;
            ss.ignore();
            
            ss>> minutes;
            // x+=hours*60+minutes;
            outFile<<hours<<":";
            if(minutes<10){
                outFile<<"0";
            }
            outFile<<minutes<<" ";
        }
        ss >> p >> musicID;

        Time sleepTime;
        generateRandomTime(sleepTime); // Generate random sleep time
outFile<< sleepTime.hours<<":";
        if(sleepTime.minutes<10){
            outFile<<"0";
        }
        outFile<<sleepTime.minutes;
        // outFile<< x/(7*60)<<":";
        // if(x%60<10){
        //     outFile<<"0";
        // }
        // outFile<<x%60;
        outFile  << " "<<setw(3)<<p << " " << musicID << endl;
    }

    inFile.close();
    outFile.close();
}

// void printNamesAndEarpodIDs(const string names[], const int earpodIDarray[], int N) {
//     cout << "Here is the list of Names and their respective EarpodID:" << endl;
//     for (int i = 0; i < N; i++) {
//         cout << names[i] << ": " << earpodIDarray[i] << endl;
//     }
// }
    
    struct Record {
    string name;
    int EarpodID;
    int MusicID;
    int Dorm;
};
struct MusicChannel {
    bool occupied;
    int dormIndex;
    int earpodID[100]; // Assuming a maximum of 100 earpod IDs per channel
    int musicID;

    MusicChannel() : occupied(false), dormIndex(-1), musicID(-1) {
        // Initialize earpodID array with -1
        for (int i = 0; i < 100; ++i) {
            earpodID[i] = -1;
        }
    }
};
int main() {
    int N, M, incrementation, peopleperdorm, numberofchannels;
  vector<string> DormName;
    vector<int> ChannelIDrecord;
    int BackupChannels;
    int *BackupEarpodID;
    
    int Channelsize = ChannelIDrecord.size();
    vector<vector<int>> ChannelID(Channelsize, vector<int>(peopleperdorm));
    vector<int> MusicID;
    cout << "Enter number of inmates:\n";
    cin >> N;
    cout << "You have stated there are " << N << " inmates." << endl;
    cin.ignore();
    
    cout << "Enter number of Dorms:\n";
    cin >> M;
    cout << "You have kept " << M << " Dorms for inmates to stay." << endl;
    cin.ignore();    

        // Added code to read the number of people per dorm and number of channels
    cout << "Enter number of people per dorm:\n";
    cin >> peopleperdorm;
    cout << "You have set " << peopleperdorm << " people per dorm." << endl;
    cin.ignore();
    // Check if N exceeds capacity
    if(N<= M*peopleperdorm){
        cout<<"Thank you.. You can accomdate sucessfully.\n";
    }
    else if (N > M * (peopleperdorm+1)) {
        cout << "Error: Number of inmates exceeds dorm capacity. Program terminated." << endl;
        return 1; // Terminate the program
    }
    else if (N > M * (peopleperdorm) && N<= M*(peopleperdorm+1)) {
        cout << "We can still allocate inmates to dorms by increasing one dorm capacity, Do you want to continue? Enter 'y' for yes or any other character for no: " << endl;
       char y;
       cin >> y;
       if(y=='y' || y=='Y'){
       peopleperdorm++;
       }
       else{
           return 0;
       }
    }
    // vector<vector<int>> Dorms(M, vector<int>(peopleperdorm));
    
    cout << "Enter number of channels:\n";
    cin >> numberofchannels;
    cout << "You have set " << numberofchannels << " channels." << endl;
    cin.ignore();
    
  
    string names[N];
    Time times[N];
    int Parray[N];
    int musicIDarray[N];
    Time Musicstop[N];
    int earpodIDarray[N];
    
    char UserRandomtaken;
    cout << "Do you want to randomize the sleep time of inmates? Enter 'Y' or 'y' for yes, press any other character to choose as no: ";
    cin >> UserRandomtaken;
    cin.ignore();
    if (UserRandomtaken == 'Y' || UserRandomtaken == 'y') {
        cout << "Sleep time will be randomized\n";
        generateInmateRecords(N);
    }
    else {
        cout << "Sleep time will not be randomized\n";
        cout << "Please make sure that the file, which you are going to upload is named 'Inmate_records.txt'\n";
        cout << "Is your file named 'Inmate_records.txt'? Enter 'Y' or 'y' for yes, press any other character to choose no: \n";
        char fileCheck;
        cin >> fileCheck;
            cin.ignore();
        if (fileCheck != 'Y' && fileCheck != 'y') {
            cout << "Please change the name to 'Inmate_records.txt' and re-run the program again\n";
            return 0;
        }
    }
    
    char UserDormtaken;
    cout << "Do you want to randomize the Dorms of inmates? Enter 'Y' or 'y' for yes, press any other character to choose as no: ";
    cin >> UserDormtaken;
    cin.ignore();
    if (UserDormtaken == 'Y' || UserDormtaken == 'y') {
        cout << "Dorms will be randomized\n";
        generateDormRecords(M, numberofchannels);
    }
    else {
        cout << "Dorms will not be randomized\n";
        cout << "Please make sure that the file, which you are going to upload is named 'Dorm_records.txt'\n";
        cout << "Is your file named 'Dorm_records.txt'? Enter 'Y' or 'y' for yes, press any other character to choose no: ";
        char fileCheck;
        cin >> fileCheck;
        cin.ignore();
        if (fileCheck != 'Y' && fileCheck != 'y') {
            cout << "Please change the name to 'Dorm_records.txt' and run the program again\n";
            return 0;
        }
        else{
            ifstream file("Inmate_records.txt");
        string myText;
        if(!file.is_open()){
            cout<<"Error opening file.\n";
            return 0;
        }
        else{
            int check=0;
            while(getline(file,myText)){
                check++;
            }
            if(check!=N){
                cout<<"The file doesn't have "<<N<<" inputs.\nDo you want to continue with "<<check<<" number of inputs?(Enter y for yes, if you enter anyother , it will be taken as a no)";
                char s;
                cin>>s;
                if(s=='y'||s=='Y'){
                    N=check;
                    cout<<"Proceeding.Thank you.Please re enter number again."<<endl;
                    cout << "Enter number of Dorms:\n";
    cin >> M;
    cout << "You have kept " << M << " Dorms for inmates to stay." << endl;
    cin.ignore();    

    cout << "Enter number of people per dorm:\n";
    cin >> peopleperdorm;
    cout << "You have set " << peopleperdorm << " people per dorm." << endl;
    cin.ignore();
    
    if(N<= M*peopleperdorm){
        cout<<"\n";
    }
    else if (N > M * (peopleperdorm+1)) {
        cout << "Error: Number of inmates exceeds dorm capacity. Program terminated." << endl;
        return 1;
    }
    else if (N > M * (peopleperdorm) && N<= M*(peopleperdorm+1)) {
        cout << "We can still allocate inmates to dorms by increasing one dorm capacity, Do you want to continue? Enter 'y' for yes or any other character for no: " << endl;
       char y;
       cin >> y;
       if(y=='y' || y=='Y'){
       peopleperdorm++;
       }
       else{
           return 0;
       }
    }
                }
                else{
                return 0;
            }
            }
        }
        }
    }

    cout << "How much incrementation do you want to take every cycle? Enter the value: ";
    cin >> incrementation;
    cin.ignore();
    cout << "The time will increment every " << incrementation << " minutes." << endl;

    ifstream MyReadFile("Inmate_records.txt");
    string myText;

    if (MyReadFile.is_open()) {
        int idx = 0;
        while (getline(MyReadFile, myText) && idx < N) {
            stringstream ss(myText);
            string name;
            int earpodID, hours, minutes, p, musicID;

            ss >> name >> earpodID;
            names[idx] = name;
            earpodIDarray[idx] = earpodID; 
            int totalHours = 0, totalMinutes = 0;
            
            for (int i = 0; i < 7; i++) {
                ss >> hours;
                ss.ignore();
                ss >> minutes;

                if (hours < 0 || hours >= 24 || minutes < 0 || minutes >= 60) {
                    cout << "Invalid time value: " << hours << ":" << minutes << endl;
                    cerr << "Error invalid time";
                    return 0;
                }

                totalHours += hours;
                totalMinutes += minutes;
            }

            int averageHours = totalHours / 7;
            int averageMinutes = totalMinutes / 7;

            times[idx].set(averageHours, averageMinutes);

            ss >> p >> musicID;
            Parray[idx] = p;
            musicIDarray[idx] = musicID;

            Musicstop[idx] = times[idx];
            Musicstop[idx].incrementMinutes(Parray[idx]);

            idx++;
        }
        MyReadFile.close();
    }
            
    ifstream inFile("Dorm_records.txt");
    if (!inFile) {
        cerr << "Error opening input file." << endl;
        return 1;
    }

    string line;
    if (getline(inFile, line)) {
        stringstream ss(line);
        string dormName;
        while (ss >> dormName) {
            DormName.push_back(dormName);
        }
    } else {
        cerr << "Error: Empty file." << endl;
        inFile.close();
        return 1;
    }

    if (getline(inFile, line)) {
        stringstream ss(line);
        int channel;
        while (ss >> channel) {
            ChannelIDrecord.push_back(channel);
        }
    } else {
        cerr << "Error: Incomplete file." << endl;
        inFile.close();
        return 1;
    }

    if (getline(inFile, line)) {
        stringstream ss(line);
        int music;
        while (ss >> music) {
            MusicID.push_back(music);
        }
    } else {
        cerr << "Error: Incomplete file." << endl;
        inFile.close();
        return 1;
    }

    inFile.close();
    
    cout << "There are currently " << N << " inmates in " << M << " dorms" << endl;
    cout << "\nThe Present Inmates average Sleep times are:" << endl;
    for (int i = 0; i < N; i++) {
        cout<<left;
        cout <<setw(10)<< names[i] << ": ";
        times[i].printTime();
        cout << endl;
    }
    int Noofpeopleperdorm = N / M;
int RemainingNoofpeopleperdorm = N % M;
    
// vector<vector<int>> Dorms(M, vector<int>(Noofpeopleperdorm));
// Dorms[M][Noofpeopleperdorm];
// int dormIndex = 0;
// int storing = 0;

// // Allocate earpod IDs to Dorms[M][peopleperdorm]
// for (int i = 0; i < N; i++) {
//     Dorms[dormIndex][storing++] = earpodIDarray[i];
//     if (storing == Noofpeopleperdorm) {
//         dormIndex++;
//         storing = 0;
//     }
// }

    // // Allocate remaining earpod IDs if there are fewer people left than Noofpeopleperdorm
    // int Remainingpeopleleft = N - (Noofpeopleperdorm * M);
    // if (Remainingpeopleleft < RemainingNoofpeopleperdorm) {
    // for (int i = 0; i < M && Remainingpeopleleft < RemainingNoofpeopleperdorm; i++) {
    //     Dorms[i][Noofpeopleperdorm] = earpodIDarray[N - RemainingNoofpeopleperdorm + Remainingpeopleleft];
    //     Remainingpeopleleft++;
    // }
    // }
    // printNamesAndEarpodIDs(names, earpodIDarray, N);
    // int Dorms[M][Noofpeopleperdorm];
    // for(int i=0;i<N;i++){
    //     for(int j;j<N;j++){
            
    //     }
    // }
    int Dorm[M][Noofpeopleperdorm];
    int DormIDarray[sizeof(earpodIDarray)/sizeof(earpodIDarray[0])]; // Assuming DormIDarray has the same size as earpodIDarray

    // Initialize DormIDarray with -1
    for (int i = 0; i < sizeof(DormIDarray)/sizeof(DormIDarray[0]); ++i) {
        DormIDarray[i] = -1;
    }

    // Search for each earpodID in Dorm and store the dormitory index in DormIDarray
    for (int i = 0; i < sizeof(earpodIDarray)/sizeof(earpodIDarray[0]); ++i) {
        int earpodID = earpodIDarray[i];
        for (int j = 0; j < MAX_DORMS; ++j) {
            for (int k = 0; k < MAX_INMATES_PER_DORM; ++k) {
                if (Dorm[j][k] == earpodID) {
                    DormIDarray[i] = j;
                    break;
                }
            }
            if (DormIDarray[i] != -1) {
                break;
            }
        }
    }
    struct Record Records[N];
    MusicChannel ChannelControl[Channelsize];
    for (int i = 0; i < N; ++i) {
        Records[i].name = names[i];
        Records[i].EarpodID = earpodIDarray[i];
        Records[i].MusicID = musicIDarray[i];
        Records[i].Dorm = DormIDarray[i];
    }
    
    
    
    
    
    
    cout << "\nTime taken by each inmate to fall asleep are:" << endl;
    for (int i = 0; i < N; i++) {
        cout << setw(10)<<names[i] << ": " << Parray[i] << " minutes" << endl;
    }

    
    cout << "\nMusic for each inmate will Automatically stop at:" << endl;
    for (int i = 0; i < N; i++) {
        cout << setw(10)<<names[i] << ": ";
        Musicstop[i].check();
        
        Musicstop[i].printTime();
        cout << endl;
    }
    struct ChannelControl channels[numberofchannels];

bool musicPlaying[N] = {false};
bool musicStopped[N] = {true};
Time currentTime(20, 0);
Time PrevTime(19, 30);

while (currentTime.isWithinRange() && !(currentTime.hours == 23 && currentTime.minutes == 30)) {
    cout << "\nCurrently the time is: ";
    currentTime.printTime();
    cout << endl;

    bool musicStopped = true;

    for (int i = 0; i < N; i++) {
        if (musicPlaying[i] && currentTime >= Musicstop[i]) {
            cout << "Music has stopped playing for " << setw(10) << names[i] << " at ";
            Musicstop[i].printTime();
            cout << endl;
            musicPlaying[i] = false;

            // Free the channel
            for (int j = 0; j < numberofchannels; j++) {
                if (channels[j].occupied && channels[j].earpodID.size() > 0) {
                    for (int k = 0; k < channels[j].earpodID.size(); k++) {
                        if (channels[j].earpodID[k] == Records[i].EarpodID) {
                            channels[j].earpodID.erase(channels[j].earpodID.begin() + k);
                            if (channels[j].earpodID.empty()) {
                                channels[j].occupied = false;
                                cout << "Music Channel " << j + 10 << " has become free." << endl;
                            }
                            break;
                        }
                    }
                }
            }
        }

        if (!musicPlaying[i]) {
            musicStopped = false;
        }

        if (!musicPlaying[i] && currentTime >= times[i] && times[i] >= PrevTime) {
            bool sameDormMusicID = false;
            for (int j = 0; j < numberofchannels; j++) {
                if (channels[j].occupied && channels[j].dormIndex == Records[i].Dorm && channels[j].musicID == Records[i].MusicID) {
                    sameDormMusicID = true;
                    musicPlaying[i] = true;
                    channels[j].earpodID.push_back(Records[i].EarpodID);
                    cout << "Multiple People in same Dorm with same MusicID Detected!\n";
                    cout << "Music Channel " << j + 10 << " has also been allocated for EarpodID " << Records[i].EarpodID << " with MusicID " << Records[i].MusicID << endl;
                    break;
                }
            }
            if (!sameDormMusicID) {
                for (int j = 0; j < numberofchannels; j++) {
                    if (!channels[j].occupied) {
                        channels[j].occupied = true;
                        channels[j].dormIndex = Records[i].Dorm;
                        channels[j].musicID = Records[i].MusicID;
                        channels[j].earpodID.push_back(Records[i].EarpodID);
                        cout << "Music Channel " << j + 10 << " has been allocated for EarpodID " << Records[i].EarpodID << " with MusicID " << Records[i].MusicID << endl;
                        musicPlaying[i] = true;
                        break;
                    }
                }
            }
        }
        else if (musicPlaying[i] && Musicstop[i] >= currentTime) {
            cout << "Music is currently playing for " << setw(9) << names[i] << endl;
            musicStopped = false;
        }
    }

    if (musicStopped) {
        cout << "Music is not being played for anyone right now" << endl;
    }

    currentTime.incrementMinutes(incrementation);
    PrevTime.incrementMinutes(incrementation);
    cout << incrementation << " minutes have passed..." << endl;
}


    updateInmateRecords();
    cout << "Inmate records updated and saved to 'Inmate_records_updated.txt'." << endl;
    return 0;
}
