#include <iostream>
using namespace std;

int addTwoNumber(int A, int B) 
{ 
    return A + B; 
} 

int main()
{
    cout << "Hello World";
    int A;
    int B;
    cin >> A;
    cin >> B;
    cout << "sum = " << addTwoNumber(A, B); 
    return 0;
}
