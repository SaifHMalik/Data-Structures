#include<iostream>
#include<string>
#include "Student.cpp"
#include "Array.cpp"

using namespace St;
using namespace A;
using namespace std;


int main(void){
    int size, cSize;
    string * cources = new string;
    string ID;
    string batch;
    string discipline;
    int expectedGY;

    cout << "Enter Number Of Students: ";
    cin >> size;

    // Student st1("1001");
    // st1.getID();
    
    //Student * Slist = new Student(size);
    Student * Slist = new Student[size];
    for(int i = 0; i < size; i++){
        cout << "\nStudent #" << (i+1) << ":\n" << "Student ID: ";
        cin >> ID;
        cout << "Enter Student Batch: ";
        cin >> batch;
        cout << "Enter Student Discipline: ";
        cin >> discipline;
        cout << "Enter Student Expected Graduation Year: ";
        cin >> expectedGY;
        cout << "Enter Number of Cources: ";
        cin >> cSize;
        cources = new string[cSize];
        cin.clear();
        cin.ignore();
        for(int j = 0; j < cSize; j++){
            cout << "Course #" << (j+1) << ": ";
            getline(cin, cources[j]);
        }
        Slist[i] = Student(ID, cources, cSize, batch, discipline, expectedGY);
    }

    Array arr(Slist, size);
    

    for(int k = 0; k <= size ; k++){
        cout << "Student # " << k+1;
        cout << "ID: " << arr[k].getID() << endl;
        cout << "Batch: " << arr[k].getBatch() << endl;
        cout << "Discipline" << arr[k].getDiscipline() << endl;
        cout << "Expected Graduation Year: " << arr[k].getExpectedGY() << endl;
        arr[k].showCurrentCources();
    }



}