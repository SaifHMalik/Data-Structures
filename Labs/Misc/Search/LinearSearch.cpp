#include <iostream>
using namespace std;

bool linear_Search(int *array, int size)
{
    int num;
    cout << "Enter NUmber to Find " << endl;
    cin >> num;

    for (int i = 0; i < size; i++)
    {
        if (array[i] == num)
        {
            return true;
        }
    }

    return false;
}

int main(void)
{
    int size;
    int num;
    cout << "Enter Size: ";
    cin >> size;

    int array[size];

    for (int i = 0; i < size; i++)
    {
        cout << "Enter Element: ";
        cin >> array[i];
    }

    cout << "Ans: " << linear_Search(array, size);
}