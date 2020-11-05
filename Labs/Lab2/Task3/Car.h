#include<iostream>
#ifndef CAR_H
#define CAR_H

namespace Cc{

    class Car{
        private:
        std::string model;
        std::string carNumber;
        int yearofManufacture;

        public:
        Car();
        ~Car();
        Car(const Car& ob);
        void setModel(std::string _model);
        void setCarNumber(std::string _carNumber);
        void setYearOfManufacture(int year);
        void Accelerate();
        void useBrakes();

        std::string getModel();
        std::string getcarNumber();
        int getYearofManufacture();

        Car& operator=(const Car& ob);
    };
}

#endif