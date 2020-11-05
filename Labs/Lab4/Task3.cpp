#include <iostream>
using namespace std;

int* Sort(int* array,int size){

    static int i = 0;
    static int j = 0;

    if(i == size){
        return array;
    }

    for(int j = 0;j < size;j++){
        if(array[i] < array[j]){
            int temp = array[j];
            array[j] = array[i];
            array[i] = temp;
        }
    }

    i++;

    Sort(array,size);
    
}


int main(void){
    int size;

    cout << "Enter Size of Array: " << endl;
    cin >> size;

    int array[size];

    for(int i = 0; i < size; i++){
        cout << "Enter Integer Number: ";
        cin >> array[i];
    }

    int* sortArray = Sort(array,size);

    for(int i = 0; i < size; i++){
        
        cout << sortArray[i] << ",";
    }


}