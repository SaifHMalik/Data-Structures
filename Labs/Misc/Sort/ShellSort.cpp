#include <iostream>
using namespace std;

int *shellSort(int *arr, int size)
{
    for (int gap = size / 2; gap > 0; gap /= 2)
    {

        for (int i = gap; i < size; i++)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }

            arr[j] = temp;
        }
    }

    return arr;
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

    int *a = shellSort(array, size);

    for (int i = 0; i < size; i++)
    {
        cout << "Data: " << a[i] << endl;
    }
}