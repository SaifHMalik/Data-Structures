#include <iostream>
#include <cstring>
using namespace std;

class DSA
{
protected:
    double *data;
    int size;

public:
    DSA()
    {
        data - NULL;
        size = 0;
    }

    DSA(int _size)
    {
        size = _size;
        data = new double[size];
        memset(data, 0, sizeof(double) * size);
    }

    DSA(const DSA *rhs)
    {
        size = rhs->size;
        data = new double[size];
        memcpy(data, rhs->data, (sizeof(double) * rhs->getSize()));
    }

    int getSize() const
    {
        return size;
    }

    ~DSA()
    {
        if (data != NULL)
        {
            cout << "\nDelete" << endl;
            delete[] data;
            data = NULL;
            size = 0;
        }
    }

    void Resize(int nsize)
    {
        double *tmp = new double[size];
        if (size != nsize)
        {
            for (int i = 0; i < size; i++)
            {
                tmp[i] = data[i];
            }

            delete[] data;
            data = 0;

            data = new double[nsize];

            memset(data, 0, sizeof(double) * nsize);

            for (int i = 0; i < size; i++)
            {
                data[i] = tmp[i];
            }

            size = nsize;
            delete[] tmp;
            tmp = 0;
        }

        else
        {
            return;
        }
    }

    DSA &operator=(DSA &rhs)
    {
        size = rhs.size;
        data = new double[size];
        memcpy(data, rhs.data, (sizeof(double) * rhs.getSize()));
        return (*this);
    }

    double &operator[](unsigned int i)
    {
        return *(data + i);
    }

    const double &operator[](unsigned int i) const
    {
        return *(data + i);
    }

    void operator<<(DSA &rhs)
    {
        cout << "Data: " << endl;
        for (int i = 0; i < rhs.size; i++)
        {
            cout << data[i] << endl;
        }
    }

    void operator>>(DSA &rhs)
    {
        for (int i = 0; i < rhs.size; i++)
        {
            cout << "Enter Elements" << endl;
            cin >> data[i];
        }
    }

    void insert(double val)
    {
        Resize(this->getSize() + 1);
        for (int i = 0; i <= size; i++)
        {
            if (i == size - 1)
            {
                data[i] = val;
                break;
            }

            else if (data[i] >= val)
            {
                for (int j = size - 1; j > i; j--)
                {
                    swap(data[j], data[j - 1]);
                }
                data[i] = val;
                break;
            }
        }
    }

    void searching(int val)
    {
        bool found = false;
        for (int i = 0; i < size; i++)
        {
            if (val == data[i])
            {
                cout << "The Searched Value is availabel on index: " << i << endl;
                found = true;
            }
            else if (i == size - 1 && found == false)
            {
                cout << "The Searched Value is not present in the Array" << endl;
            }
        }
    }
};

int main(void)
{
    int size;
    double value;

    cout << "Enter size" << endl;
    cin >> size;

    DSA ob(size);

    ob >> ob;
    ob << ob;
    cout << "Insert a value" << endl;
    cin >> value;
    ob.insert(value);

    cout << "Enter Value to Search" << endl;
    cin >> value;
    ob.searching(value);

    ob << ob;
}