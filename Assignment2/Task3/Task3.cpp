/*
IDE: Visual Code 1.51.1
Compiler: g++ (MinGW.org GCC Build-20200227-1) 9.2.0g++ (MinGW.org GCC Build-20200227-1) 9.2.0
cppStandard: c++17
*/

#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

// Stack Max Size is defined which is 500 here
#define MAX 500

// Stack Class that will be used for implementation
class Stack
{
protected:
    // char Array myStack to store data
    char myStack[MAX];
    int top; // top variable to access the end of Stack

public:
    Stack()
    {
        top = -1;
    }

    // isStackFull Function to check whether Stack is Full or Not
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

    // isStackEmpty Function to check whether Stack is Empty or Not
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

    // push Fucntion to push element to end of Stack
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

    //lastElement Function to return last element in Stack
    char lastElement()
    {
        return myStack[top];
    }

    // pop Function to remove element from end of stack and return it.
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

    // display Function to dispaly the data stored in the Stack
    void display()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << "MyStack: " << myStack[i] << endl;
        }
    }

    // StackPosition Function to return the last position of myStack
    int StackPosition()
    {
        return top;
    }
};

int main(void)
{
    string expression;
    string postfix;
    string prefix;
    string reverseExpression;
    string tmp;
    Stack ob1;
    Stack ob;

    ifstream rsi("InputFile3.txt");

    if (rsi.is_open() == false)
    {
        cout << "No Input File Exist; Making New Input File Please Enter Input in InputFile3" << endl;
        ofstream wsi("InputFile3.txt");
        wsi.close();
    }

    rsi.close();

    ifstream is("InputFile3.txt");
    getline(is, expression);
    is.close();

    for (int i = 0; i < expression.length() - 1; i++)
    {
        if (expression[i] == ' ')
        {
            expression.erase(i, 1);
        }
    }

    // PREFIX Implementation
    for (int i = expression.length() - 1; i >= 0; i--)
    {
        reverseExpression += expression[i];
    }

    for (int i = 0; i < reverseExpression.length(); i++)
    {
        ob1.display();
        if ((reverseExpression[i] >= 'a' && reverseExpression[i] <= 'z') || (reverseExpression[i] >= 'A' && reverseExpression[i] <= 'Z') || (reverseExpression[i] >= '0' && reverseExpression[i] <= '9'))
        {
            prefix += reverseExpression[i];
        }

        else if (reverseExpression[i] == ')' || reverseExpression[i] == ']' || reverseExpression[i] == '}')
        {
            ob1.push(reverseExpression[i]);
        }

        else if (reverseExpression[i] == '(' || reverseExpression[i] == '[' || reverseExpression[i] == '{')
        {
            while (ob1.lastElement() != ')')
            {
                char ch = ob1.pop();
                prefix += ch;
            }
            ob1.pop();
        }

        else if (reverseExpression[i] == '^' || reverseExpression[i] == '*' || reverseExpression[i] == '/' || reverseExpression[i] == '+' || reverseExpression[i] == '-')
        {
            if (reverseExpression[i] == '^')
            {
                while (ob1.lastElement() == '^')
                {
                    prefix += ob1.pop();
                }
                ob1.push(reverseExpression[i]);
            }

            else if (reverseExpression[i] == '*' || reverseExpression[i] == '/')
            {
                while (ob1.lastElement() == '^')
                {
                    prefix += ob1.pop();
                }
                ob1.push(reverseExpression[i]);
            }

            else if (reverseExpression[i] == '+' || reverseExpression[i] == '-')
            {
                while (ob1.lastElement() == '^' || ob1.lastElement() == '*' || ob1.lastElement() == '/')
                {
                    prefix += ob1.pop();
                }
                ob1.push(reverseExpression[i]);
            }
        }
    }
    while (ob1.StackPosition() >= 0)
    {
        prefix += ob1.pop();
    }

    // POSTFIX Implementation
    for (int i = 0; i < expression.length(); i++)
    {
        ob.display();
        if ((expression[i] >= 'a' && expression[i] <= 'z') || (expression[i] >= 'A' && expression[i] <= 'Z') || (expression[i] >= '0' && expression[i] <= '9'))
        {
            postfix += expression[i];
        }

        else if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{')
        {
            ob.push(expression[i]);
        }

        else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}')
        {
            while (ob.lastElement() != '(')
            {
                char ch = ob.pop();
                postfix += ch;
            }
            ob.pop();
        }

        else if (expression[i] == '^' || expression[i] == '*' || expression[i] == '/' || expression[i] == '+' || expression[i] == '-')
        {
            if (expression[i] == '^')
            {
                while (ob.lastElement() == '^')
                {
                    postfix += ob.pop();
                }
                ob.push(expression[i]);
            }

            else if (expression[i] == '*' || expression[i] == '/')
            {
                while (ob.lastElement() == '^' || ob.lastElement() == '*' || ob.lastElement() == '/')
                {
                    postfix += ob.pop();
                }
                ob.push(expression[i]);
            }

            else if (expression[i] == '+' || expression[i] == '-')
            {
                while (ob.lastElement() == '^' || ob.lastElement() == '*' || ob.lastElement() == '/' || ob.lastElement() == '+' || ob.lastElement() == '-')
                {
                    postfix += ob.pop();
                }
                ob.push(expression[i]);
            }
        }
    }
    while (ob.StackPosition() >= 0)
    {
        postfix += ob.pop();
    }

    for (int i = prefix.length() - 1; i >= 0; i--)
    {
        tmp += prefix[i];
    }

    prefix = tmp;

    ofstream os("OutputFile3.txt");

    cout << "Prefix: " << prefix << endl;
    cout << "Postfix: " << postfix << endl;

    os << prefix << endl;
    os << postfix << endl;
}