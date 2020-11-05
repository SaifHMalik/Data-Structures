#include <iostream>
#include <string.h>
using namespace std;

#define max 1000

class Stack
{

    int top;

public:
    int myStack[max];

    Stack()
    {
        top = -1;
    }

    bool push(int num)
    {
        if (top >= (max - 1))
        {
            cout << "Stack Overflow" << endl;
            return false;
        }
        else
        {
            myStack[++top] = num;
            return true;
        }
    }

    int pop()
    {
        if (top < 0)
        {
            cout << "Stack Underflow" << endl;
            return 0;
        }
        else
        {
            int item = myStack[top];
            myStack[top--] = NULL;
            return item;
        }
    }

    bool isEmpty()
    {
        if (top < 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main(void)
{

    int size;

    cout << "Enter Size";
    cin >> size;

    Stack ob;

    for (int i = 0; i < size; i++)
    {

        int num;
        cout << "Enter Number: ";
        cin >> num;
        if (num > 0)
        {

            if (num < 10 && (num % 6) != 0 && (num % 8) != 0 && (num % 9) != 0)
            {
                ob.push(num);
            }

            else if ((num % 2) != 0 && (num % 2) != 0 && (num % 3) != 0 && (num % 4) != 0 && (num % 5) != 0 && (num % 7) != 0)
            {
                ob.push(num);
            }
        }
    }

    for (int i = 0; i < size; i++)
    {
        cout << "Prime Numbers are: ";
        int number = ob.pop();
        if (number > 0)
        {
            cout << number << endl;
        }
    }
}