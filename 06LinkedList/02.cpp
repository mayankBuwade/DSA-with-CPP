//doubly linked list
#include<iostream>

using namespace std;

class Node {
public:
    int val;
    Node *prev, *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
    Node(Node *prev, int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = prev;
        prev->next = this;
    }
    Node(int val, Node *next)
    {
        this->val = val;
        this->next = next;
        this->prev = NULL;
        next->prev = this;
    }
    Node(Node *prev, int val, Node *next)
    {
        this->val = val;
        this->prev = prev;
        this->next = next;
        prev->next = this;
        next->prev = this;
    }
};

class DLL {
private:
    Node *head;
    Node *tail;
    int totalNodes;
public:
    DLL();
    void addAtHead(int);
    void addAtTail(int);
    void printDLL();
    int get(int);
    void addAtIndex(int, int);
    void deleteAtIndex(int);
};

DLL::DLL() {
    head = NULL;
    tail = NULL;
    totalNodes = 0;
}

void DLL::addAtHead(int val)
{
    if(head == NULL)
    {
        head = new Node(val);
        tail = head;
    }
    else head = new Node(val, head);
    ++totalNodes;
}

void DLL::addAtTail(int val)
{
    if(head == NULL) return addAtHead(val);
    tail = new Node(tail, val);
    ++totalNodes;
}

int DLL::get(int index)
{
    if(index<0 || index>=totalNodes)
    {
        cout<<"out of range";
        return -1;
    }
    Node *temp;
    if(index<totalNodes/2)
    {
        temp = head;
        while(index)
        {
            temp = temp->next;
            --index;
        }
    }
    else
    {
        temp = tail;
        index = totalNodes - index - 1;
        while(index)
        {
            temp = temp->prev;
            --index;
        }
    }
    return temp->val;
}

void DLL::printDLL()
{
    if(head == NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    Node *temp = head;
    while (temp)
    {
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{
    system("cls");
    DLL l1;
    l1.addAtTail(5);
    l1.addAtTail(9);
    l1.addAtTail(15);
    l1.addAtHead(7);
    l1.printDLL();
    cout<<l1.get(2);
    return 0;
}