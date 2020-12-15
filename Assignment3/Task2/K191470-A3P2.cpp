/*
IDE: Visual Code 1.51.1
Compiler: g++ (MinGW.org GCC Build-20200227-1) 9.2.0g++ (MinGW.org GCC Build-20200227-1) 9.2.0
cppStandard: c++17
*/

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// Class that will create nodes for the binary tree
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

// The BinarySearchTree Class contains functions for insertion and Summing the paths of the Binary Search Tree
class BinarySearchTree
{
public:
    node *root;
    vector<int> sum;
    vector<int> path;

public:
    // Insert Function which insert left or right depending whether the data is less or greater than parent
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

    // The Sum_Paths Function Sums the path of the tree and outputs the result of each paths
    void Sum_Paths(node *focusNode)
    {
        if (focusNode != NULL)
        {
            if ((focusNode->right == 0 && focusNode->left == 0))
            {
                path.push_back(focusNode->data);

                int var = 0;

                for (int i = 0; i < path.size(); i++)
                {
                    var += path[i];
                }

                sum.push_back(var);
                path.pop_back();
            }

            path.push_back(focusNode->data);
            Sum_Paths(focusNode->left);
            path.pop_back();
            path.push_back(focusNode->data);
            Sum_Paths(focusNode->right);
            path.pop_back();
        }
    }

    // In order to get the root of the binary Search tree
    node *getRoot()
    {
        return root;
    }
};

int main(void)
{
    string num;
    vector<int> values;

    ifstream rsi("InputFile2.txt");

    if (rsi.is_open() == false)
    {
        cout << "No Input File Exist; Making New Input File Please Enter Input in InputFile2" << endl;
        ofstream wsi("InputFile2.txt");
        wsi.close();
    }

    rsi.close();

    ifstream is("InputFile2.txt");

    while (is.eof() == false)
    {
        getline(is, num, ' ');

        if (num[0] != '\0' && num[0] != '\n')
        {
            values.push_back(stoi(num));
        }
    }

    is.close();

    BinarySearchTree *ob = new BinarySearchTree();

    for (int i = 0; i < values.size(); i++)
    {
        ob->Insert(values[i]);
    }

    ob->Sum_Paths(ob->getRoot());

    for (int i = 0; i < ob->sum.size(); i++)
    {
        if (i == ob->sum.size() - 1)
        {
            cout << ob->sum[i];
        }
        else
        {
            cout << ob->sum[i] << '-';
        }
    }

    ofstream os("OutputFile2.txt");

    for (int i = 0; i < ob->sum.size(); i++)
    {
        if (i == ob->sum.size() - 1)
        {
            os << ob->sum[i];
        }
        else
        {
            os << ob->sum[i] << '-';
        }
    }
}