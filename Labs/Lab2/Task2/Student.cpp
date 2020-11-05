#include <iostream>
#include <string>
#include "Student.h"

using namespace St;
using namespace std;

Student::Student(){
}

Student::Student(string _ID){
    ID = _ID;
}

void Student::setBatch(string _batch){
    batch = _batch;
}

void Student::setDiscipline(string _discipline){
    discipline = _discipline;
}

void Student::setExpectedGY(int _expectedGY){
    expectedGY = _expectedGY;
}

void Student::setCurrentCources(string *_cources, int _csize){
    cources = _cources;
    csize = _csize; 
}


Student::Student(string _ID,string * _cources, int _csize, string _batch, string _discipline, int _GY){
    ID = _ID;
    cources = _cources;
    csize = _csize;
    batch = _batch;
    discipline = _discipline;
    expectedGY = _GY;

}


void Student::setID(string _id){
    ID = _id;   
}

string Student::getID(){return ID;}
string Student::getBatch(){return batch;}
string Student::getDiscipline(){return discipline;}
int Student::getExpectedGY(){return expectedGY;}

void Student::showCurrentCources(){
    for(int i = 0; i < csize; i++){
        cout << "Cources Are: " << cources[i] << endl;
    }
}

