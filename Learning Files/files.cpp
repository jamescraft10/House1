#include <iostream>
#include <fstream> // To do anything with files do this

using namespace std;

int main() {
    cout << "Hello World!\n";
    // Create and open a text file
    ofstream MyFile("C:\\Users\\James\\Desktop\\C++\\Files\\file.cpp");

    // Write to the file
    MyFile << R""""(#include <iostream>
    using namespace std;
    int main() {
        cout << "Hello World!";
        return 0;
    }
    )"""";

    // Close the file
    MyFile.close();
}