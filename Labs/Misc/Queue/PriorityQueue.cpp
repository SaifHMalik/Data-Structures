#include <iostream>
using namespace std;

struct node
{
    int priority;
    int info;
    struct node *next;
};

class PriorityQueue
{
private:
    node *head;

public:
    PriorityQueue()
    {
        head = NULL;
    }

    void insert(int item, int priority)
    {
        node *tmp, *q;
        tmp = new node;

        tmp->info = item;
        tmp->priority = priority;

        if (head == NULL || priority < head->priority)
        {
            tmp->next = head;
            head = tmp;
        }

        else
        {
            q = head;
            while (q->next != NULL && q->next->priority <= priority)
            {
                q = q->next;
            }

            tmp->next = q->next;
            q->next = tmp;
        }
    }

    void del()
    {
        node *tmp;
        if (head == NULL)
        {
            cout << "Queu Underflow" << endl;
        }

        else
        {
            tmp = head;
            cout << "Deleted Item is: " << tmp->info << endl;
            head = head->next;
            free(tmp);
        }
    }

    void display()
    {
        node *ptr;
        ptr = head;
        if (head == NULL)
        {
            cout << "Queue is Empty" << endl;
        }

        else
        {
            cout << "Queue is :\n";
            cout << "Priority: " << endl;
            cout << "Item\n ";

            while (ptr != NULL)
            {
                cout << ptr->priority << endl;
                cout << ptr->info << endl;

                ptr = ptr->next;
            }
        }
    }
};

int main(void)
{
    int choice, item, priority;

    PriorityQueue pq;

    do
    {

        cout << "1.Insert\n";

        cout << "2.Delete\n";

        cout << "3.Display\n";

        cout << "4.Quit\n";

        cout << "Enter your choice : ";

        cin >> choice;

        switch (choice)

        {

        case 1:

            cout << "Input the item value to be added in the queue : ";

            cin >> item;

            cout << "Enter its priority : ";

            cin >> priority;

            pq.insert(item, priority);

            break;

        case 2:

            pq.del();

            break;

        case 3:

            pq.display();

            break;

        case 4:

            break;

        default:

            cout << "Wrong choice\n";
        }

    }

    while (choice != 4);
}