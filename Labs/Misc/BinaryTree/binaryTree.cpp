#include <iostream>
using namespace std;

// struct node
// {
//     int data;
//     node *left;
//     node *right;
// };

class BST
{
private:
    int data;
    BST *left, *right;

public:
    BST()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }

    BST(int value)
    {
        data = value;
        left = right = NULL;
    }

    BST *Insert(BST *root, int value)
    {
        if (!root)
        {
            return new BST(value);
        }

        if (value > root->data)
        {
            root->right = Insert(root->right, value);
        }

        else
        {
            root->left = Insert(root->left, value);
        }

        return root;
    }

    void Inorder(BST *root)
    {
        if (!root)
        {
            return;
        }

        Inorder(root->left);
        cout << "Data: " << root->data << endl;
        Inorder(root->right);
    }

    bool Search(BST *root, int num)
    {
        if (root->data == num)
        {
            return true;
        }

        if (root->right->data == num)
        {
            return true;
        }

        if (root->left->data == num)
        {
            return true;
        }

        Search(root->left, num);
        Search(root->right, num);

        return false;
    }
};

int main(void)
{
    BST b, *root = NULL;
    root = b.Insert(root, 50);
    b.Insert(root, 30);
    b.Insert(root, 20);
    b.Insert(root, 40);
    b.Insert(root, 70);
    b.Insert(root, 60);
    b.Insert(root, 80);

    b.Inorder(root);

    cout << "\n"
         << b.Search(root, 80) << endl;
}
