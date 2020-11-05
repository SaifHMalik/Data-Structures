#include <iostream>
#include "node.cpp"
using namespace std;

int main(void)
{
    double num;
    int size;

    linked_list ob;

    cout << "Enter Size of Linkded List: ";
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        cout << "Enter Elements of Linked List: " << endl;
        cin >> num;
        ob.add_node(num);
    }

    cout << "Before Swapping: " << endl;
    ob.Display();

    ob.SelectionSort();

    cout << "\nAfter Swapping: " << endl;
    ob.Display();
}