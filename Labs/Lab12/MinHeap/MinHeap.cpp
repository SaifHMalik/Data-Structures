#include <iostream>
using namespace std;

class MinHeap
{
    int *arr;
    int capacity;
    int size;

public:
    MinHeap(int _capacity)
    {
        arr = new int[capacity];
        capacity = _capacity;
        size = 0;
    }

    int getSize()
    {
        return size;
    }

    int getParent(int child)
    {
        if (child % 2 == 0)
        {
            return (child / 2) - 1;
        }

        else
        {
            return (child / 2);
        }
    }

    int getLeft(int parent)
    {
        return (2 * parent + 1);
    }

    int getRight(int parent)
    {
        return (2 * parent + 2);
    }

    bool isleaf(int i)
    {
        if (i >= size)
        {
            return true;
        }

        return false;
    }

    void shiftdown(int i)
    {
        int l = getLeft(i);
        int r = getRight(i);

        if (isleaf(l))
        {
            return;
        }

        int minIndex = i;

        if (arr[l] < arr[i])
        {
            minIndex = l;
        }

        if (!isleaf(r) && (arr[r] < arr[minIndex]))
        {
            minIndex = l;
        }

        if (minIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            shiftdown(minIndex);
        }
    }

    void shiftup(int i)
    {
        if (i == 0)
        {
            return;
        }

        int parent_index = getParent(i);

        if (arr[parent_index] > arr[i]) ////////////////////////////////////////
        {
            int temp = arr[parent_index];
            arr[parent_index] = arr[i];
            arr[i] = temp;
            shiftup(parent_index);
        }
    }

    void insert(int k)
    {
        arr[size] = k;
        shiftup(size);
        size++;

        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }

    int removeAt(int k)
    {
        int r = arr[k];

        arr[k] = arr[size - 1];
        size--;
        int p = getParent(k);

        if (k == 0 || arr[k] < arr[p])
        {
            shiftdown(k);
        }

        else
        {
            shiftup(k);
        }
        return r;
    }

    void heapify(int *array, int len)
    {
        size = len;
        arr = array;

        for (int i = size - 1; i >= 0; --i)
        {
            shiftup(i);
        }
    }
};

int main(void)
{

    int size;
    int num;

    cout << "Enter Size of Heap: " << endl;
    cin >> size;

    int arr[size];

    MinHeap *ob = new MinHeap(size);

    for (int i = 0; i < size; i++)
    {
        cout << "Enter Number " << endl;
        cin >> arr[i];

        ob->insert(arr[i]);
    }

    ob->heapify(arr, size);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}