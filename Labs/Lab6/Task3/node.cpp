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

void linked_list::deleteNode()
{
    node *tmp = head;

    if (head->next == head)
    {
        head = NULL;
        return;
    }

    head = head->next;
}

void linked_list::insertNode(double n, int count)
{
    node *tmp = head;
    node *tmp1;

    // while(count >= 0){
    //     tmp = tmp->next;
    //     count = count -1 ;
    // }

    tmp1->data = n;

    if (head == NULL)
    {
        head = tmp;
        tail = tmp;
    }

    else
    {

        for (int i = 0; i < count; i++)
        {
            tmp = tmp->next;
        }

        tmp1->next = tmp->next;
        tmp->next = tmp1;
    }
}


