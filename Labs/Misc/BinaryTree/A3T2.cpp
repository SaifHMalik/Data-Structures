#include <iostream>
#include <vector>
using namespace std;

class node
{
public:
    int data;

    node *left;
    node *right;

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

class BinarySearchTree
{
public:
    node *root;
    vector<int> sum;
    vector<int> path;

public:
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

    // void Sum_Paths(node *focusNode)
    // {
    //     static int i;
    //     if (focusNode != NULL)
    //     {
    //         if (sum.size() == 0)
    //         {
    //             sum.push_back(0);
    //         }

    //         cout << "Data: " << focusNode->data << "\t" << sum.size() << endl;
    //         sum[i] += focusNode->data;

    //         if ((focusNode->right == NULL && focusNode->left == NULL))
    //         {
    //             cout << "1" << endl;
    //             sum.push_back(0);
    //             i++;
    //         }
    //         Sum_Paths(focusNode->left);
    //         Sum_Paths(focusNode->right);
    //     }
    // }

    void Sum_Paths(node *focusNode)
    {
        if (focusNode != NULL)
        {
            // cout << "\nfocusNodes: " << focusNode->right << " " << focusNode->left << " " << focusNode->data << endl;
            if ((focusNode->right == 0 && focusNode->left == 0))
            {
                path.push_back(focusNode->data);
                cout << "\nPath: ";
                for (int i = 0; i < path.size(); i++)
                {
                    cout << path[i] << " ";
                }
                // cout << "\n\nEND\n\n";
                int var = 0;
                // cout << "Var\t";
                for (int i = 0; i < path.size(); i++)
                {
                    var += path[i];
                    // cout << path[i] << "<P V>" << var;
                }
                // cout << endl;
                sum.push_back(var);
                path.pop_back();
                cout << endl;
            }
            cout << "\n focus L: " << focusNode->data;
            path.push_back(focusNode->data);
            Sum_Paths(focusNode->left);
            // path.push_back(focusNode->data);
            path.pop_back();
            path.push_back(focusNode->data);
            cout << " focus R: " << focusNode->data;
            Sum_Paths(focusNode->right);
            // cout << " focus E: " << focusNode->data;
            path.pop_back();
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

    ob->Insert(34);
    ob->Insert(29);
    ob->Insert(65);
    ob->Insert(21);
    ob->Insert(31);
    ob->Insert(43);
    ob->Insert(87);
    ob->Insert(56);
    ob->Insert(28);
    ob->Insert(30);

    ob->preOrder_Traversal(ob->getRoot());

    //cout << ob->sum.size() << endl;

    ob->Sum_Paths(ob->getRoot());

    for (int i = 0; i < ob->sum.size(); i++)
    {
        cout << "Sum: " << ob->sum[i] << endl;
    }
}