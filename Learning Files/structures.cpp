#include <iostream>

using namespace std;

struct {
  int myNum;
  string myString;
} myStructure;

struct {
  string brand;
  string model;
  int year;
} myCar1, myCar2; // We can add variables by separating them with a comma here

struct myDataType { // This structure is named "myDataType"
  int myNum;
  string myString;
};

int main() {
    cout << "Hello World!\n";
    myStructure.myNum = 15;
    cout << myStructure.myNum << "\n";
    //Example of things
    // Put data into the first structure
    myCar1.brand = "BMW";
    myCar1.model = "X5";
    myCar1.year = 1999;

    // Put data into the second structure
    myCar2.brand = "Ford";
    myCar2.model = "Mustang";
    myCar2.year = 1969;

    // Print the structure members
    cout << myCar1.brand << " " << myCar1.model << " " << myCar1.year << "\n";
    cout << myCar2.brand << " " << myCar2.model << " " << myCar2.year << "\n";
    // New Data Type
    myDataType myVar;
    myVar.myNum = 5;
    myVar.myString = "H\n";
    cout << myVar.myNum << "\n";
    cout << myVar.myString << "\n";
}