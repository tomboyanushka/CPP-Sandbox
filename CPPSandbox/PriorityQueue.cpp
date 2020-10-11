#include <iostream>

using namespace std;


template<class T>
class PriorityQueue // FIPO
{
private:
	template <typename T>
	struct node
	{
		int priority;
		T info;
		struct node* link;
	};

	node<T>* front;

public:
	PriorityQueue()
	{
		front = nullptr;
	}

	void Enqueue(T item, int priority)
	{
		node<T> *temp, *q;
		temp = new node<T>;
		temp->info = item;
		temp->priority = priority;
		if (front == NULL || priority < front->priority)
		{
			temp->link = front;
			front = temp;
		}
		else
		{
			q = front;
			while (q->link != NULL && q->priority <= priority)
			{
				q = q->link;
			}
			temp->link = q->link;
			q->link = temp;
			
		}
	}

	void Dequeue()
	{
		node<T>* temp;
		if (front == NULL)
		{
			cout << "Queue is empty. " << endl;
		}
		else
		{
			// priority queue is sorted based on highest to lowest priority
			temp = front;
			cout << "Dequeued item is of highest priority. It is: " << temp->info << endl;
			front = front->link;
			free(temp);
		}
	}

	void Print()
	{
		node<T>* ptr;
		ptr = front;
		if (front == NULL)
		{
			cout << "Queue is empty. " << endl;
		}
			
		else
		{
			cout << "Queue is :\n";
			cout << "Priority       Item\n";
			while (ptr != NULL)
			{
				cout << ptr->priority << "                 " << ptr->info << endl;
				ptr = ptr->link;
			}
		}
	}
};

int PQmain()
{
	int priority, choice;
	int item;
	PriorityQueue<int> priorityQueue;
	do 
	{
		cout << "1.Insert" << endl;
		cout << "2.Delete" << endl;
		cout << "3.Display" << endl;
		cout << "4.Quit" << endl;
		cout << "Enter your choice : ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case 1:
			cout << "Input the item value to be added in the queue: ";
			cin >> item;
			cout << "Its priority is: ";
			cin >> priority;
			priorityQueue.Enqueue(item, priority);
			break;
		case 2:
			priorityQueue.Dequeue();
			break;
		case 3:
			priorityQueue.Print();
			break;
		case 4:
			break;
		default:
			cout << "Wrong choice\n";
		}
	} 
	while (choice != 4);

	return 0;
}