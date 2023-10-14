#include <iostream>
#include <string>

using namespace std;

int main() {
    cout << "Hello World!\n";
    //References
    int cubes = 5;
    int &objects = cubes;

    cout << "There Are " << cubes << " Cubes!\n";
    cout << "There Are " << objects << " Objects!\n\n";
    //Memory Address
    string food = "Pizza\n";

    cout << &food << "\n"; //Outputs The Memory Address Of The Food
    //You Get The Address With The & Operator And You Can Use It For
    //References To

    /*References and Pointersare important in C++, 
    because they give you the ability to manipulate the data in the computer's memory - 
    which can reduce the code and improve the performance.
   */

    //Pointers
    string pizza = "Pizza\n"; // A food variable of type string

    cout << pizza;  // Outputs the value of food (Pizza)
    cout << &pizza; // Outputs the memory address of pizza

    //A pointer however, is a variable that stores the memory address as its value.

    string* ptr = &pizza; //This Stores The Address Of pizza
    cout << ptr << "\n";
    cout << *ptr << "\n"; //Output food With The Pointer

    *ptr = "Hamburger";

    cout << *ptr << "\n";
    cout << ptr << "\n";
}