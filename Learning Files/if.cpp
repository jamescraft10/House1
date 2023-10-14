#include <iostream>

using namespace std;

int main() {
    cout << "Hello World!\n";
    // For A If Statement You Use Boolen Algebra
    // which is
    // >> << >= <= || && ! == !=
    if (20 > 18) {
        cout << "20 is greater than 18" << "\n";
    }

    if (18 > 20) {
        cout << "You Broke The World" << "\n";
    } else if (17 > 5) {
        cout << "17 is greater then 5" << "\n";
    }

    if (5 > 10) {
        cout << "You Broke The World" << "\n";
    } else {
        cout << "5 is greater then 10" << "\n";
    }
    // Short Hand
    // variable = (condition) ? expressionTrue : expressionFalse;
    //Switch Statement
    int day = 4;
    switch (day) {
    case 1:
        cout << "Monday";
        break;
    case 2:
        cout << "Tuesday";
        break;
    case 3:
        cout << "Wednesday";
        break;
    case 4:
        cout << "Thursday";
        break;
    case 5:
        cout << "Friday";
        break;
    case 6:
        cout << "Saturday";
        break;
    case 7:
        cout << "Sunday";
        break;
    default:
        cout << "The Day Number Does Not Exist";
    }
    return 0;
}