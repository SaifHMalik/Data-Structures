#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

class Palindrome
{
private:
public:
    bool Check_Palindrome(int *arr, int size)
    {
        int rem = 0;
        int revArray[size];
        bool check = true;

        for (int i = 0; i < size; i++)
        {
            int num = arr[i];
            revArray[i] = 0;

            while (num > 0)
            {

                rem = (num % 10);
                revArray[i] = revArray[i] * 10 + rem;
                num = num / 10;
            }
        }

        for (int i = 0; i < size; i++)
        {

            if (check == false)
            {
                return false;
            }

            if (arr[i] == revArray[size - (i + 1)])
            {
                check = true;
            }

            else
            {
                check = false;
            }
        }

        return true;
    }
};

int main(void)
{
    int size;
    int elements;
    string line;
    string num;
    bool check;

    Palindrome ob;

    ifstream rsi("InputFile2.txt");

    if (rsi.is_open() == false)
    {

        ofstream os("InputFile2.txt");

        cout << "Enter Size: ";
        cin >> size;
        cin.ignore();
        cin.clear();

        os << size << endl;

        for (int i = 0; i < size; i++)
        {
            cout << "Enter Element of Array: ";
            cin >> elements;
            cin.ignore();
            cin.clear();

            os << elements << endl;
        }

        os.close();
    }

    rsi.close();

    ifstream is("InputFile2.txt");
    getline(is, line);

    int array[stoi(line)];

    for (int i = 0; i < stoi(line); i++)
    {
        getline(is, num);
        array[i] = stoi(num);
    }

    for (int i = 0; i < stoi(line); i++)
    {

        cout << array[i] << endl;
    }

    check = ob.Check_Palindrome(array, stoi(line));

    cout << "Check: " << check;

    ofstream outs("OutputFile2.txt");

    if (check == true)
    {
        outs << "YES";
    }

    else
    {
        outs << "NO";
    }
}
