#include <iostream>
#include <string>

using namespace std;

int main() {
    string Word = "Hello";
    cout << "Guess The Word: ";
    string GuessedWord = "";
    cin >> GuessedWord;
    if(GuessedWord == Word) {
        cout << "\nCorrect";
    } else {
        cout << "\nWrong";
    }
    return 0;
}