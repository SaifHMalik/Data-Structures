#include <iostream>
#include <string.h>
#include <fstream>
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

    // cout << "Enter infix Expression" << endl;
    //cin >> expression;

    for (int i = expression.length() - 1; i >= 0; i--)
    {
        reverseExpression += expression[i];
    }

    cout << reverseExpression << endl;

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

    ////////////////////////////////////////////////////////////////////////////////////////////// POSTFIX
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