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

void linked_list::GetNth(linked_list *ob, int index, int size)
{

    node *tmp = ob->head;

    if (index < 0 || index >= size)
    {
        cout << "Error Index out of Range" << endl;
        return;
    }

    while (index != 0)
    {
        if (tmp == NULL)
        {
            cout << "Index not Found" << endl;
            return;
        }

        tmp = tmp->next;
        index = index - 1;
    }

    cout << "The Value Stored in the Node is: ";
    cout << tmp->data << endl;
}

// void linked_list::BubbleSort()
// {
//     int count = 0;
//     node *tmp = head;

//     while (tmp != NULL)
//     {
//         count = count + 1;
//         //cout << "0";
//         tmp = tmp->next;
//     }

//     tmp = head;

//     while (tmp->next != NULL)
//     {
//         for (int i = 0; i < count; i++)
//         {
//             if (tmp->data > tmp->next->data)
//             {
//                 swap(tmp->data, tmp->next->data);
//             }
//         }

//         tmp = tmp->next;
//     }
// }
