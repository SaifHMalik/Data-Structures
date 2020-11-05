#include <iostream>
#include <cmath>
#include "Equation.h"

using namespace std;
using namespace Eq;

void Quadratic::setEquation(double _a,double _b, double _c){
    a = _a;
    b = _b;
    c = _c;

    deter = (b*b) - (4*a*c);
}

void Quadratic::showEquation(){
    cout << a << "x^2 " << b << "x " << c << endl; 
}

void Quadratic::calculateEquation(){
    if(deter > 0){
        x1 = (-b + sqrt(b*b - (4*a*c)))/(2*a);
        x2 = (-b - sqrt(b*b - (4*a*c)))/(2*a);

        cout << "Root 1 X1 = " << x1 << endl;
        cout << "Root 2 X2 = " << x2;
    }

    else if (deter < 0){
        cout << "Root 1 X1 = " << (-b)/(2*a) << "," << sqrt((-deter))/(2*a) << "i" << endl;
        cout << "Root 2 X2 = " << (-b)/(2*a) << "," << -sqrt((-deter))/(2*a) << "i" << endl;
    }

    else{
        x1 = -b/(2*a);
        x2 = -b/(2*a);

        cout << "Root 1 X1 = " << x1 << endl;
        cout << "Root 2 X2 = " << x2;
    }
}
