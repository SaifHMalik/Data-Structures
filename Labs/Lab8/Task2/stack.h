#include <iostream>
#ifndef STACK_H
#define STACK_H

using namespace std;

#define MAX 1000

namespace ST
{
    class Stack
    {
        int top;

    public:
        char myStack[MAX];

        Stack();
        bool push(char num);
        char pop();
        bool isEmpty();
        bool isFull();
        int getTop();
    };

} // namespace ST
#endif
