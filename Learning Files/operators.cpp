#include <iostream>

using namespace std;

int main() {
    cout << "Hello World!\n";
    //Operators for example x+y these are the simple operators
    int x = 5;
    int y = 7;
    int z;
    z = x + y; // 5 + 7 = 12
    z = z - y; // 12 - 7 = 5
    z = z / x; // 5 / 5 = 1
    z = z * y; // 1 * 7 = 7
    z = z % x; // 7 % 5 = 2 7/5=1 R=2 R is what % counts
    z++; // 2 + 1 = 3
    z--; // 3 - 1 = 2
    z = z ^ x; // 2 ^ 5 = 32
    z+=x; // z = z + x this works for every operator even up coming ones
    z = x == y; // z = 0(false) because x does not equal y
    // more compairing operators is ==(equal) !=(not equal) >(greater then) <(less then) >=(greater then or equal to) <=(less then or equal to)
    // more logic is ||(or) &&(and) !(not)
    return 0;
}