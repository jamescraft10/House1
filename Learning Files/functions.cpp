#include <iostream>
#include <string>

using namespace std;

void myFunction() { //void means no return value and myFunction is name so the syntax is type name() {}
    cout << "Goodbye World!\n";
}

void secondFunction();

void parameters(string name = "Not A Name");

void mutibleParameters(string name, int age);

int returnVaule(int number); //Use the type you want to return not "void"

int main() {
    cout << "Hello World!\n";
    myFunction(); // Order of code matters, if you put the function after the main function it does not work.
    // Unless if you Declare a function then make what it means latter like in secondFunction()
    secondFunction();
    //Parameters
    parameters("Joe");
    parameters("John");
    parameters("James");
    parameters(); // Prints "Not A Name" because nothing is in it
    mutibleParameters("Joe", 18);
    mutibleParameters("John", 19);
    mutibleParameters("James", 17);
    // With Return
    cout << returnVaule(5) << "\n";
    //You Can Also Do References Etc
    //You Can Also Put Arrays In Functions
    //Function Overloading Don't Make Functions Have The Same Name As Each Other
    //Its A Bad Practise And Leads To Alot Of Errors
    //Do Not Put Functions Inside Of Functions (Its Could Act Like A Loop If You Put A If Statement And Other Things But Put A Loop)
    //(Then Not A Function)
    return 0;
}

void secondFunction() {
    cout << "Hello Again World!\n";
}

void parameters(string name) {
    cout << name << "\n";
}

void mutibleParameters(string name, int age) {
    cout << "Name: " << name << " Age: " << age << "\n";
}

int returnVaule(int number) {
    number++;
    return number; // Returns value
}