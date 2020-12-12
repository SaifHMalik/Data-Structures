#include <iostream>
using namespace std;

void selectionSort(int *array, int size)
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

            swap(array[min], array[i])
        }
    }

    int main(void)
    {
    }