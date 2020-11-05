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

void linked_list::average(linked_list *ob1, linked_list *ob2)
{

    double sum = 0;
    double avg = 0;
    static int j = 0;

    node *tmp1 = ob1->head;
    //node *tmp2 = ob2->head;

    for (int i = 0; i < j; i++)
    {
        tmp1 = tmp1->next;
    }

    for (int k = 0; k < 4; k++)
    {
        sum = sum + tmp1->data;
        tmp1 = tmp1->next;
    }

    avg = (sum / 4);

    ob2->add_node(avg);
    j++;

    if (tmp1 == NULL)
    {
        return;
    }

    average(ob1, ob2);
}
