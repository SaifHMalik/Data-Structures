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

void linked_list::SelectionSort()
{
    node *tmp1, *tmp2, *tmp3, *tmp4, *temporary;

    tmp1 = tmp2 = head;

    while (tmp2->next)
    {
        tmp3 = tmp4 = tmp2->next;

        while (tmp4)
        {
            if (tmp2->data > tmp4->data)
            {

                if (tmp2->next == tmp4)
                {

                    if (tmp2 == head)
                    {

                        tmp2->next = tmp4->next;
                        tmp4->next = tmp2;

                        temporary = tmp2;
                        tmp2 = tmp4;
                        tmp4 = temporary;
                        tmp3 = tmp4;
                        head = tmp2;

                        tmp4 = tmp4->next;
                    }

                    else
                    {

                        tmp2->next = tmp4->next;
                        tmp4->next = tmp2;
                        tmp1->next = tmp4;

                        temporary = tmp2;
                        tmp2 = tmp4;
                        tmp4 = temporary;

                        tmp3 = tmp4;

                        tmp4 = tmp4->next;
                    }
                }

                else
                {

                    if (tmp2 == head)
                    {

                        temporary = tmp2->next;
                        tmp2->next = tmp4->next;
                        tmp4->next = temporary;
                        tmp3->next = tmp2;

                        temporary = tmp2;
                        tmp2 = tmp4;
                        tmp4 = temporary;

                        tmp3 = tmp4;

                        tmp4 = tmp4->next;

                        head = tmp2;
                    }

                    else
                    {

                        temporary = tmp2->next;
                        tmp2->next = tmp4->next;
                        tmp4->next = temporary;
                        tmp3->next = tmp2;
                        tmp1->next = tmp4;

                        temporary = tmp2;
                        tmp2 = tmp4;
                        tmp4 = temporary;

                        tmp3 = tmp4;

                        tmp4 = tmp4->next;
                    }
                }
            }
            else
            {

                tmp3 = tmp4;
                tmp4 = tmp4->next;
            }
        }

        tmp1 = tmp2;
        tmp2 = tmp2->next;
    }
}