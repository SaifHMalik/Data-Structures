#include<iostream>
#include"DynamicSafeArray.h"

using namespace DSA;
using namespace std;
using namespace OU;

OrderdDSA::OrderdDSA(){
    Data = NULL;
    size = 0;
}

OrderdDSA::OrderdDSA(int a){
    size = a;
    Data = new int[size];
    memset(this->Data,0,sizeof(int)*size);
}

UnOrderedDSA::UnOrderedDSA(){
    Data = NULL;
    size = 0;
}

UnOrderedDSA::UnOrderedDSA(int a){
    size = a;
    Data = new int[size];
    memset(this->Data,0,sizeof(int)*size);
}

void OrderdDSA::insertion(int val){
    Resize(getSize()+1);
    for(int i = 0; i <= size; i++){
	    if(i == size-1){
		    Data[size-1] = val;
            break;
	    }else if(Data[i] >= val){
		    for(int j = size-1; j > i; j--){
			    swap(Data[j], Data[j-1]);
		    }
		    Data[i] = val;
		    break;
	    }
    }
}

void OrderdDSA::searching(int var){
    bool found = false;
    for(int i = 0; i < size; i++){
        if(var == Data[i]){
            cout << "The Searched Value is availabel on index: " << i <<endl;
            found = true;
        }
        else if(i == size-1 && found == false){
            cout << "The Searched Value is not present in the Array" <<endl;
        }
    }
}

void OrderdDSA::sort(){
    for(int i = 0; i < size;i++){
        for(int j = 0;j < size; j++){
            if(Data[j] > Data[j+1]){
                swap(Data[j],Data[j+1]);
            }
        }
    }
}

void UnOrderedDSA::insertion(int val){
    Resize(getSize()+1);
    Data[size-1] = val;

}

void UnOrderedDSA::searching(int var){
    bool found = false;
    for(int i = 0; i < size; i++){
        if(var == Data[i]){
            cout << "The Searched Value is availabel on index: " << i <<endl;
            found = true;
        }
        else if(i == size-1 && found == false){
            cout << "The Searched Value is not present in the Array" <<endl;
        }
    }
}

