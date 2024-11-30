// inheritance_polymorphism.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
class Person {
public:
    string firstName;
    string lastName;

    void printName() {
        cout << firstName << " "  << lastName << endl;

    }
    void printID(int c){
        cout << " The studet or employee ID: " << c << endl;
    }
    void print() { cout << " I am in a base class " << endl; }
};

class Student : public Person {
public:
    int studentID;
    /*void printID() {
        cout << "Student ID: " << studentID << endl;
    }*/
    void print() { 
        Person::print();
        cout << " I am in a derive  class " << endl; }
};

class Employee : public Person {
public:
    int employeeID;
   /* void printID() {
        cout << "Employee ID: " << employeeID << endl;
    } */
};

int main()

{
    //Person person1;
    //person1.print();


    Student student1;
    student1.print();
    student1.firstName = "Princewill";
    student1.lastName = "Nwokeke";
    student1.studentID = 23;
    

    Employee employee1;
    employee1.firstName = "Jose";
    employee1.lastName = "Hernandez";
    employee1.employeeID = 26;




    student1.printName();
    student1.printID(student1.studentID); 

    employee1.printName();
    employee1.printID(employee1.employeeID); 

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
