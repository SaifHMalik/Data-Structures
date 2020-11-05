#include<iostream>

using namespace std;

int Sum_Num(int* arr, int size){

    if(size == 0){
        return 0;
    }

    --size;

    if(arr[size] % 2 == 0){
        return (arr[size] + Sum_Num(arr ,size));
    }

    else{
        Sum_Num(arr,size);
    }
}

int main(void){

    int size;
    cout << "Enter Size of Array: " <<endl;
    cin >> size;

    int array[size];

    for(int i = 0; i < size; i++){
        cout << "Enter Integer Number: ";
        cin >> array[i];
    }

    int num = Sum_Num(array,size);

    cout << "The Value is: " << num;

}


