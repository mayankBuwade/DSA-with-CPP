//stack implementation using linked list
#include<iostream>

using namespace std;

class Node {
public:
    int val;
    Node *next;
    Node(int val) {
        this->val = val;
        next = NULL;
    };
    Node(int val, Node* next)
    {
        this->val = val;
        this->next = next;
    }
};

class LinkedList {
private:
    Node *head;
    Node *tail;
    int totalNodes;
public:
    LinkedList();
    void addAtHead(int);
    void addAtTail(int);
    void printLS();
    int get(int);
    void addAtIndex(int, int);
    void deleteAtIndex(int);
    void deleteLinkedList();
};

LinkedList::LinkedList()
{
    head = NULL;
    tail = NULL;
    totalNodes = 0;
}

void LinkedList::addAtHead(int val)
{
    if(head == NULL)
    {
        head = new Node(val);
        tail = head;
    }
    else {
        head = new Node(val, head);
    }
    ++totalNodes;
}   

void LinkedList::addAtTail(int val)
{
    if(head == NULL) return addAtHead(val);
    tail->next = new Node(val);
    tail = tail->next;
    ++totalNodes;
}

void LinkedList::printLS()
{
    if(head == NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    Node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int LinkedList::get(int index)
{
    if(index<0 || index>=totalNodes)
    {
        cout<<"out of range";
        return -1;
    }
    Node *temp = head;
    while(index)
    {
        temp=temp->next;
        --index;
    }
    return temp->val;
}

void LinkedList::addAtIndex(int index, int val)
{
    if(index<0 || index>=totalNodes)
    {
        cout<<"out of range";
        return;
    }
    if(index == 0) return addAtHead(val);
    if(index == totalNodes - 1) return addAtTail(val);
    Node *temp = head;
    while(--index)
    {
        temp = temp->next;
    }
    temp->next = new Node(val, temp->next);
    ++totalNodes;
}

void LinkedList::deleteAtIndex(int index)
{
    if(index<0 || index>=totalNodes)
    {
        cout<<"out of range";
        return;
    }
    Node *temp = head;
    if(index == 0)
    {
        head = head->next;
        delete temp;
    }
    else 
    {
        while(--index)
        {
            temp = temp->next;
        }
        if(temp->next == tail)
        {
            tail = temp;
        }
        Node *deletingNode = temp->next;
        temp->next = deletingNode->next;
        delete deletingNode;
        --totalNodes;
    }
}

void LinkedList::deleteLinkedList()
{
    while(head)
    {
        Node *deleteNode = head;
        head = head->next;
        delete deleteNode;
    }
    totalNodes = 0;
    head = NULL;
    tail = NULL;
}

// main code starts here
class Stack {
private: 
    LinkedList *s;
    int currI;
public:
    Stack();
    bool isEmpty();
    void push(int);
    int top();
    void pop();
    int getSize();
};

Stack::Stack() 
{
    currI = -1;
    s = new LinkedList();
}

bool Stack::isEmpty()
{
    if(currI == -1) return true;
    return false;
}

void Stack::push(int val)
{
    ++currI;
    s->addAtTail(val);
}

int Stack::top()
{
    if(isEmpty())
    {
        cout<<"stack is empty"<<endl;
        return -1;
    }
    return s->get(currI);
}

void Stack::pop()
{
    if(isEmpty()) 
    {
        cout<<"stack is empty"<<endl;
        return;
    }
    s->deleteAtIndex(currI);
    --currI;
}

int Stack::getSize()
{
    return currI+1;
}


int main()
{
    system("cls");
    Stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    s1.push(6);
    s1.push(7);
    s1.push(8);
    s1.push(9);
    s1.push(10);
    cout<<s1.top()<<endl;
    s1.pop();
    cout<<s1.top()<<endl;
    cout<<s1.getSize()<<endl;
    return 0;
}