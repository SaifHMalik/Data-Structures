#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;

#define MAX 500

class Queue
{
protected:
    int myQueue[MAX];
    int top;
    int end;

public:
    Queue()
    {
        top = -1;
        end = -1;
    }

    Queue(int _size)
    {
        top = -1;
        end = -1;
    }

    bool isQueueFull()
    {
        if (end >= MAX - 1)
        {
            cout << "Queue is Full" << endl;
            return true;
        }

        else
        {
            return false;
        }
    }

    bool isQueueEmpty()
    {
        if (end <= -1)
        {
            cout << "Queue is Empty" << endl;
            return true;
        }

        else
        {
            return false;
        }
    }

    void addQueue(int num)
    {
        if (isQueueFull())
        {
            cout << "QUEUE is Full" << endl;
            return;
        }

        else
        {
            if (top == -1)
            {
                top = 0;
            }

            end++;
            myQueue[end] = num;
        }
        cout << "\nmyQueue (Add Queue):" << endl;
        for (int k = 0; k <= end; k++)
        {
            cout << myQueue[k] << "\t";
        }
        cout << endl;
    }

    int removeQueue()
    {
        if (isQueueEmpty())
        {
            cout << "Queue is Empty" << endl;
            return 0;
        }

        else
        {
            int value;
            value = myQueue[top];
            myQueue[top] = NULL;
            top++;
            return value;
        }
    }

    void displayQueue()
    {
        for (int i = top; i <= end; i++)
        {
            cout << "Data: " << myQueue[i] << endl;
        }
    }

    int *Processing(Queue &CPU, int *processed)
    {

        cout << "\nProcessing" << endl;
        for (int i = 0; i <= end; i++)
        {
            processed[i] = (CPU.removeQueue() / this->removeQueue());
            if (processed[i] == 0)
            {
                processed[i] = 1;
            }
            cout << processed[i] << "\t";
            //cout << "Data: " << processed[i] << endl;
        }
        cout << endl;
        return processed;
    }

    void Result(int *array)
    {
        cout << "\nArray:" << endl;
        for (int k = 0; k <= end; k++)
        {
            cout << array[k] << "\t";
        }
        cout << endl;
        cout << "\nmyQueue:" << endl;
        for (int k = 0; k <= end; k++)
        {
            cout << myQueue[k] << "\t";
        }
        cout << endl;

        int key, j, key1;

        for (int i = 1; i <= end; i++)
        {

            key = array[i];
            key1 = myQueue[i];
            j = i - 1;

            while (j >= 0 && array[j] > key)
            {
                array[j + 1] = array[j];
                myQueue[j + 1] = myQueue[j];
                j = j - 1;
            }
            array[j + 1] = key;
            myQueue[j + 1] = key1;
        }
        // for (int i = 0; i <= end; i++)
        // {
        //     for (int j = 0; j <= end; j++)
        //     {
        //         if (array[i] < array[j] || ((array[i] == array[j] && i < j)))
        //         {
        // cout << "Array i > j:\t" << array[i] << "\t" << array[j] << endl;
        //swap(array[i], array[j]);
        // cout << "Array i > j:\t" << array[i] << "\t" << array[j] << endl;
        // cout << "myQueue i > j:\t" << myQueue[i] << "\t" << myQueue[j] << endl;
        // swap(myQueue[i], myQueue[j]);
        // if (i > j && array[i] == array[j])
        // {
        //     swap(myQueue[i], myQueue[j]);
        // }
        // cout << "myQueue i > j:\t" << myQueue[i] << "\t" << myQueue[j] << endl;
        //}
        // else if (i < j && array[i] == array[j])
        // {
        //     {
        //         swap(myQueue[i], myQueue[j]);
        //     }
        // }

        // else if (array[i] == array[j])
        // {
        //     if (myQueue[i] > myQueue[j])
        //     {
        //         swap(myQueue[i], myQueue[j]);
        //     }
        // }
    }
    // cout << "\nArray:" << endl;
    // for (int k = 0; k <= end; k++)
    // {
    //     cout << array[k] << "\t";
    // }
    // cout << endl;
    // cout << "\nmyQueue:" << endl;
    // for (int k = 0; k <= end; k++)
    // {
    //     cout << myQueue[k] << "\t";
    // }
    // cout << endl;
    //}
    // for (int i = 0; i < end; i++)
    // {
    //     if (array[i] == array[i + 1] && myQueue[i] > myQueue[i + 1])
    //     {
    //         swap(myQueue[i], myQueue[i + 1]);
    //     }
    // }
    // cout << "\nResult: Array" << endl;
    // for (int i = 0; i <= end; i++)
    // {
    //     cout << array[i] << "\t";
    // }
    // cout << endl;
    // cout << "\nResult: myQueue" << endl;
    // for (int i = 0; i <= end; i++)
    // {
    //     cout << myQueue[i] << "\t";
    // }
    // cout << endl;
    //}
};

