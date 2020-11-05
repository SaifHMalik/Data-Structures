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

void linked_list::BubbleSort()
{
    node *temp = head;
    node *tmp1;
    node *tmp2;
    node *prev;
    int count = 0;

    if (head == NULL)
    {
        return;
    }

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    for (int i = 0; i < count; i++)
    {
        tmp1 = head;
        prev = NULL;
        while (tmp1->next != NULL)
        {
            tmp2 = tmp1->next;
            if (tmp1->data > tmp2->data)
            {
                tmp1->next = tmp2->next;
                tmp2->next = tmp1;
                if (prev == NULL)
                {
                    head = tmp2;
                }
                else
                {
                    prev->next = tmp2;
                }

                prev = tmp2;
            }

            else
            {
                prev = tmp1;
                tmp1 = tmp1->next;
            }
        }
    }
}