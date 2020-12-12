#include <iostream>
using namespace std;

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

class BinaryTree
{
public:
    node *root;

public:
    void Insert_left(int _data)
    {

        node *newNode = new node(_data);
        if (root == NULL)
        {
            root = newNode;
            return;
        }

        else
        {
            node *foucusNode = new node;

            foucusNode = root;
            while (true)
            {

                if (foucusNode->left == NULL)
                {
                    foucusNode->left = newNode;
                    return;
                }
                foucusNode = foucusNode->left;
            }
        }
    }

    void Insert_right(int _data)
    {
        node *newNode = new node(_data);
        if (root == NULL)
        {
            root = newNode;
            return;
        }

        else
        {
            node *foucusNode = new node;
            foucusNode = root;
            while (true)
            {
                if (foucusNode->right == NULL)
                {
                    foucusNode->right = newNode;
                    return;
                }
                foucusNode = foucusNode->right;
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
};

int main(void)
{

    BinaryTree *ob = new BinaryTree();

    ob->Insert_left(50);
    ob->Insert_right(60);
    ob->Insert_left(35);
    ob->Insert_right(80);

    ob->preOrder_Traversal(ob->getRoot());
}