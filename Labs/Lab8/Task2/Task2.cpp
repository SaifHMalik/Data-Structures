#include <iostream>
#include <string.h>
#include "stack.cpp"

using namespace std;

int main(void)
{
    string exp;
    Stack ob;

    cout << "Enter Expression" << endl;
    getline(cin, exp);

    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {

            ob.push(exp[i]);
        }
    }

    for (int i = 0; i < exp.length(); i++)
    {

        if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
        {
            ob.pop();
        }
    }

    if (ob.getTop() == -1)
    {
        cout << "Expression contains matching grouping Symbols" << endl;
    }
    else
    {
        cout << "Expression is Incorrect" << endl;
    }
}