int main(void)
{
    int size, lineNum = 1;
    string num;
    //Queue numofProcess;
    Queue permutationNumbers;
    Queue quotaUnits;
    Queue CPUProcess;

    ifstream rsi("InputFile2.txt");

    if (rsi.is_open() == false)
    {
        cout << "No Input File Exist; Making New Input File Please Enter Input in InputFile2" << endl;
        ofstream wsi("InputFile2.txt");
        wsi.close();
    }

    rsi.close();

    ifstream is("InputFile2.txt");
    getline(is, num);

    size = stoi(num);

    int permutation[size];
    int quota[size];
    int requirement[size];

    while (lineNum < 4)
    {
        getline(is, num);
        stringstream str(num);
        if (lineNum == 1)
        {
            for (int i = 0; i < size; i++)
            {
                getline(str, num, ' ');
                cout << "Loop 1:\t" << i << num << endl;
                permutation[i] = stoi(num);
            }
        }
        else if (lineNum == 2)
        {
            for (int i = 0; i < size; i++)
            {
                getline(str, num, ' ');
                cout << "Loop 2:\t" << i << num << endl;
                quota[i] = stoi(num);
            }
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                getline(str, num, ' ');
                cout << "Loop 3:\t" << i << num << endl;
                requirement[i] = stoi(num);
            }
        }
        lineNum++;
    }

    // while (!is.eof())
    // {
    //     cout << "While" << endl;
    //     for (int i = 0; i < size - 1; i++)
    //     {
    //         getline(is, num, ' ');
    //         cout << "Loop 1:\t" << i << num << endl;
    //         permutation[i] = stoi(num);
    //     }

    //     for (int i = 0; i < size - 1; i++)
    //     {
    //         getline(is, num, ' ');
    //         cout << "Loop 2:\t" << i << num << endl;
    //         quota[i] = stoi(num);
    //     }

    //     for (int i = 0; i < size - 1; i++)
    //     {
    //         getline(is, num, ' ');
    //         cout << "Loop 3:\t" << i << num << endl;
    //         requirement[i] = stoi(num);
    //     }
    // }
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << permutation[i] << "\t";
    }
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << quota[i] << "\t";
    }
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << requirement[i] << "\t";
    }
    cout << endl;
    // getline(is, num);

    int alength = num.length();
    // vector<int> permutation;

    // for (int i = 0; num[i] != '\0'; i++)
    // {
    //     if (num[i] == ' ')
    //     {
    //         j++;
    //     }
    // }

    for (int i = 0; i < size; i++)
    {
        permutationNumbers.addQueue(permutation[i]);
    }

    for (int i = 0; i < size; i++)
    {
        quotaUnits.addQueue(quota[i]);
    }

    for (int i = 0; i < size; i++)
    {
        CPUProcess.addQueue(requirement[i]);
    }

    int processed[size];

    int *a = quotaUnits.Processing(CPUProcess, processed);

    cout << endl
         << "\nData:\n";

    // for (int i = 0; i < size; i++)
    // {
    //     cout << a[i] << "\t";
    // }

    permutationNumbers.Result(a);
    cout << "\n\n\n\n\n";

    permutationNumbers.displayQueue();

    ofstream os("OutputFile2.txt");
    for (int i = 0; i < size; i++)
    {
        os << permutationNumbers.removeQueue() << " ";
    }
}