#include <iostream>
using namespace std;

int binarySearch(int *arr, int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
        {
            return mid;
        }

        if (arr[mid] > x)
        {
            return binarySearch(arr, l, mid - 1, x);
        }

        return binarySearch(arr, mid + 1, r, x);
    }

    return -1;
}

bool BinSearch(int arr[], int l, int r, int x)
{
    int mid;

    while (r >= l)
    {

        mid = l + ((r - l) / 2);
        cout << "Mid: " << mid << endl;
        cout << "L: " << l << endl;
        cout << "R: " << r << endl;
        if (arr[mid] == x)
        {
            return true;
        }

        if (arr[mid] < x)
        {
            cout << "Less" << endl;
            l = mid + 1;
        }

        else if (arr[mid] > x)
        {
            r = mid - 1;
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

    // Before Searching array must be sorted
    cout << binarySearch(array, 0, size - 1, num) << endl;
    cout << BinSearch(array, 0, size - 1, num) << endl;
}