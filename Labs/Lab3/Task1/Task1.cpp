#include<iostream>
#include"DynamicSafeArray.cpp"

using namespace std;
using namespace DSA;
using namespace OU;

int main(void){

    int num1;
    int num2;

    int val1;
    int val2;

    DynamicSafeArray ob;

    cout << "Enter Number of Elements of Ordered Dynamic Safe Array: ";
    cin >> val1;

    cout << "Enter Number of Elements of UnOrdered Dynamic Safe Array: ";
    cin >> val2;

    OrderdDSA ob1(val1);
    UnOrderedDSA ob2(val2);

    cout << "Enter Array Values for Ordered Dynamic Safe Array:";
    ob >> ob1;

    ob1.sort(); // If the Values entered by the user are unordered for Ordered DSA so in order to make sure the initial values of the array is sorted we use sort function

    ob << ob1;
    
    cout << "\nEnter Number to Insert: " <<endl;
    cin >> num1;

    ob1.insertion(num1);
    ob << ob1;

    cout << "\nEnter Number for searching: " <<endl; // searching starts from index 0
    cin >> num1;

    ob1.searching(num1);
    ob << ob1;

    cout << "\nEnter Array Values for UnOrdered Dynamic Safe Array:";
    ob >> ob2;
    ob << ob2;
    
    cout << "\nEnter Number to Insert: " <<endl;
    cin >> num2;

    ob2.insertion(num2);
    ob << ob2;

    cout << "\nEnter Number for searching: " <<endl;
    cin >> num2;

    ob2.searching(num2);
    ob << ob2;
}