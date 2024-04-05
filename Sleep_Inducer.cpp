#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

using namespace std;

// Structure to store information about an inmate
struct Inmate {
    string name;
    string earpodID;
    vector<int> sleepTime;
    int fallAsleepTime;  // Time taken by the inmate to fall asleep in minutes
    bool asleep;  // Flag to indicate if the inmate is asleep
};

// Structure to store information about a dorm
struct Dorm {
    string name;
    vector<int> musicChannels;
    vector<vector<int>> musicPlaylist;  // Music playlist for each channel
    vector<Inmate*> assignedInmates;  // Inmates assigned to the dorm
};

// Function to read input data from a file
void readInputData(const string& filename, vector<Inmate>& inmates, vector<Dorm>& dorms) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        exit(1);
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string type;
        ss >> type;
        if (type == "Inmate") {
            Inmate inmate;
            ss >> inmate.name >> inmate.earpodID >> inmate.fallAsleepTime;
            for (int i = 0; i < 7; ++i) {
                int sleepTime;
                ss >> sleepTime;
                inmate.sleepTime.push_back(sleepTime);
            }
            inmates.push_back(inmate);
        } else if (type == "Dorm") {
            Dorm dorm;
            ss >> dorm.name;
            int numChannels;
            ss >> numChannels;
            for (int i = 0; i < numChannels; ++i) {
                int channel;
                ss >> channel;
                dorm.musicChannels.push_back(channel);
            }
            for (int i = 0; i < numChannels; ++i) {
                vector<int> playlist;
                int numSongs;
                ss >> numSongs;
                for (int j = 0; j < numSongs; ++j) {
                    int songID;
                    ss >> songID;
                    playlist.push_back(songID);
                }
                dorm.musicPlaylist.push_back(playlist);
            }
            dorms.push_back(dorm);
        }
    }

    file.close();
}

// Function to assign inmates to dorms
void assignInmatesToDorms(vector<Inmate>& inmates, vector<Dorm>& dorms) {
    srand(time(NULL));
    for (Inmate& inmate : inmates) {
        int dormIndex = rand() % dorms.size();
        dorms[dormIndex].assignedInmates.push_back(&inmate);
    }
}

// Function to play sleep-inducing music for inmates
void playMusic(vector<Dorm>& dorms, int p) {
    for (Dorm& dorm : dorms) {
        for (Inmate* inmate : dorm.assignedInmates) {
            if (!inmate->asleep) {
                // Assume music plays for p minutes
                cout << "Playing music for inmate " << inmate->name << " in dorm " << dorm.name << "..." << endl;
                sleep(p);  // Sleep for p seconds
                cout << "Stopping music for inmate " << inmate->name << " in dorm " << dorm.name << "." << endl;
                inmate->asleep = true;
            }
        }
    }
}
