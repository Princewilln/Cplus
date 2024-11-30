#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
// class_tutorial.cpp : This file contains the 'main' function. Program execution begins and ends there.
//



/*class Test
{
public:
    int* p = new int;

    const Test& operator= (const Test& test)
    {
        if (this != &test)
            *p = *(test.p);
        return *this;
    }
           
};
void swap(int &d, int &e) {
    int temp = d;
    d = e;
    e = temp;

}*/

int main()
{
    int numStudents, numClasses;
    // Ask for number of students
    cout << "Enter the number of students: ";
    cin >> numStudents;

    // Ask for number of class meetings
    cout << "Enter the number of classes: ";
    cin >> numClasses;
    // Create dynamic arrays for student names and attendance
    string* studentNames = new string[numStudents];
    int* attendance = new int[numStudents];
    // Get the names of the students
    cout << "Enter the names of students:\n";
    for (int i = 0; i < numStudents; ++i) {
        cin >> studentNames[i];
    }
    // Get the attendance data
    cout << "Enter the number of days the students attended the class:\n";
    for (int i = 0; i < numStudents; ++i) {
        cin >> attendance[i];
    }
    // Output the attendance rates
    cout << "\nStudent Name     Attendance Rate\n";
    cout << "-------------------------------\n";
    for (int i = 0; i < numStudents; ++i) {
        double attendanceRate = (double)attendance[i] / numClasses * 100;
        cout << left << setw(15) << studentNames[i] << fixed << setprecision(2) << attendanceRate << "%" << endl;
    }
    // Clean up dynamically allocated memory
    delete[] studentNames;
    delete[] attendance;
    return 0;
}





/*int* scoreList; // Declares the pointer  scorelist to an integerand intialize it with a value 100
int size; // Declare tha variable size
cout << "Enter array size: ";
cin >> size;  // Read the size from the user
scoreList = new int[size];  // Dynamically allocate memory for the array

// Input elements into the array
for (int i = 0; i < size; i++) {
    int num;
    cout << "Enter element " << i << ": ";
    cin >> num;
    scoreList[i] = num;  // Assign the input value to the array
}

// Output the elements of the array
for (int i = 0; i < size; i++) {
    cout << "scoreList[" << i << "] is: " << scoreList[i] << endl;
}

// Free the allocated memory
delete[] scoreList;


/* const double PI = 3.1416;
 double* radius;

 cout << fixed << showpoint << setprecision(2);

 radius = new double;
 *radius = 3.2;

 cout << "Perimeter: " << 2 * PI * (*radius) << endl;
 cout << "Area: " << PI * (*radius) * (*radius) << endl;

 delete radius;*/


    /*  int* p;
    int* scoreList;
    int size;
    cout << "Enter array size: ";
    cin >> size;

    scoreList = new int[size];

    for (int i = 0; i < size; i++) {
        int num;
        cout << "Enter element " << i << ":" << endl;
        cin >> num;
        scoreList[i] = num;
        for (int i = num; i <= num; i++) {
           cout <<"scoreList[" << i - 1 << "] is: " << num << endl;
        }
        
    }
    delete[] scoreList;
    //int* p;
  // p = new int;
   // int num;
    //int hold = 4;
   //num = 30;
    
   //  p = &num;
    //*p = 7;
   // cout << "p: " << p << endl;
   // cout << "&num: " << &num << endl;
    //cout << "num: " << num << endl;
    //cout << *p << endl;
   // cout << "&p: " << &p << endl;
   // cout << hold << endl;



   // int a; 
   // a = 200;
   // cout << "a: " << a << endl;

    //int &b = a;
   // int &c = b;
    
    //c = 6;

   // cout << "a: " << a << endl;
   // cout << "b: " << b << endl;
   // cout << "c: " << c << endl;

    
    int d = 10, e = 20;

    
    cout << "d: " << d << endl;
    cout << "e: " << e << endl;

    swap(d, e);

   cout << "d: " << d << endl;
   cout << "e: " << e << endl;

    //string* str;
    //string weather;
   // weather = "sunny day";
    //str = &weather;
   // cout << str << endl;
    //str->length();
   // cout << *str << endl;
   // cout << weather.length() << endl;
    //cout << (*str).length() << endl;
    //cout << str->length() << endl;

    delete[] p;  */



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file */
