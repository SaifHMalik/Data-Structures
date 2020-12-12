#include <iostream>
#include "string.h"
using namespace std;

class node
{
public:
    int data;
    string name;

    node *left;
    node *right;

public:
    node()
    {
        left = NULL;
        right = NULL;
    }

    node(int _data, string _name)
    {
        data = _data;
        name = _name;
        left = NULL;
        right = NULL;
    }

    void toString()
    {
        cout << name << " has the data " << data << endl;
    }
};

class BinarySearchTree
{
public:
    node *root;

public:
    void Insert(int _data, string _name)
    {

        node *newNode = new node(_data, _name);

        cout << newNode->name << "  " << newNode->data << endl;

        if (root == NULL)
        {

            root = newNode;
            return;
        }

        else
        {

            node *focusNode = root;

            node *parent;

            while (true)
            {

                parent = focusNode;

                if (_data < focusNode->data)
                {

                    focusNode = focusNode->left;

                    if (focusNode == NULL)
                    {

                        parent->left = newNode;
                        return;
                    }
                }

                else
                {

                    focusNode = focusNode->right;

                    if (focusNode == NULL)
                    {

                        parent->right = newNode;
                        return;
                    }
                }
            }
        }
    }

    void search(node *focusNode, int _data)
    {

        if (focusNode != NULL)
        {

            if (focusNode->data == _data)
            {
                cout << "Number is Present" << endl;
                return;
            }

            search(focusNode->left, _data);
            search(focusNode->right, _data);
        }
    }

    void preOrder_Traversal(node *focusNode)
    {
        if (focusNode != NULL)
        {
            cout << "Name: " << focusNode->name << endl;
            cout << "Data: " << focusNode->data << endl;
            preOrder_Traversal(focusNode->left);
            preOrder_Traversal(focusNode->right);
        }
    }

    void Inorder_Traversal(node *focusNode)
    {
        if (focusNode != NULL)
        {
            Inorder_Traversal(focusNode->left);
            cout << "Name: " << focusNode->name << endl;
            cout << "Data: " << focusNode->data << endl;
            Inorder_Traversal(focusNode->right);
        }
    }

    void Postorder_Traversal(node *focusNode)
    {
        if (focusNode != NULL)
        {
            Postorder_Traversal(focusNode->left);
            Postorder_Traversal(focusNode->right);
            cout << "Name: " << focusNode->name << endl;
            cout << "Data: " << focusNode->data << endl;
        }
    }

    node *getRoot()
    {
        return root;
    }
};

int main(void)
{

    BinarySearchTree *ob = new BinarySearchTree();

    ob->Insert(60, "CEO");
    ob->Insert(50, "Vice President");
    ob->Insert(40, "Primary Manager");
    ob->Insert(26, "Secondary Manager");
    ob->Insert(70, "Secretary");
    ob->Insert(80, "Salesman");

    ob->preOrder_Traversal(ob->getRoot());
    ob->Inorder_Traversal(ob->getRoot());
    ob->Postorder_Traversal(ob->getRoot());
    ob->search(ob->getRoot(), 26);
}