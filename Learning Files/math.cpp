#include <iostream>
#include <cmath>

using namespace std;

int main() {
    cout << "Hello World!\n";
    int x = 5;
    int y = 7;
    // No Header File
    cout << max(x, y) << "\n"; //Prints Max Value
    cout << min(x, y) << "\n"; //Prints Min Value
    // With Header File
    cout << sqrt(64);
    cout << round(2.6);
    cout << log(2);
    // more functions for math at https://www.w3schools.com/cpp/cpp_math.asp
    return 0;
}