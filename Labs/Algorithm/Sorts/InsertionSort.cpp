#include <iostream>
using namespace std;

int *InsertionSort(int *array, int size)
{
    int holePosition;
    int valuetoInsert;

    for (int i = 0; i < size; i++)
    {
        valuetoInsert = array[i];
        holePosition = i;

        while (holePosition > 0 && array[holePosition - 1] > valuetoInsert)
        {
            array[holePosition] = array[holePosition - 1];
            holePosition = holePosition - 1;
        }
        array[holePosition] = valuetoInsert;
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

    int *a = InsertionSort(arr, size);

    cout << "After Sorting: ";

    for (int i = 0; i < size; i++)
    {

        cout << a[i] << ",";
    }
}