#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    cout << "File Maker\n\n";
    cout << "What Type Of File Are You Making\n\n";
    cout << "Options Are C C++ HTML(With Css & Js Interinal Scripts)\n\n";
    cout << "1 For C, 2 For C++, 3 For HTML(With Css & Js Interinal Scripts)\n";
    string fileType = "";
    getline(cin, fileType);
    if(fileType == "1") {fileType = "c";}
    else if(fileType == "2") {fileType = "cpp";}
    else if(fileType == "3") {fileType = "html";}
    else {return 0;}
    cout << "\nWhats The File Name?\n";
    string fileName = "";
    getline(cin, fileName);
    string fullFile = fileName + "." + fileType;
    // Create and open a text file
    ofstream MyFile(fullFile);

    // Write to the file
    if(fileType == "c") {
        MyFile << "#include <stdio.h>\n\nint main() {\nprintf(\"Hello World!\");\n}";
    }
    if(fileType == "cpp") {
        MyFile << "#include <iostream>\nusing namespace std;\n\nint main() {\ncout << \"Hello World!\";\n}";
    }
    if(fileType == "html") {
        MyFile << "<!DOCTYPE html>\n<html lang=\"en\">\n<head>\n<meta charset=\"UTF-8\">\n<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n<title>Hello World</title>\n<style>\nbody {\nbackground-color: gray;\ncolor: aqua;\n}\n</style>\n</head>\n<body>\n<h1>Hello World</h1>\n<script>\nalert(\"Hello World!\");\n</script>\n</body>\n</html>";
    }

    // Close the file
    MyFile.close();
}