#include <iostream>
using namespace std;

class BST
{
    struct node
    {
        int data;
        node *left = NULL;
        node *right = NULL;
        int height;
    };

    node *root;

    void makeEmpty(node *t)
    {
        if (t == NULL)
        {
            return;
        }
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }

    node *insert(int x, node *t)
    {

        if (t == NULL)
        {

            t = new node;
            t->data = x;
            t->height = 0;
            t->left = t->right = NULL;
        }

        else if (x < t->data)
        {
            t->left = insert(x, t->left);

            if (height(t->left) - height(t->right) == 2)
            {

                if (x < t->left->data)
                {
                    t = singleRightRotate(t);
                }

                else
                {
                    t = doubleRightRotate(t);
                }
            }
        }

        else if (x > t->data)
        {
            t->right = insert(x, t->right);
            if (height(t->right) - height(t->left) == 2)
            {
                if (x > t->right->data)
                {
                    t = singleLeftRotate(t);
                }

                else
                {
                    t = doubleLeftRotate(t);
                }
            }
        }
        t->height = max(height(t->left), height(t->right)) + 1;
        return t;
    }

    node *
    singleRightRotate(node *t)
    {
        node *u = t->left;
        t->left = u->right;
        u->right = t;
        t->height = max(height(t->left), height(t->right)) + 1;
        u->height = max(height(u->left), t->height) + 1;
        return u;
    }

    node *singleLeftRotate(node *t)
    {
        node *u = t->right;
        t->right = u->left;
        u->left = t;
        t->height = max(height(t->left), height(t->right)) + 1;
        u->height = max(height(t->right), t->height) + 1;
        return u;
    }

    node *doubleLeftRotate(node *t)
    {
        t->right = singleRightRotate(t->right);
        return singleLeftRotate(t);
    }

    node *doubleRightRotate(node *t)
    {
        t->left = singleLeftRotate(t->left);
        return singleRightRotate(t);
    }

    node *findMin(node *t)
    {
        if (t == NULL)
        {
            return NULL;
        }

        else if (t->left == NULL)
        {
            return t;
        }

        else
        {
            return findMin(t->left);
        }
    }

    node *findMax(node *t)
    {
        if (t == NULL)
        {
            return NULL;
        }

        else if (t->right == NULL)
        {
            return t;
        }

        else
        {
            return findMax(t->right);
        }
    }

    node *remove(int x, node *t)
    {
        node *temp;

        if (t == NULL)
        {
            return NULL;
        }

        else if (x < t->data)
        {
            t->left = remove(x, t->left);
        }

        else if (x > t->data)
        {
            t->right = remove(x, t->right);
        }

        else if (t->left && t->right)
        {
            temp = findMin(t->right);
            t->data = temp->data;
            t->right = remove(t->data, t->right);
        }

        else
        {
            temp = t;
            if (t->left == NULL)
            {
                t = t->right;
            }

            else if (t->right == NULL)
            {
                t = t->left;
            }

            delete temp;
        }

        if (t == NULL)
        {
            return t;
        }

        t->height = max(height(t->left), height(t->right)) + 1;

        if (height(t->left) - height(t->right) == 2)
        {
            if (height(t->left->left) - height(t->left->right) == 1)
            {
                return singleLeftRotate(t);
            }

            else
            {
                return doubleLeftRotate(t);
            }
        }

        else if (height(t->right) - height(t->left) == 2)
        {

            if (height(t->right->right) - height(t->right->left) == 1)
            {
                return singleRightRotate(t);
            }

            else
            {
                return doubleRightRotate(t);
            }
        }
        return t;
    }

    int height(node *t)
    {
        //return (t == NULL ? -1 : t - &gt; height);
        if (t == NULL)
        {
            return -1;
        }

        else
        {
            return t->height;
        }
    }

    int getBalance(node *t)
    {
        if (t == NULL)
        {
            return 0;
        }

        else
        {
            return height(t->left) - height(t->right);
        }
    }

    void in_order(node *t)
    {

        if (t == NULL)
        {
            return;
        }

        in_order(t->left);
        cout << t->data << " ";
        in_order(t->right);
    }

public:
    BST()
    {
        root = NULL;
    }

    void insert(int x)
    {
        root = insert(x, root);
    }

    void remove(int x)
    {
        root = remove(x, root);
    }

    void display()
    {
        in_order(root);
        cout << endl;
    }
};

int main(void)
{
    BST t;
    t.insert(67);
    t.insert(43);
    t.insert(21);
    t.insert(10);
    t.insert(89);
    t.insert(38);
    t.insert(69);
    t.display();
    t.remove(89);
    t.remove(43);
    t.remove(88);
    t.remove(20);
    t.display();
}