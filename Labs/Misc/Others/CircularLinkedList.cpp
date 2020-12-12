#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

class linked_list
{
protected:
    node *head, *tail;

public:
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }

    void addNode(int num)
    {
        node *tmp = new node;
        tmp->data = num;
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
};