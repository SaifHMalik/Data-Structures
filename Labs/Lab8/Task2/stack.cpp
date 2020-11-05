#include <iostream>
#include "stack.h"
#include <string.h>

using namespace ST;
using namespace std;

Stack::Stack()
{
    top = -1;
}

bool Stack::push(char num)
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

char Stack::pop()
{

    char item = myStack[top];
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