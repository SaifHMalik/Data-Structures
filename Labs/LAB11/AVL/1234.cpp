#include <iostream>
using namespace std;

class BST
{
    struct node
    {
        int data;
        node *left;
        node *right;
        int height;
    };
    node *root;
    void makeEmpty(node *t)
    {
        if (t == NULL)
            return;
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
                    t = singleRightRotate(t);
                else
                    t = doubleRightRotate(t);
            }
        }
        else if (x & gt; t->data)
        {
            t->right = insert(x, t->right);
            if (height(t->right) - height(t->left) == 2)
            {
                if (x & gt; t->right->data)
                    t = singleLeftRotate(t);
                else
                    t = doubleLeftRotate(t);
            }
        }
        t->height = max(height(t->left), height(t -
                                                    &gt;
                                                right)) +
                    1;
        return t;
    }
    node *singleRightRotate(node *t)
    {
        node *u = t->left;
        t->left = u->right;
        u->right = t;
        t->height = max(height(t->left), height(t -
                                                    &gt;
                                                right)) +
                    1;
        u->height = max(height(u->left), t->height) + 1;
        return u;
    }
    node *singleLeftRotate(node *t)
    {
        node *u = t->right;
        t->right = u->left;
        u->left = t;
        t->height = max(height(t->left), height(t -
                                                    &gt;
                                                right)) +
                    1;
        u->height = max(height(t->right), t -
                                              &gt;
                        height) +
                    1;
        return u;
    }
    node *doubleLeftRotate(node *t)
    {
        t->right = singleRightRotate(t->right);
        return singleLeftRotate(t);
    }
    node *doubleRightRotate(node *t)