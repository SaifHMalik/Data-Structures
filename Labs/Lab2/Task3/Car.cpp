#include<iostream>
#include<string>
#include "Car.h"

using namespace std;
using namespace Cc;

void Car::setModel(string _model){
    model = _model;
}

void Car::setCarNumber(string _carNumber){
    carNumber = _carNumber;
}

void Car::setYearOfManufacture(int year){
    yearofManufacture = year;
}

void Car::Accelerate(){
    cout << "Accelerator used" <<endl;
}

void Car::useBrakes(){
    cout << "Breaks used" <<endl;
}

string Car::getModel(){return model;}
string Car::getcarNumber(){return carNumber;}
int Car::getYearofManufacture(){return yearofManufacture;}

Car::Car(){

}

Car::~Car(){
    model = "0";
    carNumber = "0";
    yearofManufacture = 0;
}

Car::Car(const Car& ob){
    model = ob.model;
    carNumber = ob.carNumber;
    yearofManufacture = ob.yearofManufacture;
}

Car& Car::operator=(const Car& ob){
    model = ob.model;
    carNumber = ob.carNumber;
    yearofManufacture = ob.yearofManufacture;

    return *this;
}

