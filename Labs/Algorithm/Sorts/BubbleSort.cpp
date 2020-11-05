#include <iostream>
using namespace std;

int *BubbleSort(int *array, int size)
{
    bool swapped;
    for (int i = 0; i < size; i++)
    {
        swapped = false;
        for (int j = 0; j < size; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(array[j], array[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
        {
            break;
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

    int *a = BubbleSort(arr, size);

    cout << "After Sorting: ";

    for (int i = 0; i < size; i++)
    {

        cout << a[i] << ",";
    }
}