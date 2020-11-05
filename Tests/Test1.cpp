#include<iostream>
#include<vector>

using namespace std;


int main(void){
    int i;
    int m = 3;
    int n = 4;
    vector <int> array = {0, 1,  2,  3,
                          4, 5,  6,  7,
                          8, 9, 10, 11 };
    vector <int> a;
    // 1 0 5 2 6 4 9 10 7 11
    // cout << "Enter n or column: ";
    // cin >> n;

    cout << "Enter i: ";
    cin >> i;

    for(int j = 0; j < 8; j++){
        if(i < n && j < 3){
            continue;
            cout << "Caught 0" << endl;
        } else if(i%n == 0 && (j == 0 || j == 3 || j == 5)){
            cout << "Caught 1" << endl;
            continue;
        } else if((i+1)%n == 0 && (j == 2 || j == 4 || j == 7)){
            cout << "Caught 2" << endl;
            continue;
        } else if(i >= (n*(m-1)) && (j > 4)){
            cout << "Caught 3" << endl;
            continue;
        } else{
            if(j == 0){
                a.push_back(i-n-1);
            } else if(j == 1){
                a.push_back(i-n);
            } else if(j == 2){
                a.push_back(i-n+1);
            } else if(j == 3){
                a.push_back(i-1);
            } else if(j == 4){
                a.push_back(i+1);
            } else if(j == 5){
                a.push_back(i+n-1);
            } else if(j == 6){
                a.push_back(i+n);
            } else if(j == 7){
                a.push_back(i+n+1);
            }
        }
    }

    // a.push_back(i-n-1);
    // a.push_back(i-n);
    // a.push_back(i-n+1);
    // a.push_back(i-1);
    // a.push_back(i+1);
    // a.push_back(i+n-1);
    // a.push_back(i+n);
    // a.push_back(i+n+1);

    // for(int j = 0;j<a.size();j++){
    //     cout << a[j] <<endl;
    // }


    for(int j = 0; j < a.size(); j++){

        // if((a[j] <= 0) || (a[j] >= n && (a[j]/n) == 0)){
            
        // } else{
            cout << a[j] <<endl;
        // }
    }


}