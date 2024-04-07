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


void generateRandomTime(Time& sleepTime) {
    sleepTime.set(randomInt(20, 22), randomInt(0, 59));
}

void allocateEarpods(int Dorm[MAX_DORMS][MAX_INMATES_PER_DORM], int EarpodIDarray[], int musicIDarray[], int peopleperdorm) {
    int musicIDInmates[MAX_DORMS][MAX_INMATES_PER_DORM] = {0};
    int remainderInmates[MAX_DORMS] = {0};
    int dormIndex = 0;

    for (size_t i = 0; i < MAX_DORMS; ++i) {
        for (size_t j = 0; j < MAX_INMATES_PER_DORM; ++j) {
            musicIDInmates[i][j] = -1;
        }
    }

    for (size_t i = 0; i < MAX_DORMS; ++i) {
        remainderInmates[i] = -1;
    }

    for (size_t i = 0; i < MAX_DORMS; ++i) {
        for (size_t j = 0; j < MAX_INMATES_PER_DORM; ++j) {
            Dorm[i][j] = -1;
        }
    }

    for (size_t i = 0; i < MAX_DORMS; ++i) {
        int earpodID = EarpodIDarray[i];
        int musicID = musicIDarray[i];

        bool filled = false;

        for (size_t j = 0; j < peopleperdorm; ++j) {
            if (musicIDInmates[musicID][j] == -1) {
                musicIDInmates[musicID][j] = earpodID;
                filled = true;
                break;
            }
        }

        if (!filled) {
            remainderInmates[dormIndex++] = earpodID;
        }
    }

    dormIndex = 0;

    for (size_t i = 0; i < MAX_DORMS; ++i) {
        for (size_t j = 0; j < peopleperdorm; ++j) {
            if (musicIDInmates[i][j] != -1) {
                Dorm[dormIndex][j] = musicIDInmates[i][j];
            }
        }
        ++dormIndex;
    }

    for (size_t i = 0; i < MAX_DORMS; ++i) {
        if (remainderInmates[i] != -1) {
            Dorm[dormIndex][0] = remainderInmates[i];
            ++dormIndex;
        }
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

void freeChannel(int channel) {
    cout << "Music Channel " << channel + 10 << " has become free." << endl;
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

void printNamesAndEarpodIDs(const string names[], const int earpodIDarray[], int N) {
    cout << "Here is the list of Names and their respective EarpodID:" << endl;
    for (int i = 0; i < N; i++) {
        cout << names[i] << ": " << earpodIDarray[i] << endl;
    }
}

int main() {
    int N, M, incrementation, peopleperdorm, numberofchannels;

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
    vector<vector<int>> Dorms(M, vector<int>(peopleperdorm));
    
    cout << "Enter number of channels:\n";
    cin >> numberofchannels;
    cout << "You have set " << numberofchannels << " channels." << endl;
    cin.ignore();
    
    vector<string> DormName;
    vector<int> ChannelIDrecord;
    int Channelsize = ChannelIDrecord.size();
    MusicChannel MusicChannels[Channelsize];
    vector<int> MusicID;
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
                    break;
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

Dorms[M][Noofpeopleperdorm];
int dormIndex = 0;
int storing = 0;

// Allocate earpod IDs to Dorms[M][peopleperdorm]
for (int i = 0; i < N; i++) {
    Dorms[dormIndex][storing++] = earpodIDarray[i];
    if (storing == Noofpeopleperdorm) {
        dormIndex++;
        storing = 0;
    }
}

    // Allocate remaining earpod IDs if there are fewer people left than Noofpeopleperdorm
    int Remainingpeopleleft = N - (Noofpeopleperdorm * M);
    if (Remainingpeopleleft < RemainingNoofpeopleperdorm) {
    for (int i = 0; i < M && Remainingpeopleleft < RemainingNoofpeopleperdorm; i++) {
        Dorms[i][Noofpeopleperdorm] = earpodIDarray[N - RemainingNoofpeopleperdorm + Remainingpeopleleft];
        Remainingpeopleleft++;
    }
    }
    printNamesAndEarpodIDs(names, earpodIDarray, N);
    
    // int Dorms[M][Noofpeopleperdorm];
    
    for(int i=0;i<N;i++){
        for(int j;j<N;j++){
            
        }
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

bool musicPlaying[N] = {false};
bool musicStopped[N] = {true};
Time currentTime(20, 0);
Time PrevTime(19, 30);

    while (currentTime.isWithinRange() && !currentTime.isMidnight()) {
        cout << "\nCurrently the time is:";
        currentTime.printTime();
        cout << endl;

        bool musicCurrentlyPlaying = false; // Flag to track if music is currently playing

        // Free channels if no EarpodID is using them
        for (int dorm = 0; dorm < M; dorm++) {
            for (int person = 0; person < peopleperdorm; person++) {
                if (ChannelID[dorm][person] != -1) {
                    // Check if EarpodID is still using the channel, if not free the channel
                    bool earpodIDUsingChannel = false;
                    for (int i = 0; i < N; i++) {
                        if (ChannelID[dorm][person] == i) {
                            earpodIDUsingChannel = true;
                            break;
                        }
                    }
                    if (!earpodIDUsingChannel) {
                        freeChannel(ChannelID[dorm][person]);
                        ChannelID[dorm][person] = -1; // Clear the channel allocation
                    }
                }
            }
        }

        for (int i = 0; i < N; i++) {
            // Check if music has stopped playing
            if (musicPlaying[i] && currentTime >= Musicstop[i]) {
                cout << "Music has stopped playing for " << setw(10) << names[i] << " at ";
                Musicstop[i].printTime();
                cout << endl;
                musicPlaying[i] = false;
                musicStopped[i] = true;

                // Free the music channel if no EarpodID is using it
                for (int j = 0; j < Channelsize; j++) {
                    for (int k = 0; k < peopleperdorm; k++) {
                        if (ChannelID[j][k] == i) {
                            freeChannel(j);
                            ChannelID[j][k] = -1; // Clear the channel allocation
                        }
                    }
                }
            }

            if (!musicPlaying[i]) {
                musicStopped[i] = false;
            }

            if ((currentTime >= times[i]) && (!musicPlaying[i]) && (times[i] >= PrevTime)) {
                cout << right;
                cout << "Music has started playing for " << setw(10) << names[i] << " at ";
                times[i].printTime();
                cout << endl;
                musicPlaying[i] = true;
                musicStopped[i] = false;
                musicCurrentlyPlaying = true; // Set the flag when music starts playing

                // Allocate a music channel dynamically
                for (int channel = 0; channel < Channelsize; channel++) {
                    bool channelEmpty = true;
                    for (int j = 0; j < peopleperdorm; j++) {
                        if (ChannelID[channel][j] != -1) {
                            channelEmpty = false;
                            break;
                        }
                    }
                    if (channelEmpty) {
                        ChannelID[channel][i % peopleperdorm] = i; // Allocate the channel to the dorm
                        cout << "Music Channel " << channel + 10 << " has been allocated for EarpodID " << earpodIDarray[i] << " with MusicID " << musicIDarray[i] << endl;
                        break;
                    }
                }
            } else if (musicPlaying[i] && (Musicstop[i] >= currentTime)) {
                cout << "Music is currently playing for " << setw(9) << names[i] << endl;
                musicCurrentlyPlaying = true; // Set the flag when music is playing
            }
        }

        int check = 0;
        for (int i = 0; i < N; i++) {
            if (musicStopped[i]) {
                check++;
            }
        }

        if (!musicCurrentlyPlaying) { // Print only when no music is currently playing
            cout << "Music is not being played for anyone right now" << endl;
            cout << "Currently No Music channels is being utilized" << endl;
        }

        currentTime.incrementMinutes(incrementation);
        PrevTime.incrementMinutes(incrementation);
        cout << incrementation << " minutes have passed..." << endl;
    }

    updateInmateRecords();
    cout << "Inmate records updated and saved to 'Inmate_records_updated.txt'." << endl;
    return 0;
}
