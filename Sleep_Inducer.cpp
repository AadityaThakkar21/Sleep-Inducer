#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to generate a random int number between min and max
int randomInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

void generateRandomArray(int Finalarr[], int N) {
    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < N; ++i) {
        Finalarr[i] = randomInt(1, 100); // Change 100 to the desired maximum value for the array elements
    }
}

int main() {
    int N;
    cout << "Enter the number of elements for the array: ";
    cin >> N;

    int Finalarr[N];
    generateRandomArray(Finalarr, N);

    cout << "Random array generated with " << N << " elements:" << endl;
    for (int i = 0; i < N; ++i) {
        cout << Finalarr[i] << " ";
    }
    cout << endl;

    return 0;
}
