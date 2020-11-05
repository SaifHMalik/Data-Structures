#include<iostream>
#include"node.cpp"

using namespace std;
using namespace SLL;

int main(void){

    double num;
    int size;
    int index;
    linked_list ob;

    cout <<"Enter Number of Nodes in Link List: " <<endl;
    cin >> size;

    for(int i = 0; i < size; i++){
        cout << "Enter Elements of Link List: ";
        cin >> num;

        ob.add_node(num);
    }

    cout << "Enter Index to Search from index 0 to " << size-1 <<endl;
    cin >> index;

    ob.GetNth(&ob,index,size);
    
    //ob.BubbleSort();

    ob.Display();

}