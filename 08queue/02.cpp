// Queue implementation using circular array
//
#include<iostream>

using namespace std;

class Queue
{
private:
    int *arr;
    int front;
    int rear;
    int currSize;
    int maxSize;
public:
    Queue(int);
    void enQueue(int);
    int deQueue();
    int frontVal();
    int size();
    bool isEmpty();
    bool isFull();
};

Queue::Queue(int val = 5)
{
    arr = new int[val];
    maxSize = val;
    rear = maxSize - 1;
    front = 0;
    currSize = 0;
}

bool Queue::isEmpty()
{
    return currSize == 0;
}

bool Queue::isFull()
{
    return currSize == maxSize;
}

void Queue::enQueue(int val)
{
    if(isFull())
    {
        cout<<"Queue is full"<<endl;
        return;
    }
    rear = (rear+1)%maxSize;
    arr[rear] = val;
    ++currSize;
}

int Queue::deQueue()
{
    if(isEmpty())
    {
        cout<<"Queue is empty"<<endl;
        return -1;
    }
    int temp = front;
    front = (front + 1)%maxSize;
    --currSize;
    return arr[temp];
}

int Queue::frontVal()
{
    if(isEmpty())
    {
        cout<<"Queue is empty"<<endl;
        return -1;
    }
    return arr[front];
}

int Queue::size()
{
    return currSize;
}

int main()
{
    system("cls");
    Queue q(6);
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);
    q.enQueue(6);
    q.deQueue();
    q.deQueue();
    q.deQueue();
    q.deQueue();
    q.deQueue();
    q.deQueue();
    q.enQueue(7);
    cout<<q.frontVal()<<endl;
    return 0;
}