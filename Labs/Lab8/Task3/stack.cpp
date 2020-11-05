#include <iostream>
#include "stack.h"
#include <string.h>

using namespace ST;
using namespace std;

Stack::Stack()
{
    top = -1;
}

// Stack::Stack(const Stack &rhs)
// {
//     this->top = rhs.top;

//     for (int i = 0; i <= top; i++)
//     {
//         this->myStack[i] = rhs.myStack[i];
//     }
// }

// Stack &Stack::operator=(Stack &rhs)
// {
//     if (this != rhs)
//     {
//         this->top = rhs.top;

//         for (int i = 0; i <= top; i++)
//         {
//             this->myStack[i] = rhs.myStack[i];
//         }
//     }
// }
template <class T>
bool Stack::push(T num)
{
    if (top >= MAX - 1)
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

bool Stack::isEmpty()
{
    if (top < 0)
    {
        return true;
    }

    return false;
}

string Stack::pop()
{
    if (isEmpty())
    {
        cout << "Stack Underflow" << endl;
        return NULL;
    }

    string item = myStack[top];
    myStack[top--] = ' ';
    return item;
}

bool Stack::isFull()
{
    if (top >= MAX - 1)
    {
        cout << "Stack Overflow" << endl;
        return true;
    }

    return false;
}

int Stack::getTop()
{
    return top;
}

template <class X>
bool Stack::operator==(X &rhs)
{
    if (this->top == rhs.top)
    {
        for (int i = 0; i <= top; i++)
        {
            if (this->myStack[i] != rhs.myStack[i])
            {
                return false;
            }
        }

        return true;
    }

    else
    {

        return false;
    }
}