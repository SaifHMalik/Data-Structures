#include <iostream>
#include <string.h>
using namespace std;

#define MAX 500

class Stack
{
protected:
    char myStack[MAX];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    bool isStackFull()
    {
        if (top == MAX - 1)
        {
            cout << "Stack is Full" << endl;
            return true;
        }

        else
        {
            return false;
        }
    }

    bool isStackEmpty()
    {
        if (top <= -1)
        {
            cout << "Stack is Empty" << endl;
            return true;
        }

        else
        {
            return false;
        }
    }

    void push(char num)
    {
        if (isStackFull())
        {
            cout << "Stack is Full " << endl;
            return;
        }

        else
        {
            top++;
            myStack[top] = num;
        }
    }

    char lastElement()
    {
        return myStack[top];
    }

    char pop()
    {
        if (isStackEmpty())
        {
            cout << "Stack is Empty" << endl;
            return NULL;
        }

        else
        {
            char value = myStack[top];
            myStack[top] = NULL;
            top--;
            return value;
        }
    }

    void display()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << "MyStack: " << myStack[i] << endl;
        }
    }

    int StackPosition()
    {
        return top;
    }
};

int main(void)
{
    string expression;
    string postfix;
    Stack ob;
    int i;

    cout << "Enter infix Expression" << endl;
    cin >> expression;
    cout << "0" << endl;

    for (int i = 0; i < expression.length(); i++)
    {
        ob.display();
        cout << "1" << endl;
        if ((expression[i] >= 'a' && expression[i] <= 'z') || (expression[i] >= 'A' && expression[i] <= 'Z') || (expression[i] >= '0' && expression[i] <= '9'))
        {
            cout << "2" << endl;
            postfix += expression[i];
        }

        else if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{')
        {
            cout << "3" << endl;
            ob.push(expression[i]);
        }

        else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}')
        {
            cout << "4" << endl;
            while (ob.lastElement() != '(')
            {
                cout << "5" << endl;
                char ch = ob.pop();
                postfix += ch;
            }
            ob.pop();
        }

        else if (expression[i] == '^' || expression[i] == '*' || expression[i] == '/' || expression[i] == '+' || expression[i] == '-')
        {
            cout << "5" << endl;
            if (expression[i] == '^')
            {
                cout << "6" << endl;
                while (ob.lastElement() == '^')
                {
                    postfix += ob.pop();
                }
                ob.push(expression[i]);
            }

            else if (expression[i] == '*' || expression[i] == '/')
            {
                cout << "7" << endl;
                while (ob.lastElement() == '^' || ob.lastElement() == '*' || ob.lastElement() == '/')
                {
                    postfix += ob.pop();
                }
                ob.push(expression[i]);
            }

            else if (expression[i] == '+' || expression[i] == '-')
            {
                cout << "8" << endl;
                while (ob.lastElement() == '^' || ob.lastElement() == '*' || ob.lastElement() == '/' || ob.lastElement() == '+' || ob.lastElement() == '-')
                {
                    cout << "9" << endl;

                    // if (ob.StackPosition() <= -1)
                    // {
                    //     break;
                    // }
                    cout << "100" << endl;
                    postfix += ob.pop();
                }
                ob.push(expression[i]);
            }
        }
        cout << "10" << endl;
    }
    //cout << "11" << endl;
    while (ob.StackPosition() >= 0)
    {
        postfix += ob.pop();
    }
    cout << postfix << endl;
}