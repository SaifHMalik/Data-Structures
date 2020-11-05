#include <iostream>
#include "node.h"

using namespace std;
using namespace SLL;

linked_list::linked_list()
{
    head = NULL;
    tail = NULL;
}

void linked_list::add_node(double n)
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
    }
}

void linked_list::Display()
{
    node *tmp = head;

    while (tmp != NULL)
    {
        cout << "Node Element is: " << tmp->data << "," << endl;
        tmp = tmp->next;
    }
}



void linked_list::InsertionSort()
{
    if (head == NULL)
    {
        return;
    }

    node *tmp = head->next;
    node *tmp1;
    node *prev;
    node *tmp3;
    node *pNext;

    while (tmp != NULL)
    {
        tmp3 = tmp->next;
        tmp1 = head;
        prev = NULL;
        while (tmp1 != tmp)
        {
            if (tmp1->data > tmp->data)
            {
                break;
            }
            prev = tmp1;
            tmp1 = tmp1->next;
        }

        if (tmp1 != tmp)
        {

            pNext = tmp->next;
            if (prev != NULL)
            {
                prev->next = tmp;
            }

            else
            {
                head = tmp;
            }
            tmp->next = tmp1;
            while (tmp1->next != tmp)
            {
                tmp1 = tmp1->next;
            }
            tmp1->next = pNext;
        }
        tmp = tmp3;
    }
}
