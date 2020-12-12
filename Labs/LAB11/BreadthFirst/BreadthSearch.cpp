#include <iostream>
using namespace std;

#define MAX 100

class node
{
public:
    int data = NULL;

    node *left;
    node *right;

public:
    node()
    {
        left = NULL;
        right = NULL;
    }

    node(int _data)
    {
        data = _data;
        left = NULL;
        right = NULL;
    }
};

class Queue
{
protected:
    node *myQueue[MAX];
    int front, end;

public:
    Queue()
    {
        front = -1;
        end = -1;
    }

    bool isFull()
    {
        if (end == MAX - 1)
        {
            cout << "Queue is Full Unable to Enter New Nodes" << endl;
            return true;
        }

        else
        {
            return false;
        }
    }

    bool isEmpty()
    {
        if (front == -1)
        {
            cout << "Queue is Empty" << endl;
            return true;
        }

        else
        {
            return false;
        }
    }

    void enqueue(node *focusNode)
    {
        if (isFull())
        {
            return;
        }

        else
        {
            if (front == -1)
            {
                front = 0;
            }

            end++;
            myQueue[end] = focusNode;
        }
    }

    node *deQueue()
    {
        if (isEmpty())
        {
            return NULL;
        }

        else
        {
            node *returnNode = new node;
            returnNode = myQueue[front];
            myQueue[front] = NULL;
            front++;
            return returnNode;
        }
    }
};

class BinarySearchTree
{
public:
    node *root;

    void Insert(int _data)
    {
        node *newNode = new node(_data);

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

    void preOrder_Traversal(node *focusNode)
    {
        if (focusNode != NULL)
        {
            cout << "Data: " << focusNode->data << endl;
            preOrder_Traversal(focusNode->left);
            preOrder_Traversal(focusNode->right);
        }
    }

    node *getRoot()
    {
        return root;
    }

    void breadth_First_Searching(int _data)
    {
        Queue Qu;
        Qu.enqueue(root);
        while (!Qu.isEmpty())
        {
            node *focusNode = Qu.deQueue();
            if (focusNode->data == NULL)
            {
                cout << "Not Found" << endl;
                return;
            }
            cout << "FoucsNode->data: " << focusNode->data << endl;

            if (focusNode->data == _data)
            {
                cout << "Data Matched " << endl;
                return;
            }

            else
            {
                // cout << "3" << endl;

                if (focusNode->left != NULL)
                {
                    Qu.enqueue(focusNode->left);
                }

                if (focusNode->right != NULL)
                {
                    Qu.enqueue(focusNode->right);
                }
            }
        }

        cout << "Not Found" << endl;
    }
};

int main(void)
{
    BinarySearchTree *ob = new BinarySearchTree();
    ob->Insert(40);
    ob->Insert(35);
    ob->Insert(45);
    ob->Insert(50);
    ob->Insert(30);
    ob->Insert(25);
    ob->Insert(55);

    ob->preOrder_Traversal(ob->getRoot());

    ob->breadth_First_Searching(55);
}