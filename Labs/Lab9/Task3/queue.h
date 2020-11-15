#include <iostream>
#ifndef QUEUE_H
#define QUEUE_H

#define MAX 100

using namespace std;

namespace QUE
{
    class Queue
    {
    protected:
        int myQueue[MAX];
        int front, end;

    public:
        Queue();
        bool isFull();
        bool isEmpty();
        void enQueue(int num);
        int deQueue();
        void reverse();
        void display();
    };
} // namespace QUE

#endif