/*
IDE: Visual Code 1.51.1
Compiler: g++ (MinGW.org GCC Build-20200227-1) 9.2.0g++ (MinGW.org GCC Build-20200227-1) 9.2.0
cppStandard: c++17
*/

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Class that will create Nodes for the BinarySearchTree
class node
{
public:
    int data;
    int height;

    node *left;
    node *right;

    node()
    {
        left = NULL;
        right = NULL;
    }

    node(int _data, int _height)
    {
        data = _data;
        height = _height;
        left = NULL;
        right = NULL;
    }
};

// The BinarySearchTree Class containing insertion and Summing level wise Functions
class BinarySearchTree
{
public:
    node *root;      // The first Node which will be created from which the tree will be extended
    vector<int> sum; // Vector to store the sums

    // Insert Function which insert left or right depending whether the data is less or greater than parent
    void Insert(int _data)
    {
        int level;

        if (root == NULL)
        {
            node *newNode = new node(_data, 0);
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
                    level = focusNode->height;
                    focusNode = focusNode->left;

                    if (focusNode == NULL)
                    {
                        node *newNode = new node(_data, level + 1);
                        parent->left = newNode;
                        return;
                    }
                }

                else
                {
                    level = focusNode->height;
                    focusNode = focusNode->right;

                    if (focusNode == NULL)
                    {
                        node *newNode = new node(_data, level + 1);
                        parent->right = newNode;
                        return;
                    }
                }
            }
        }
    }

    // The Sum_Levels Function sums the tree nodes level wise
    void Sum_Levels(node *focusNode)
    {
        if (focusNode != NULL)
        {
            if (focusNode == root)
            {
                sum.push_back(focusNode->data);
            }

            else if (sum.size() - 1 < focusNode->height)
            {
                sum.push_back(focusNode->data);
            }
            else
            {
                sum[focusNode->height] += focusNode->data;
            }

            Sum_Levels(focusNode->left);
            Sum_Levels(focusNode->right);
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
    ifstream rsi("InputFile1.txt");

    if (rsi.is_open() == false)
    {
        cout << "No Input File Exist; Making New Input File Please Enter Input in InputFile1" << endl;
        ofstream wsi("InputFile1.txt");
        wsi.close();
    }

    rsi.close();

    ifstream is("InputFile1.txt");

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

    ob->Sum_Levels(ob->getRoot());

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

    ofstream os("OutputFile1.txt");

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