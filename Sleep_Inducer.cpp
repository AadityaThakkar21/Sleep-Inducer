#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

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
