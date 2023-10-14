#include <iostream>

using namespace std;

int main() {
    cout << "Hello World\n";
    string cars[5] = {"Ford", "BMW", "Joes Car", "Him"};
    cars[3] = "They";
    cout << cars[0] << "\n\n";
    cars[4] = "Car"; // Must Declare Size If You Want To Do This
    // Loop For Array
    for(string i : cars) {
        cout << i << "\n";
    }
    cout << sizeof(cars) << "\n"; // size of in bytes

    // Is Sizeof In Places
    int myNumbers[5] = {10, 20, 30, 40, 50};
    int getArrayLength = sizeof(myNumbers) / sizeof(int);
    cout << getArrayLength;
    // Multi-Dimensional Arrays
    string letters[2][4] = {
        { "A", "B", "C", "D" },
        { "E", "F", "G", "H" }
    };
    // Loop Though A 2D Array
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            cout << letters[i][j] << "\n";
        }
    }
    return 0;
}