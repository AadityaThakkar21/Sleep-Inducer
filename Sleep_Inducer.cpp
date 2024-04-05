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
