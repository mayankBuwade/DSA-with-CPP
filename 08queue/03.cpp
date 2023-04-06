//
#include<iostream>

using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        next = NULL;
    }
    Node(int val, Node *next)
    {
        this->val = val;
        this->next = next;
    }
};

class Queue
{
private:
    Node *head;
    Node *tail;
    int totalNodes;
    void addAtTail(int);
public:
    Queue();
    int size();
    bool isEmpty();
    void enQueue(int);
    int frontVal();
    int deQueue();
};
 
void Queue::addAtTail(int val)
{
    if(head == NULL)
    {
        head = new Node(val);
        tail = head;
    }
    else
    {
        tail->next = new Node(val);
        tail = tail->next;
    }
    ++totalNodes;
}

Queue::Queue()
{
    totalNodes = 0;
    head = NULL;
    tail = NULL;
}

bool Queue::isEmpty()
{
    if(head == NULL) return true;
    return false;
}

int Queue::size()
{
    return totalNodes;
}

void Queue::enQueue(int val)
{
    addAtTail(val);
}

int Queue::frontVal()
{
    if(isEmpty())
    {
        cout<<"Queue is empty"<<endl;
        return -1;
    }
    return head->val;
}

int Queue::deQueue()
{
    if(isEmpty())
    {
        cout<<"Queue is empty"<<endl;
        return -1;
    }
    int temp = head->val;
    Node *deleteNode = head;
    head = head->next;
    delete deleteNode;
    return temp;
}

int main()
{
    system("cls");
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);
    q.enQueue(6);
    while(!q.isEmpty())
    {
        cout<<q.frontVal()<<" ";
        q.deQueue();
    }
    return 0;
}