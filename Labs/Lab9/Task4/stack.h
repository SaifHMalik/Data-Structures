#ifndef STACK_H
#define STACK_H
#include <iostream>

#define MAX 100

using namespace std;

namespace ST
{
    class Stack
    {
    protected:
        int myStack[MAX];
        int top;

    public:
        Stack();
        bool isFull();
        bool isEmpty();
        void push(int num);
        int pop();
        void enQueue(Stack &s2, int num);
        int deQueue(Stack &s2);
        void display();
    };
} // namespace ST