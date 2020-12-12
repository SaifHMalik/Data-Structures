#include <iostream>
using namespace std;

#define MAX 100

class node
{
public:
    int data;

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

class Stack
{
protected:
    node *myStack[MAX];
    int top = -1;

public:
    bool isFull()
    {
        if (top == MAX - 1)
        {
            cout << "Stack is FULL" << endl;
            return true;
        }

        else
        {
            return false;
        }
    }

    bool isEmpty()
    {
        if (top <= -1)
        {
            cout << "Stack is Empty" << endl;
            return true;
        }

        else
        {
            return false;
        }
    }

    void push(node *newNode)
    {
        if (isFull())
        {
            return;
        }

        else
        {
            //cout << "NewNode" << newNode->data << endl;
            top++;
            //cout << "Top " << top << endl;
            myStack[top] = newNode;
            //cout << "push: " << myStack[top] << endl;
        }
    }

    node *pop()
    {
        if (isEmpty())
        {
            return NULL;
        }

        else
        {
            node *returnNode = new node;
            returnNode = myStack[top];
            myStack[top] = NULL;
            top--;
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

    void depth_First_Searching(int _data)
    {
        Stack st;
        st.push(root);
        while (!st.isEmpty())
        {
            node *focusNode;
            focusNode = st.pop();

            cout << "FocusNode->data: " << focusNode->data << endl;

            if (focusNode->data == _data)
            {
                cout << "Data Found" << endl;
                return;
            }

            else
            {
                if (focusNode->left != NULL)
                {
                    st.push(focusNode->left);
                }

                if (focusNode->right != NULL)
                {
                    st.push(focusNode->right);
                };
            }
        }
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

    Stack st1;
    st1.push(ob->getRoot());
    cout << "Stack " << st1.pop() << endl;

    ob->preOrder_Traversal(ob->getRoot());

    ob->depth_First_Searching(25);
}