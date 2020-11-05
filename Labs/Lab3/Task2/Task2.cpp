#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int num,row,element;

    vector<vector<int>> jagged;

    cout << "Enter Number of Rows: ";
    cin >> row;

    for(int i = 0; i < row; i++){
        vector <int> temp;
        cout << "Enter the Size of Row " << i << " : ";
        cin >> num;

        for(int j = 0; j < num; j++){
            cout << "Enter Row Elements: " <<endl;
            cin >> element;
            temp.push_back(element);
        }
        jagged.push_back(temp);
    }

    for(int i = 0; i < jagged.size();i++){
        cout << "\nRow " << i << " : ";
        for(int j = 0; j < jagged[i].size();j++){
            cout << jagged[i][j] << ",";
        }
    }
}