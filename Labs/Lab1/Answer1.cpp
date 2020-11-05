#include <iostream>
#include<string>
using namespace std;

class Student{

protected:
    string name;
    int age;
    string rollNumber;

public:
    void setName(string _name){
        name = _name;
    }

    void setAge(int _age){
        age = _age;
    }

    void setRollNumber(string _rollNumber){
        rollNumber = _rollNumber;
    }

    string getName(){return name;}
    int getAge(){return age;}
    string getRollNumber(){return rollNumber;}

}; 


int main(void){
    string name;
    int age;
    string rollNumber;
    string temp1;
    int temp2;
    string temp3;



    Student *Slist;

    Slist = new Student[5];

    for(int i = 0; i < 5; i++){
        cout << "Enter Name" << endl;
        cin >> name;
        Slist[i].setName(name);

        cout << "Enter Age" << endl;
        cin >> age;
        Slist[i].setAge(age);

        cout << "Enter rollNumber" << endl;
        cin >> rollNumber;
        Slist[i].setRollNumber(rollNumber);

    }

    for(int i = 0; i < 5; i++){
        for(int j = i+1; j < 5; j++){
            if(Slist[j].getName() > Slist[i].getName()){
                temp1 = Slist[i].getName();
                temp2 = Slist[i].getAge();
                temp3 = Slist[i].getRollNumber();
                Slist[i].setName(Slist[j].getName());
                Slist[i].setAge(Slist[j].getAge());
                Slist[i].setRollNumber(Slist[j].getRollNumber());
                Slist[j].setName(temp1);
                Slist[j].setAge(temp2);
                Slist[j].setRollNumber(temp3);
            }
        }
    }

    cout << "In Descending Order: " << endl;

    for(int i = 0; i < 5; i++){
        cout << endl << "Name" << endl;
        cout << Slist[i].getName() << endl;

        cout << "Age" << endl;
        cout << Slist[i].getAge() << endl;

        cout << "rollNumber" << endl;
        cout << Slist[i].getRollNumber() << endl;

    }
}