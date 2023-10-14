#include <iostream>

using namespace std;

int main() {
    cout << "Hello World!\n";

    // While Loop
    int i = 0;
    while (i < 5) {
        cout << i << " I \n";
        i++;
    }

    // Do While Loop
    int A = 5;
    do {
        cout << A << " A \n";
        A--;
    }
    while (A!=0);

    // For Loop
    for(int b = 0; b<=5; b++) {
        cout << b << " B \n";
    }

    // For Each Loop (Array)
    int myNumbers[5] = {10, 20, 30, 40, 50};
    for (int i : myNumbers) {
    cout << i << "\n";
    }
    // Break and Continue Works In Loops
    return 0;
}