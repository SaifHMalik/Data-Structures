/*
IDE: Visual Code 1.51.1
Compiler: g++ (MinGW.org GCC Build-20200227-1) 9.2.0g++ (MinGW.org GCC Build-20200227-1) 9.2.0
cppStandard: c++17
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;

// Queue Max Size is defined which is 500 here
#define MAX 500

// Queue Class is used for implementing the Task
class Queue
{
protected:
    // myQueue is the array in which the data is to be stored
    int myQueue[MAX];
    int top; // top is used to access the top of the queue
    int end; // end is used to access the end of the queue

public:
    Queue()
    {
        top = -1;
        end = -1;
    }

    // isQueueFull Function to check whether Queue is full or not
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

    // isQueueEmpty Function to check whether Queue is Empty or not
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

    // addQueue Function to add an element to the end of queue
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
    }

    //removeQueue Function to remove from the top of the Queue
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

    //displayQueue Function to display the data stored in the Queue
    void displayQueue()
    {
        cout << "\nData: ";
        for (int i = top; i <= end; i++)
        {
            cout << myQueue[i] << " ";
        }
    }

    // Processing Function to dividie processing needs by unit quota
    int *Processing(Queue &CPU, int *processed)
    {

        for (int i = 0; i <= end; i++)
        {
            processed[i] = (CPU.removeQueue() / this->removeQueue());
            if (processed[i] == 0)
            {
                processed[i] = 1;
            }
        }
        return processed;
    }

    // Function to Sort the number of process to determine completion order
    void Result(int *array)
    {
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
    }
};

int main(void)
{
    int size, lineNum = 1;
    string num;
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
                permutation[i] = stoi(num);
            }
        }
        else if (lineNum == 2)
        {
            for (int i = 0; i < size; i++)
            {
                getline(str, num, ' ');
                quota[i] = stoi(num);
            }
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                getline(str, num, ' ');
                requirement[i] = stoi(num);
            }
        }
        lineNum++;
    }

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

    permutationNumbers.Result(a);

    permutationNumbers.displayQueue();

    ofstream os("OutputFile2.txt");
    for (int i = 0; i < size; i++)
    {
        os << permutationNumbers.removeQueue() << " ";
    }
}