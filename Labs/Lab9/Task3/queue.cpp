#include "queue.h"

using namespace QUE;

Queue::Queue()
{
    front = -1;
    end = -1;
}

bool Queue::isFull()
{
    if (front == MAX - 1)
    {
        cout << "QUEUE is FULL" << endl;
        return true;
    }
    else
    {
        return false;
    }
}

bool Queue::isEmpty()
{
    if (front == -1)
    {
        cout << "QUEUE is Empty " << endl;
        return true;
    }

    else
    {
        return false;
    }
}

void Queue::enQueue(int num)
{
    if (isFull())
    {
        cout << "QUEUE is Full" << endl;
        return;
    }

    else
    {
        if (front == -1)
        {
            front = 0;
        }

        end++;
        myQueue[end] = num;
    }
}

int Queue::deQueue()
{
    if (isEmpty())
    {
        cout << "Queue is Empty" << endl;
        return 0;
    }

    else
    {
        int value;
        value = myQueue[front];
        myQueue[front] = 0;
        front++;
        return value;
    }
}

void Queue::reverse()
{
    if (isEmpty())
    {
        cout << "Queue is Empty" << endl;
        return;
    }

    int revarray[end];

    for (int i = 0; i <= end; i++)
    {
        revarray[end - i] = myQueue[i];
    }

    for (int i = 0; i <= end; i++)
    {
        myQueue[i] = revarray[i];
    }
}

void Queue::display()
{
    for (int i = 0; i <= end; i++)
    {
        cout << "Data: " << myQueue[i] << endl;
    }
}