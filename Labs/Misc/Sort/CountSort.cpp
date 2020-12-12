#include <iostream>
using namespace std;

void CountSort(int *arr, int size)
{
    int output[10];
    int countArr[10];
    int x = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (arr[i] > x)
        {
            x = arr[i];
        }
    }

    for (int i = 0; i <= x; i++)
    {
        countArr[i] = 0;
    }

    for (int i = 0; i < size; i++)
    {
        countArr[arr[i]]++;
    }

    for (int i = 1; i <= x; i++)
    {
        countArr[i] += countArr[i - 1];
    }

    for (int i = 0; i < size; i++)
    {
        output[countArr[arr[i]] - 1] = arr[i];
        countArr[arr[i]]--;
    }

    for (int i = 0; i < size; i++)
    {
        arr[i] = output[i];
    }
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

    CountSort(array, size);

    for (int i = 0; i < size; i++)
    {
        cout << "Data: " << array[i] << endl;
    }
}