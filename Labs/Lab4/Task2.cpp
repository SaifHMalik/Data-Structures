#include <iostream>
using namespace std;


int* REV(int* array,int* revarr,int size){

    static int i = 0;

    

    if(size == 0){
        return revarr;
    }

    --size;
    revarr[i] = array[size];

    i++;

    REV(array,revarr,size);

    
}

int main(void){
    int size;

    cout << "Enter Size of Array: " << endl;
    cin >> size;

    int arr[size];
    int revarr[size];

    for(int i = 0; i < size; i++){
        cout << "Enter Integer Number: ";
        cin >> arr[i];
    }

    cout << endl;

    int *a = REV(arr,revarr,size);

    cout << "Reversed Array Element: ";

    for(int i = 0; i < size; i++){
        
        cout << a[i] << ",";
    }

}