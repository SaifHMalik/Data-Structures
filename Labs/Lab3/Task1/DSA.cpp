#include<iostream>
#include<cstring>
#include"DSA.h"

using namespace DSA;
using namespace std;




ArrayIndexOutOfBoundException::ArrayIndexOutOfBoundException():msg("Array Index Out of Bound"){
    
}


ArrayIndexOutOfBoundException::~ArrayIndexOutOfBoundException(){

}

string ArrayIndexOutOfBoundException::what(){
    return msg;
}



DynamicSafeArray::DynamicSafeArray(){
    Data = NULL;
    size = 0;
} 

DynamicSafeArray::DynamicSafeArray(int n){
    size = n;
    Data = new int[size];
    memset(this->Data,0,sizeof(int)*size);

}

DynamicSafeArray::DynamicSafeArray(const DynamicSafeArray &rhs){
    this->size = rhs.size;
    this->Data = new int[size];
    memcpy(this->Data,rhs.Data,(sizeof(int)*rhs.getSize()));

}


DynamicSafeArray::~DynamicSafeArray(){
    if(Data != 0){
        cout << "\nDelete" << endl;
        delete[] Data;
        Data = 0;
        size = 0; 
    }
}

void DynamicSafeArray::Resize(int nSize){
    if(size != nSize){
        int *temp = new int [size];

        for(int i =0;i < size; i++){
            temp[i] = *(Data+i);
        }

        delete[] Data;
        Data = 0;

        Data = new int[nSize];
        memset(this->Data,0,sizeof(int)*nSize);

        for(int i=0; i<nSize ; i++){
            *(Data+i) = temp[i];
        }

        size = nSize;
        delete [] temp;
        temp=0;
    }
}

unsigned int DynamicSafeArray::getSize() const {
    return size;
}

DynamicSafeArray& DynamicSafeArray::operator = (DynamicSafeArray &rhs){
    
    if(this != &rhs){
        int s = rhs.getSize();
        this->size = s;
        this->Data = new int[s];
        memcpy(this->Data,rhs.Data,sizeof(rhs.Data));

    }
    return(*this);
}

int& DynamicSafeArray::operator[](unsigned int i){
    return *(Data+i);
}

const int& DynamicSafeArray::operator[](unsigned int i) const{
    return *(Data+i);
}

void DynamicSafeArray::operator << (DynamicSafeArray &rhs){
    for(int j = 0; j < rhs.size; j++){
        cout << rhs[j] << ",";
    }
}

void DynamicSafeArray::operator >> (DynamicSafeArray &rhs){
    for(int j = 0; j < rhs.size; j++){
        cin >> rhs[j];
    }
}

