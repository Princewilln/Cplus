#include <iostream>
#include "clockTypeImp.cpp"
#include "clockType.h"


using namespace std;

int main() {
    extClockType myClock(5, 10, 15, "CST");

    cout << "Time: ";
    myClock.printTime();
    cout << endl;

    return 0;
}