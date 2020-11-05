#include<iostream>
#include "Car.cpp"
#include<string>


using namespace std;
using namespace Cc;


int main(void){
    std::string model;
    std::string carNumber;
    int yearOfManufacture;

    Car *Clist;
    Clist = new Car[2];

    cout << "Enter Car Model: " <<endl;
    cin >> model;
    Clist[0].setModel(model);

    cout << "Enter Car Number: " <<endl;
    cin >> carNumber;
    Clist[0].setCarNumber(carNumber);

    cout << "Enter Year Of Manufacture: " <<endl;
    cin >> yearOfManufacture;
    Clist[0].setYearOfManufacture(yearOfManufacture);
    
    cout << "Car 1 information: " <<endl;
    cout << "Car Model: " << Clist[0].getModel() << endl;
    cout << "Car Number: " << Clist[0].getcarNumber() << endl;
    cout << "Car Year of Manufacture: " << Clist[0].getYearofManufacture() << endl;
    Clist[0].Accelerate();
    Clist[0].useBrakes();

    Clist[1] = Clist[0]; // assignment operator 

    cout << "Car 2 information: " <<endl;
    cout << "Car Model: " << Clist[1].getModel() << endl;
    cout << "Car Number: " << Clist[1].getcarNumber() << endl;
    cout << "Car Year of Manufacture: " << Clist[1].getYearofManufacture() << endl;
    Clist[1].Accelerate();
    Clist[1].useBrakes();

    Car ob3 = Clist[0]; // copy constructor

    cout << "Car 3 information: " <<endl;
    cout << "Car Model: " << ob3.getModel() << endl;
    cout << "Car Number: " << ob3.getcarNumber() << endl;
    cout << "Car Year of Manufacture: " << ob3.getYearofManufacture() << endl;
    ob3.Accelerate();
    ob3.useBrakes();

    Clist[0].~Car(); // destructors
    Clist[1].~Car();
    ob3.~Car();

}