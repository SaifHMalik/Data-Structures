#include <iostream>
#include<string>
using namespace std;

class Employee {
protected:
    string employeeId;
    int age;
    int experience;
    int workingHours;

public:
    void setEmployeeID(string _employeeId){employeeId = _employeeId;}
    void setAge(int _age){age = _age;}
    void setExperience(int _experience){experience = _experience;}
    void setWorkingHours(int _workingHours){workingHours = _workingHours;}

    string getEmplyeeID(){return employeeId;}
    int getAge(){return age;}
    int getExperience(){return experience;}
    int getWorkingHours(){return workingHours;}

};


int main(void){
    
    int num;
    string employeeId;
    int age;
    int experience;
    int workingHours;
    int wageRate;
    double salary;

    cout << "Enter Number of Employees: " << endl;
    cin >> num;

    Employee *Elist;
    Elist = new Employee[num];

    for(int i = 0; i < num; i++){
        cout << "Enter EmployeeID: " << endl;
        cin >> employeeId;
        cout << "Enter Age: " << endl;
        cin >> age;
        cout << "Enter Employee Experience: " << endl;
        cin >> experience;
        cout << "Enter Working Hours of Employee: " << endl;
        cin >> workingHours;
        Elist[i].setEmployeeID(employeeId);
        Elist[i].setAge(age);
        Elist[i].setExperience(experience);
        Elist[i].setWorkingHours(workingHours);

    }

    cout << endl << "Employees Salary:" << endl;

    for(int i = 0; i < num; i++){
        if(Elist[i].getAge() > 50 && Elist[i].getExperience() > 10 && Elist[i].getWorkingHours() > 240){
            salary = Elist[i].getWorkingHours() * 500;
            cout << "Salary of Employee: " << Elist[i].getEmplyeeID() << " is: " << salary << endl;
        }

        else if((Elist[i].getAge() <= 50 && Elist[i].getAge() > 40) && (Elist[i].getExperience() <= 10 && Elist[i].getExperience() > 6) && (Elist[i].getWorkingHours() > 200 && Elist[i].getWorkingHours() <= 240)){
            salary = Elist[i].getWorkingHours() * 425;
            cout << "Salary of Employee: " << Elist[i].getEmplyeeID() << " is: " << salary << endl;
        }

        else if((Elist[i].getAge() <= 40 && Elist[i].getAge() > 30) && (Elist[i].getExperience() <= 6 && Elist[i].getExperience() > 3) && (Elist[i].getWorkingHours() > 160 && Elist[i].getWorkingHours() <= 200)){
            salary = Elist[i].getWorkingHours() * 375;
            cout << "Salary of Employee: " << Elist[i].getEmplyeeID() << " is: " << salary << endl;
        }

        else if((Elist[i].getAge() <= 30 && Elist[i].getAge() > 22) && (Elist[i].getExperience() <= 3 && Elist[i].getExperience() > 1) && (Elist[i].getWorkingHours() > 120 && Elist[i].getWorkingHours() <= 160)){
            salary = Elist[i].getWorkingHours() * 300;
            cout << "Salary of Employee: " << Elist[i].getEmplyeeID() << " is: " << salary << endl;
        }

        else{
            cout << "Invalid Parameters: " << endl;
        }
    }
}