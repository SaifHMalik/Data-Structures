#include <iostream>
using namespace std;

int *SelectionSort(int *array, int size)
{
    int min;
    for (int i = 0; i < size; i++)
    {
        min = i;

        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            swap(array[min], array[i]);
        }
    }
    return array;
}

int main(void)
{
    int size;

    cout << "Enter Size of Array: " << endl;
    cin >> size;

    int arr[size];

    for (int i = 0; i < size; i++)
    {
        cout << "Enter Integer Number: ";
        cin >> arr[i];
    }

    int *a = SelectionSort(arr, size);

    cout << "After Sorting: ";

    for (int i = 0; i < size; i++)
    {

        cout << a[i] << ",";
    }
}