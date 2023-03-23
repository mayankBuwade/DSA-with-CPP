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

void DLL::addAtIndex(int index, int val)
{
    if(index<0 || index>=totalNodes)
    {
        cout<<"out of range";
        return;
    }
    if(index == 0) return addAtHead(val);
    if(index == totalNodes - 1) return addAtTail(val);
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
    temp = new Node(temp->prev, val, temp);
    ++totalNodes;
}

void DLL::deleteAtIndex(int index)
{
    if(index<0 || index>=totalNodes)
    {
        cout<<"out of range";
        return;
    }
    Node *deleteNode;
    if(index == 0)
    {
        deleteNode = head;
        head = head->next;
        head->prev = NULL;
    }
    else
    {
        if(index<totalNodes/2)
        {
            deleteNode = head;
            while(index)
            {
                deleteNode = deleteNode->next;
                --index;
            }
        }
        else
        {
            deleteNode = tail;
            index = totalNodes - index - 1;
            while(index)
            {
                deleteNode = deleteNode->prev;
                --index;
            }
        }
        if(deleteNode == tail)
        {
            tail = deleteNode->prev;
            tail->next = NULL;
        }
        else
        {
            deleteNode->prev->next = deleteNode->next;
            deleteNode->next->prev = deleteNode->prev;
        }
    }
    delete deleteNode;
    --totalNodes;
}

int main()
{
    system("cls");
    DLL l1;
    l1.addAtTail(5);
    l1.addAtTail(9);
    l1.addAtTail(15);
    l1.addAtTail(7);
    l1.addAtTail(700);
    l1.addAtTail(150);
    l1.printDLL();
    l1.deleteAtIndex(2);
    l1.printDLL();
    return 0;
}