#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main()
{
    string input = "2*3/(2-1)+5*3", output = "", stack = "";
    string precedence = "-+/*^";
    for (int i = 0; i < input.length(); i++)
    {
        // cout << "Inside For " << endl;
        // if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z'))
        // {
        //     // cout << "If Alpha" << endl;
        //     output.push_back(input[i]);
        // }
        if (input[i] == '(')
        {
            // cout << "If (" << endl;
            stack.push_back(input[i]);
        }
        else if (input[i] == ')')
        {
            // cout << "If )" << endl;
            while (stack[stack.length() - 1] != '(')
            {
                // cout << "while !(" << endl;
                output.push_back(stack[stack.length() - 1]);
                stack.pop_back();
            }
            stack.pop_back();
        }
        else if (precedence.find(input[i]) >= 0 && precedence.find(input[i]) < precedence.length())
        {
            // if (stack.length() == 0 || stack[stack.length() - 1] == '(')
            // {
            //     stack.push_back(input[i]);
            // }
            // else
            // {
            // cout << "If Operator" << endl;
            if (stack.length() != 0 && floor(float(precedence.find(input[i])) / 2) <= floor(float(precedence.find(stack[stack.length() - 1])) / 2))
            {
                // output.push_back(stack[stack.length() - 1]);
                // stack.pop_back();
                // cout << "Operator Precedence >" << endl;
                while (stack.length() != 0 && floor(float(precedence.find(stack[stack.length() - 1])) / 2) >= floor(float(precedence.find(input[i])) / 2))
                {
                    output.push_back(stack[stack.length() - 1]);
                    stack.pop_back();
                }
                stack.push_back(input[i]);
                //     }
                // }
                // if(floor(float(precedence.find(input[i]))))
            }
            else
            {
                // cout << "asa" << endl;
                stack.push_back(input[i]);
            }
        }
        else
        {
            output.push_back(input[i]);
        }
        // cout << "Input:\t" << input << endl;
        cout << "Stack:\t" << stack << endl;
        cout << "Output:\t" << output << endl;

        // cout << floor(float(precedence.find('^')) / 2) << endl;
        // cout << floor(float(precedence.find('*')) / 2) << endl;
        // cout << floor(float(precedence.find('/')) / 2) << endl;
        // cout << floor(float(precedence.find('+')) / 2) << endl;
        // cout << floor(float(precedence.find('-')) / 2) << endl;
    }
    while (stack.length() != 0)
    {
        output.push_back(stack[stack.length() - 1]);
        stack.pop_back();
    }
    cout << "Input:\t" << input << endl;
    cout << "Stack:\t" << stack << endl;
    cout << "Output:\t" << output << endl;
}