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
        string myStack[MAX];

        Stack();
        // Stack(const Stack &rhs);
        template <class T>
        bool push(T num);
        string pop();
        bool isEmpty();
        bool isFull();
        int getTop();
        template <class X>
        bool operator==(X &rhs);
        // Stack &operator=(Stack &rhs);
    };

} // namespace ST
#endif
