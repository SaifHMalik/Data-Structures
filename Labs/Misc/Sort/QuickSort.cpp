#include <iostream>
using namespace std;

int partition(int *arr, int low, int high)
{
    int pivot = arr[high];

    int i = (low - 1);

    for (int j = low; j <= high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[j], arr[i]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int *arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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

    quickSort(array, 0, size - 1);

    for (int i = 0; i < size; i++)
    {
        cout << "Data: " << array[i] << endl;
    }
}