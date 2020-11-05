#include <iostream>
#include "stack.cpp"
using namespace std;

int main(void)
{
    int size;
    string num;

    Stack ob1;
    Stack ob2;

    cout << "Enter Number of Elements" << endl;
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        cout << "Enter element of Stack 1: " << endl;
        cin >> num;

        ob1.push(num);

        cout << "Enter element of Stack 2: " << endl;
        cin >> num;

        ob2.push(num);
    }

    if (ob1 == ob2)
    {
        cout << "Stacks are Equal" << endl;
    }

    else
    {
        cout << "Stacks are not Equal" << endl;
    }
}
