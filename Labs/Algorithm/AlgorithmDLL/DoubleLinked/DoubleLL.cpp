#include <iostream>
#include "node.cpp"
using namespace std;

int main(void)
{
    double num;
    int size;
    int index;
    linked_list ob;

    cout << "Enter Size of Link List: " << endl;
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        cout << "Enter Elements of Link List: ";
        cin >> num;

        ob.add_node(num);
    }

    cout << "\nTraverse from begiinning " << endl;
    ob.Traverse_Beginning();

    cout << "\nTraverse from End" << endl;
    ob.Traverse_Ending();

    cout << "\nInsert At Beginning" << endl;
    ob.insertAtBeginning(10);

    cout << "\nTraverse from begiinning " << endl;
    ob.Traverse_Beginning();

    cout << "\n Inserting at End" << endl;
    ob.insertAtEnd(3);

    cout << "\nTraverse from begiinning " << endl;
    ob.Traverse_Beginning();

    cout << "\nEnter index to Insert 1 - size" << endl;
    cin >> index;

    cout << "Enter Value to Insert" << endl;
    cin >> num;

    if (index > 0)
    {
        ob.insertPosition(num, index);
    }

    cout << "\nTraverse from begiinning " << endl;
    ob.Traverse_Beginning();

    cout << "Delete from beginning: " << endl;
    ob.deleteFromBeginning();

    cout << "\nTraverse from begiinning " << endl;
    ob.Traverse_Beginning();

    cout << "Enter Index to Delete 1 - size" << endl;
    cin >> index;

    if (index > 0)
    {
        ob.deletePosition(index);
    }

    cout << "\nTraverse from End" << endl;
    ob.Traverse_Ending();

    cout << "Delete From End" << endl;
    ob.deleteFromEnd();

    cout << "\nTraverse from begiinning " << endl;
    ob.Traverse_Beginning();
}
