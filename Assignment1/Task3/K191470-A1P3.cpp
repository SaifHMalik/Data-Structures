#include<iostream>
#include<string.h>
#include<fstream>


using namespace std;

class Set{
private:
    int size;

public:
    Set(){

    }

    Set(int _size){
        size = _size;
    }

    void Size(int _size){
        size = _size;
    }


    bool Sub_set(int *arr,int ci,int target){
    
    if(target == 0){
        return true;
    }

    if(ci >= size){
        return false;
    }

    else{
        return Sub_set(arr,ci+1,target) + Sub_set(arr,ci+1,target - arr[ci]);
        }

    }
};

int main (void){
    int size;
    int elements;
    string line;
    string num;
    bool check;
    
    ifstream rsi("InputFile3.txt");

    if(rsi.is_open() == false){

    ofstream os("InputFile3.txt");
    
        cout << "Enter Size: ";
        cin >> size;
        cin.ignore();
        cin.clear();

        os << size <<endl;

        for(int i = 0; i < size; i++){
            cout << "Enter Element of Array: ";
            cin >> elements;
            cin.ignore();
            cin.clear();

            os << elements <<endl;
        }

        cout << "Enter Target Value: ";
        cin >> elements;
        cin.ignore();
        cin.clear();

        os << elements <<endl;

        Set ob(size);

        os.close();

    }

    rsi.close();

    Set ob;

    ifstream is("InputFile3.txt");
    getline(is,line);

    int array[stoi(line)];

    ob.Size(stoi(line));

    for(int i = 0; i < stoi(line); i++){
        getline(is,num);
        array[i] = stoi(num);
    }

    for(int i = 0; i < stoi(line); i++){

        cout << array[i] <<endl;
       
    }

    getline(is,num);
    cout << num;

    check = ob.Sub_set(array,0,stoi(num));

    ofstream outs("OutputFile3.txt");

    if(check == true){
        outs << "YES";
    }

    else{
        outs << "NO";
    }

}


