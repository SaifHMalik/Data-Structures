#include <iostream>
using namespace std;

int *bubbleSort(int *array, int size)
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
}