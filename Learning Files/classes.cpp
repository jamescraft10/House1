#include <iostream>
#include <string>

using namespace std;

class myClass {
    public:
    int myNum;
    string myString;

    void myMethod() { // Method/function defined inside the class
        cout << "Hello World!\n";
    }

    void mySecondMethod();

    myClass() {
        cout << "Hello World!\n";
    }
};

void myClass::mySecondMethod() {
    cout << "Goodbye World!";
}

int main() {
    cout << "Hello World!\n";
    //A Class Is A Something Like
    //A Car Which Contains Objects Like
    //Ford, Joes Car, Him, etc
    myClass myObj; //New Object Type That Class

    // Attributes
    myObj.myNum = 5;
    myObj.myString = "Jello";

    // Printing
    cout << myObj.myNum << "\n";
    cout << myObj.myString << "\n";

    // Object 2
    myClass myObj2;

    // Attributes
    myObj2.myNum = 7;
    myObj2.myString = "Hello";

    // Printing
    cout << myObj2.myNum << "\n";
    cout << myObj2.myString << "\n";
    myObj2.myMethod();
    myObj2.mySecondMethod();

    return 0;
}