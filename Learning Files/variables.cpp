#include <iostream>
#include <string> // To Use String Type Use This

using namespace std;

int main() {
    cout << "Hello World!\n";
    /*
    Variables I Use Them All The Time There Great :)
    Variable Types {
        int
        double
        char
        string
        bool
    }
    How To Declare
    type name = value;
    you can do "= value" if you want
    its not nessary
    */
   int A = 5; // Whole Number
   double B = 5.5; // Short String
   char C = '5'; // Single Char
   string D = "55"; // Useful Char (You need todo "#include <string>" to use it)
   bool E = true; // 1 or 2 (True or False)
   cout << A << "\n" << B << "\n" << C << "\n" << D << "\n" << E << "\n";
   //*********************************************************************
   // Declaring Mutible Variables At Once
   int F = 1, G, H = 3, I, J = 5, K, L = 7;

   // 1 Value Mutible Variables (Useless If You Do Something After)
   F = G = H = I = J = K = L = 15;
   cout << F << "\n" << G << "\n" << H << "\n" << I << "\n" << J << "\n" << K << "\n" << L << "\n";

   // Also A Type Is FloatIts A Bigger Double
   float M = 11.1;
   cout << M << "\n";

   // Name Your Variables Good
   string userOneName = "James Czak";

   // Conts
   // const type name = value;
   const string Name = "James Czak";
   // If You Try To Change It You Get A Error
   // Name = "Jams Good"
   // !!!!!!!!!!!!!! ERROR
   cout << Name << "\n" << userOneName;
   
   return 0;
}