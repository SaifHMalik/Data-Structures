#include <iostream>
#include "node.cpp"

using namespace std;
using namespace SLL;

int main(void)
{

    double num;
    linked_list ob1;
    linked_list ob2;

    for (int i = 0; i < 12; i++)
    {
        cout << "Enter Elements of Link List: ";
        cin >> num;

        ob1.add_node(num);
    }

    ob2.average(&ob1, &ob2);
    ob2.Display();
}