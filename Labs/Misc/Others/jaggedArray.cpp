#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int in = 0;
    int a = 0;

    vector<vector<int>> vec;

    for (int i = 0; i < 3; i++)
    {
        vector<int> t;
        cout << "Enter Row Size:" << endl;
        cin >> in;
        for (int j = 0; j < in; j++)
        {
            cout << "Enter Row Elements" << endl;
            cin >> a;
            t.push_back(a);
        }

        vec.push_back(t);
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
}