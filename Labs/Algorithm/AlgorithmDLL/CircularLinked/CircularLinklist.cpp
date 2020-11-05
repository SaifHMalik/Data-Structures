#include <iostream>
#include "node.cpp"
using namespace std;

int main(void)
{
    double num;
    int size;
    int index;
    linked_list ob;

    cout << "Enter Number of Nodes in Link List: " << endl;
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        cout << "Enter Elements of Link List: ";
        cin >> num;

        ob.add_nodeCLL(num);
    }

    ob.Display();
}
