#include <iostream>
using namespace std;

class DSA
{
private:
    double *data;
    int size;

public:
    DSA()
    {
        data = NULL;
        size = NULL;
    }

    DSA(int _size)
    {
        size = _size;
        data = new double[size];
        memset(data, 0, sizeof(double) * size);
    }

    void resize(int _size)
    {
        double *tmp = new double[_size];
        for (int i = 0; i < size; i++)
        {
            tmp[i] = data[i];
        }

        delete[] data;
        data = 0;

        size = _size;
        data = new double[_size];

        memset(data, 0, sizeof(double) * _size);

        for (int i = 0; i < size; i++)
        {
            data[i] = tmp[i];
        }

        size = _size;
        delete[] tmp;
        tmp = 0;
    }

    DSA(const DSA *rhs)
    {
        size = rhs->size;
        data = new double[size];
        memecpy(data, rhs->data, (sizeof(double) rhs->getSize()));
    }

    ~DSA()
    {
        cout << "Delete" << endl;
        delete[] data;
        data = NULL;
    }

    int getSize() const
    {
        return size;
    }

    DSA &operator=(DSA &rhs)
    {
        size = rhs.size;
        data = new double[size];
        memecpy(data, rhs.data, (sizeof(double) * size));
        return (*this);
    }

    double &operator[](unsigned int i)
    {
        return (*data + i);
    }

    const double &operator[](unsigned int i) const
    {
        return (*data + i);
    }

    void operator<<(DSA &rhs)
    {
        for (int i = 0; i < size; i++)
        {
            cout << "Data: " << data[i] << endl;
        }
    }

    void operator>>(DSA &rhs)
    {
        for (int i = 0; i < size; i++)
        {
            cout << "Enter Elements" << endl;
            cin >> data[i];
        }
    }

    void insert(double val)
    {
        resize(getSize() + 1);

        for (int i = 0; i <= size; i++)
        {
            if (i == size - 1)
            {
                data[i] = val;
                break;
            }

            else if (data[i] >= val)
            {
                for (int j = size - 1; j > 0; j++)
                {
                    swap(data[j] < data[j - 1])
                }
                data[i] = val;
                break;
            }
        }
    }
};

int main(void)
{
}