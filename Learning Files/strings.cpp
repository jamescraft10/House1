#include <iostream>
//Use <string>
#include <string>

using namespace std;

int main() {
    string A = "Hello World!";
    cout << A << "\n";
    const string firstName = "James";
    const string lastName = "Czak";
    cout << firstName + " " + lastName << "\n";
    /*
    int x = 10;
    int y = 20;
    cout << x + y;
    Outputs 30
    ........
    string x = "10";
    string y = "20";
    cout << x + y;
    Outputs "1020"
    */
   //*******************************************
   //How to see Size
   string text = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
   cout << "The Size Of The String Is " << text.size() << "\n"; // or you can use text.length()
   //*******************************************
   string Hello = "Hello";
   Hello[0] = 'J'; // Outputs Jello Not Hello
   cout << Hello[0] << "\n";
   cout << Hello[1] << "\n";
   cout << Hello[2] << "\n";
   cout << Hello[3] << "\n";
   cout << Hello[4] << "\n";
   // what charter is in the area of single chars [0, 1, 2, 3, 4] does not start at 1 LUA
   //*******************************************
   //Special Characters
   // don't use \ " or '
   // use \\ \" and \'
   // you can also use \n(new line) \t(tab)
   cout << "\\ and \" and \' are good to \tuse" << "\n";
   //*******************************************
   //Better Input
   // All the input that you know is cin which only reads upto any spaces to read a full line do this
   string fullName;
   cout << "Whats Your  Full Name?" << "\n";
   getline(cin, fullName);
   cout << "Hello " << fullName << "!\n";
   //*******************************************
   //If You Do Not Use "using namespace std" as setup you need to print by doing this
   std::cout << fullName << "\n";
   return 0;
}