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
        cout << "10" << endl;
        if (t == NULL)
        {
            return;
        }
        cout << "11" << endl;
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
        cout << "12" << endl;
    }

    node *insert(int x, node *t)
    {
        cout << "13" << endl;
        if (t == NULL)
        {
            cout << "13" << endl;
            t = new node;
            t->data = x;
            t->height = 0;
            t->left = t->right = NULL;
            cout << "14" << endl;
        }

        else if (x < t->data)
        {
            cout << "15" << endl;
            t->left = insert(x, t->left);

            if (height(t->left) - height(t->right) == 2)
            {
                cout << "16" << endl;
                if (x < t->left->data)
                {
                    cout << "17" << endl;
                    t = singleRightRotate(t);
                }

                else
                {
                    cout << "17" << endl;
                    t = doubleRightRotate(t);
                }
            }
        }

        else if (x > t->data)
        {
            cout << "18" << endl;
            t->right = insert(x, t->right);

            cout << "19" << endl;
            if (height(t->right) - height(t->left))
            {
                cout << "20" << endl;
                if (x > t->right->data)
                {
                    cout << "21" << endl;
                    t = singleLeftRotate(t);
                }

                else
                {
                    cout << "22" << endl;
                    t = doubleLeftRotate(t);
                }
            }
        }
        cout << "23" << endl;
        t->height = max(height(t->left), height(t->right)) + 1;
        return t;
    }

    node *singleRightRotate(node *t)
    {
        cout << "24" << endl;
        node *u = t->left;
        cout << "150" << endl;
        t->left = u->right;
        cout << "31" << endl;
        u->right = t;
        cout << "200" << endl;
        t->height = max(height(t->left), height(t->right)) + 1;
        u->height = max(height(u->left), t->height) + 1;
        cout << "25" << endl;
        return u;
    }

    node *singleLeftRotate(node *t)
    {
        cout << "26" << endl;
        node *u = t->right;
        t->right = u->left;
        u->left = t;
        t->height = max(height(t->left), height(t->right)) + 1;
        u->height = max(height(t->right), t->height) + 1;
        return u;
        cout << "27" << endl;
    }

    node *doubleLeftRotate(node *t)
    {
        cout << "28" << endl;
        t->right = singleRightRotate(t->right);
        return singleLeftRotate(t);
    }

    node *doubleRightRotate(node *t)
    {
        cout << "29" << endl;
        t->left = singleLeftRotate(t->left);
        return singleRightRotate(t);
    }

    node *findMin(node *t)
    {
        cout << "30" << endl;
        if (t == NULL)
        {
            cout << "31" << endl;
            return NULL;
        }

        else if (t->left == NULL)
        {
            cout << "32" << endl;
            return t;
        }

        else
        {
            cout << "33" << endl;
            return findMin(t->left);
        }
    }

    node *findMax(node *t)
    {
        cout << "34" << endl;
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
        cout << "1" << endl;
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