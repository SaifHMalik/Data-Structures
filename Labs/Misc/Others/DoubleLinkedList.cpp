#include <iostream>

using namespace std;

void insertPosition(int num, int size)
{
    node *tmp = new node;
    tmp = head;

    for (int i = 1; i <= size; i++)
    {
        tmp = tmp->next;
    }

    if (tmp == head)
    {
        node *newnode = new node;
        newnode->data = num;
        newnode->next = head;
        head = newnode;
        newnode->prev = NULL;
    }

    if (tmp == tail)
    {
        node *newnode = new node;
        newnode->data = num;
        nenode->next = NULL;
        newnode->prev = tail;
        tail = newnode;
    }

    if (tmp == NULL)
    {
        return;
    }

    node *newnode = new node;
    newnode->next = tmp->next;
    newnode->data = num;
    newnode->prev = tmp;
    tmp->next = newnode;
}

int main(void)
{
}