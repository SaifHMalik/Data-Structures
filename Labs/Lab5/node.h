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
    };

    class linked_list
    {
    private:
        node *head, *tail;

    public:
        linked_list();
        void add_node(double n);
        void average(linked_list *ob1, linked_list *ob2);
        void Display();
        void Swap(node *n1, node *n2);
        void getNode(int count);
    };
} // namespace SLL

#endif