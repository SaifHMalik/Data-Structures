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
    tmp->prev = NULL;

    if (head == NULL)
    {
        head = tmp;
        tail = tmp;
    }

    else
    {
        tmp->prev = tail;
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

void linked_list::Traverse_Beginning()
{
    if (head == NULL)
    {
        cout << "list is Empty" << endl;
    }

    else
    {
        node *tmp = head;
        while (tmp != NULL)
        {
            cout << "Data is: ";
            cout << tmp->data << endl;
            tmp = tmp->next;
        }
    }
}

void linked_list::Traverse_Ending()
{
    if (tail == NULL)
    {
        cout << "List is Empty" << endl;
    }

    else
    {
        node *tmp = tail;
        while (tmp != NULL)
        {
            cout << "Data is: ";
            cout << tmp->data << endl;
            tmp = tmp->prev;
        }
    }
}

void linked_list::insertAtBeginning(double num)
{
    node *tmp = new node;

    if (tmp == NULL)
    {
        cout << "Unable to allocate Memory" << endl;
    }
    else
    {
        tmp->data = num;
        tmp->prev = NULL;
        tmp->next = head;

        head->prev = tmp;
        head = tmp;
        cout << "Node Succesfully added to beginning of the List" << endl;
    }
}

void linked_list::insertAtEnd(double num)
{
    node *tmp = new node;

    if (tmp == NULL)
    {
        cout << "unable to Allocate Memory" << endl;
    }

    else
    {
        tmp->data = num;
        tmp->next = NULL;
        tmp->prev = tail;

        tail->next = tmp;
        tail = tmp;
        cout << "Node Succesfully added to END of the List" << endl;
    }
}

void linked_list::insertPosition(double num, int index)
{
    node *tmp = head;
    for (int i = 1; i < index - 1; i++)
    {
        if (tmp == NULL)
        {
            break;
        }
        tmp = tmp->next;
    }

    if (index == 1)
    {
        insertAtBeginning(num);
    }

    else if (tmp == tail)
    {
        insertAtEnd(num);
    }

    else if (tmp != NULL)
    {
        node *newNode = new node;

        newNode->data = num;
        newNode->next = tmp->next;
        newNode->prev = tmp;

        if (tmp->next != NULL)
        {
            tmp->next = newNode;
        }
        cout << "Node Added Succesfully" << endl;
    }
}

void linked_list::deleteFromBeginning()
{
    if (head == NULL)
    {
        return;
    }

    if (head == tail)
    {
        node *toDelete = head;
        head = NULL;
        tail = NULL;
        delete toDelete;
    }

    else
    {
        node *toDelete = head;
        head = head->next;
        head->prev = NULL;
        delete toDelete;
    }
}

void linked_list::deleteFromEnd()
{
    if (tail == NULL)
    {
        cout << "Canot delete from an Empty List" << endl;
    }

    else
    {
        node *toDelete = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete toDelete;
        cout << "Succesfully deleted from End" << endl;
    }
}

void linked_list::deletePosition(int index)
{
    node *current = head;

    for (int i = 1; i < index && current != NULL; i++)
    {
        current = current->next;
    }

    if (index == 1)
    {
        deleteFromBeginning();
    }

    else if (current == tail)
    {
        deleteFromEnd();
    }

    else if (current != NULL)
    {
        current->prev->next = current->next;

        if (current->next != NULL)
        {
            current->next->prev = current->prev;
        }
        delete current;
        cout << "Node Deleted from: " << index << "position" << endl;
    }
}