#include "stack.h"

using namespace ST;

Stack::Stack()
{
    top = -1;
}

bool Stack::isFull()
{
    if (top >= MAX - 1)
    {
        cout << "Stack is Full " << endl;
        return true;
    }

    else
    {
        return false;
    }
}

bool Stack::isEmpty()
{
    if (top == -1)
    {
        cout << "Stack is Empty" << endl;
        return true;
    }

    else
    {
        return false;
    }
}

void Stack::push(int num)
{
    if (isFull())
    {
        cout << "Stack is Full " << endl;
        return;
    }

    else
    {
        myStack[++top] = num;
    }
}

int Stack::pop()
{
    if (isEmpty())
    {
        cout << "Stack is Empty" << endl;
        return 0;
    }

    else
    {
        int value = myStack[top];
        top--;
        return value;
    }
}

void Stack::enQueue(Stack &s2, int num)
{
    while (!this->isEmpty())
    {
        s2.push(this->pop());
    }

    this->push(num);

    while (!s2.isEmpty())
    {
        this->push(s2.pop());
    }
}

int Stack::deQueue(Stack &s2)
{
    if (this->isEmpty())
    {
        cout << "Stack is Empty" << endl;
        return 0;
    }

    else
    {
        while (!this->isEmpty())
        {
            s2.push(this->pop());
        }

        int value = s2.pop();

        while (!s2.isEmpty())
        {
            this->push(s2.pop());
        }

        return value;
    }
}
