#include<iostream>
#include "Equation.cpp"

using namespace std;
using namespace Eq;

int main(void){
    double a,b,c;

    Quadratic QE;

    cout << "Enter value for 'x^2': " << endl;
    cin >> a;

    cout << "Enter value for 'x': " << endl;
    cin >> b;

    cout << "Enter value for constant: " << endl;
    cin >> c;

    QE.setEquation(a,b,c);

    cout << "The Equation you have Entered is: " <<endl;
    QE.showEquation();

    QE.calculateEquation();
}