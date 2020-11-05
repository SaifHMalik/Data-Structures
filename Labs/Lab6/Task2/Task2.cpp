#include<iostream>

using namespace std;


struct node {
	int data;
	node *next;
	node *prev;
};

class linked_list {
private:
	node *head, *tail;
public:
	linked_list() {
		head = NULL;
		tail = NULL;
	}

	void add_node(int num) {
		node *tmp = new node;

		tmp->data = num;
		tmp->next = NULL;

		if (head == NULL) {
			head = tmp;
			tail = tmp;
		}

		else {

			tmp->prev = tail;
			tail->next = tmp;
			tail = tail->next;
		}
	}

	void HijackCheck() {
		node *tmp = head;
		int count = 0;
		while (tmp != NULL) {

			if (tmp->data == 0) {
				cout << "Hijack Cabin Found at Cabin: " << count << endl;
				break;
			}

			tmp = tmp->next;
			count++;
		}


		while (tmp != head) {
			tmp = tmp->prev;
		}

		count = 0;
		while (tmp != NULL){

			if (tmp->data == 10) {
				cout << "Hijack Member Found at Cabin: " << count << endl;
				break;
			}

			tmp = tmp->next;
			count++;
		}


	}

	void Display() {
		node *tmp = head;

		while (tmp != NULL) {
			cout << "Data: " << tmp->data;

			tmp = tmp->next;
		}
	}


};


int main(void) {
	int size;
	int num;
	cout << "Enter Number of Nodes: " << endl;
	cin >> size;
	linked_list ob;

	cout << "Enter '0' for Hijack Cabin" << endl;
	cout << "Enter '10' for Hijack Member" << endl;

	for (int i = 0; i < size; i++) {
		cout << "Enter Element of Node: " << endl;
		cin >> num;

		ob.add_node(num);
	}


	ob.HijackCheck();
	cin >> num;
}