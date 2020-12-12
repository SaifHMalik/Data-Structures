#include <iostream>
using namespace std;

void countSort(int *arr, int size, int exp)
{
    int output[size];
    int i, count[10] = {0};

    for (i = 0; i < size; i++)
    {
        count[(arr[i] / exp) % 10]++;
    }

    for (i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for (i = size - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < size; i++)
    {
        arr[i] = output[i];
    }
}

int getMax(int *arr, int size)
{
    int mx = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (arr[i] > mx)
        {
            mx = arr[i];
        }
    }

    return mx;
}

void radixSort(int *arr, int size)
{

    int m = getMax(arr, size);

    for (int exp = 1; m / exp > 0; exp *= 10)
    {
        countSort(arr, size, exp);
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

    radixSort(array, size);

    for (int i = 0; i < size; i++)
    {
        cout << "Data: " << array[i] << endl;
    }
}