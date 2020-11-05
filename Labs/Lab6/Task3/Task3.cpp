#include<iostream>
#include"node.cpp"

using namespace std;
using namespace SLL;

int main(void){

    double num;
    int count;
    linked_list ob;

    

    for(int i = 0; i < 6; i++){
        cout << "Enter 6 End Devices : ";
        cin >> num;

        ob.add_node(num);
    }


    cout << "Enter 1 Router:" <<endl;
    cin >> num;

    ob.add_node(num);

    cout << "Before Deleting: " <<endl;
    ob.Display();

    ob.deleteNode();

    cout << "After Deletion: " <<endl;
    ob.Display();


    cout << "Enter Position for device to Insert:" <<endl;
    cin >> count;

    cout << "Enter device to Insert:" <<endl;
    cin >> num;

    ob.insertNode(num,count);

    cout << "After Insertion " <<endl;
    ob.Display();
    


}