#include <bits/stdc++.h>

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
    int Finalarr[N];
    generateRandomArray(Finalarr, N);
    updateInmateRecords(Finalarr, N);
    cout << "Inmate records updated and saved to 'Inmate_records_updated.txt'." << endl;
    return 0;
}
