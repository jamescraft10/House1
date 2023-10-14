#include <iostream>
#include <string>
using namespace std;

int main() {
    //Startup Text
    cout << "File Maker\n";
    cout << "What File Type Do You Want?\n";
    cout << "****Warrning You Must Have The Setup To Compile The Files Or Run Them****\n";
    cout << "1 For C\n";
    cout << "2 For C++\n";
    cout << "3 For C#\n";
    cout << "4 For HTML\n";
    cout << "5 For CSS\n";
    cout << "6 For JS\n";
    cout << "7 For PYTHON\n";
    cout << "8 For JAVA\n";

    //Input
    string Input = "";
    getline(cin, Input);

    //Which One It Is
    //variable = (condition) ? expressionTrue : expressionFalse;
    string afterPointName;
    if(Input == "1") {afterPointName = "c";}
    else if(Input == "2") {afterPointName = "cpp";}
    else if(Input == "3") {afterPointName = "cs";}
    else if(Input == "4") {afterPointName = "html";}
    else if(Input == "5") {afterPointName = "css";}
    else if(Input == "6") {afterPointName = "js";}
    else if(Input == "7") {afterPointName = "py";}
    else if(Input == "8") {afterPointName = "java";}
    else {cout << "Not A Number 1-8 Stopping Program.\n"; return 0;}

    // Continuing Text
    cout << "What Should Be The File Path Be?\n";
    cout << "(put name of file at the end like C:\\file.txt)\n";
    string fileName = "";
    getline(cin, fileName);
    cout << "\nIs" << "\"" << fileName << "." << afterPointName << "\" The Name You Want?\n";
    cout << "1 For Yes 2 For No\n";
    string YeNe = "";
    getline(cin, YeNe);
    if(YeNe == "1") {
        cout << "Creating File\n";
    } else if (YeNe == "2") {
        cout << "Ok Program Stopping Now.\n";
        return 0;
    } else {
        cout << "You Did Not Put A Number!\n";
        return 0;
    }
    return 0;
}