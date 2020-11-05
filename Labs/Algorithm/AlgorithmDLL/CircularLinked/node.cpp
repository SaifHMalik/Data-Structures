#include <iostream>
#include "node.h"

using namespace std;
using namespace SLL;

linked_list::linked_list()
{
    head = NULL;
    tail = NULL;
}

void linked_list::add_nodeCLL(double n)
{
    node *tmp = new node;

    tmp->data = n;
    tmp->next = NULL;

    if (head == NULL)
    {
        head = tmp;
        tail = tmp;
    }

    else
    {

        tail->next = tmp;
        tail = tail->next;
        tail->next = head;
    }
}

void linked_list::Display()
{
    node *tmp = head;

    while (tmp != tail)
    {
        cout << "Node Element is: " << tmp->data << "," << endl;
        tmp = tmp->next;
    }

    cout << "Node Element is: " << tmp->data << "," << endl;
}
