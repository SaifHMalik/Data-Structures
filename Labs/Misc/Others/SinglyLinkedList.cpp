#include <iostream>
using namespace std;

struct node
{
    double data;
    node *next;
};

class linked_list
{
protected:
    node *head;
    node *tail;

public:
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }

    void addNode(double num)
    {
        node *tmp = new node;
        tmp->data = num;
        tmp->next = NULL;

        if (head == NULL)
        {
            head = tmp;
            tail = tmp;
        }

        tail->next = tmp;
        tail = tail->next;
    }

    void display()
    {
        node *tmp = new node;
        tmp = head;

        while (tmp != NULL)
        {
            cout << "Data: " << tmp->data << endl;
            tmp = tmp->next;
        }
    }
};

int main(void)
{
    int size;
    double elements;

    cout << "ENter Size" << endl;
    cin >> size;

    linked_list ob;

    for (int i = 0; i < size; i++)
    {
        cout << "Enter Element" << endl;
        cin >> elements;
        ob.addNode(elements);
    }

    ob.display();
}