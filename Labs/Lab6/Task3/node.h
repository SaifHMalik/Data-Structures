#include<iostream>
#ifndef NODE_H
#define NODE_H

using namespace std;


namespace SLL{
    struct node{
        double data;
        node *next;
    };

    class linked_list{
        private:
            node *head,*tail;
        public:
            linked_list();
            void add_node(double n);
            void Display();
            void deleteNode();
            void insertNode(double n,int count);
    };
}

#endif