#include <iostream>
#ifndef NODE_H
#define NODE_H

using namespace std;

namespace SLL
{
    struct node
    {
        double data;
        node *next;
        node *prev;
    };

    class linked_list
    {
    private:
        node *head, *tail;

    public:
        linked_list();
        void add_node(double n);
        void Traverse_Beginning();
        void Traverse_Ending();
        void insertAtBeginning(double num);
        void insertAtEnd(double num);
        void insertPosition(double num, int index);
        void deleteFromBeginning();
        void deleteFromEnd();
        void deletePosition(int index);
        void Display();
    };
} // namespace SLL

#endif