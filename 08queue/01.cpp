//EnQueue(int data): Inserts an element at the end of the queue
//int DeQueue(): Removes and returns the element at the front of the queue
//int Front(): Returns the element at the front without removing it
//int QueueSize(): Returns the number of elements stored in the queue
//int IsEmptyQueueQ: Indicates whether no elements are stored in the queue or not

//
#include<iostream>
#define MAX_SIZE 5
using namespace std;

class Queue
{
private:
    int *arr;
    int front;
    int rear;
public:
    Queue();
    void enQueue(int);
    int deQueue();
    int frontVal();
    int size();
    bool isEmpty();
    bool isFull();
};

Queue::Queue()
{
    arr = new int[MAX_SIZE];
    rear = -1;
    front = -1;
}

bool Queue::isEmpty()
{
    return rear - front == 0;
}

bool Queue::isFull()
{
    return rear+1 == MAX_SIZE;
}

void Queue::enQueue(int val)
{
    if(isFull())
    {
        cout<<"Queue is full"<<endl;
        return;
    }
    ++rear;
    arr[rear] = val;
}

int Queue::deQueue()
{
    if(isEmpty())
    {
        cout<<"Queue is empty"<<endl;
        return -1;
    }
    ++front;
    return arr[front];
}

int Queue::frontVal()
{
    if(isEmpty())
    {
        cout<<"Queue is empty"<<endl;
        return -1;
    }
    return arr[front+1];
}

int Queue::size()
{
    return rear - front;
}

int main()
{
    system("cls");
    Queue q;
    q.enQueue(5);
    q.enQueue(51);
    q.enQueue(533);
    q.deQueue();
    q.deQueue();
    q.deQueue();
    q.enQueue(5);
    q.enQueue(7);
    q.enQueue(9);
    
    return 0;
}