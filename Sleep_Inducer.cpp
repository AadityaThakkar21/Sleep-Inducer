#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function to generate a random float number between min and max
float randomFloat(float min, float max) {
    return min + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(max-min)));
}

// Function to generate a random int number between min and max
int randomInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

int main()
{
    int N; // Here N is the Number of Inmates
    cin >> N;

    int M; // Here M is the Number of sleeping dorms
    cin >> M;

    int Noofpeopleperdorm = N / M; // Here Noofpeopleperdorm is the Number of people living per dorm

    char UserRandomtaken;
    cout << "Do you want to randomize the sleep time of inmates? Enter Y/N: ";
    cin >> UserRandomtaken;

    if (UserRandomtaken == 'Y' || UserRandomtaken == 'y') {
        cout << "Sleep time will be randomized";
    }
    else if (UserRandomtaken == 'N' || UserRandomtaken == 'n') {
        cout << "Sleep time will not be randomized";
    }
    else {
        cout << "Irrelevant char entered by user";
    }

    return 0;
}
