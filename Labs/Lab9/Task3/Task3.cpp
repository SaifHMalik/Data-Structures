#include <iostream>
#include "queue.cpp"

using namespace std;
using namespace QUE;

int main(void)
{
    int size;
    int num;

    cout << "Enter Size of Queue" << endl;
    cin >> size;

    Queue ob;

    for (int i = 0; i < size; i++)
    {
        cout << "Enter Number" << endl;
        cin >> num;
        ob.enQueue(num);
    }

    ob.display();

    ob.reverse();

    cout << "After Reversing" << endl;
    ob.display();
}