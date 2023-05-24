//
#include<iostream>

using namespace std;

class PriorityQueue {
private:
    int *heap;
    int capacity;
    int size;
    int leftChild(int);
    int rightChild(int);
    int parent(int);
    void heapifyUp(int);
    void heapifyDown(int);
    void resize();
public:
    PriorityQueue();
    void push(int);
    int pop();
    int top();
    int isEmpty();
    int getSize();
};

//private helper
void PriorityQueue::resize()
{
    capacity *= 2;
    int *newHeap = new int[capacity];
    for(int i = 0; i<size; i++)
    {
        newHeap[i] = heap[i];
    }
    delete[] heap;
    heap = newHeap;
}

int PriorityQueue::leftChild(int i)
{
    return (i*2) + 1;
}

int PriorityQueue::rightChild(int i)
{
    return (i*2) + 2;
}
int PriorityQueue::parent(int i)
{
    return (i-1)/2;
}

void PriorityQueue::heapifyDown(int index)
{
    while(true)
    {
        int left = leftChild(index);
        int right = rightChild(index);
        int largest = index;

        if(left < size && heap[left] > heap[largest])
            largest = left;
        if(right < size && heap[right] > heap[largest])
            largest = right;
        if(largest != index)
        {
            swap(heap[index], heap[largest]);
            index = largest;
        }
        else break;
    }
}

void PriorityQueue::heapifyUp(int index)
{
    int parentI = parent(index);
    while(index > 0 && heap[parentI] < heap[index])
    {
        swap(heap[index], heap[parentI]);
        index = parentI;
        parentI = parent(index);
    }
}


//public

PriorityQueue::PriorityQueue()
{
    capacity = 10;
    size = 0;
    heap = new int[capacity];
}

void PriorityQueue::push(int ele)
{
    if(size == capacity) resize();
    heap[size] = ele;
    heapifyUp(size);
    ++size;
}

int PriorityQueue::pop()
{
    if(size == 0)
    {
        cout<<"Priority queue is empty"<<endl;
        return -1;
    }
    int topElement = heap[0];
    heap[0] = heap[size-1];
    --size;
    heapifyDown(0);
    return topElement;
}

int PriorityQueue::isEmpty()
{
    if(size == 0)
        return 1;
    return 0;
}

int PriorityQueue::getSize()
{
    return size;
}

int PriorityQueue::top()
{
    if(size == 0)
    {
        cout<<"Priority queue is empty"<<endl;
        return -1;
    }
    return heap[0];
}

int main()
{
    system("cls");
    PriorityQueue pq;
    pq.push(54);
    pq.push(99);
    pq.push(75);
    pq.push(57);
    pq.push(1000);
    cout<<pq.top()<<endl;
    pq.pop();
    cout<<pq.top()<<endl;
    return 0;
}