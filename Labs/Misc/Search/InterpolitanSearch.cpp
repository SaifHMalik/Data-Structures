#include <iostream>
using namespace std;

bool interpolitanSearch(int arr[], int n, int x)
{
    int low = 0;
    int high = n - 1;

    while (low <= high && x >= arr[low] && x <= arr[high])
    {
        if (low == high)
        {
            if (arr[low] == x)
            {
                return true;
            }
            return false;
        }

        int pos = low + ((double)(high - low) / ((arr[high] - arr[low])) * (x - arr[low]));

        if (arr[pos] == x)
        {
            return true;
        }

        if (arr[pos] < x)
        {
            low = pos + 1;
        }

        else
        {
            high = pos - 1;
        }
    }

    return false;
}

bool INSearch(int *arr, int low, int high, int x)
{
    int pos;

    if (low <= high && x >= arr[low] && x <= arr[high])
    {
        //pos = low + (high - low) / ((arr[high] - arr[low]) * (x - arr[low]));
        pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (x - arr[low]));

        if (arr[pos] == x)
        {
            return true;
        }

        if (arr[pos] < x)
        {
            return INSearch(arr, pos + 1, high, x);
        }

        if (arr[pos] > x)
        {
            return INSearch(arr, low, pos - 1, x);
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

    cout << "Enter Number to Search: ";
    cin >> num;

    cout << interpolitanSearch(array, size, num) << endl;

    cout << INSearch(array, 0, size - 1, num);
}