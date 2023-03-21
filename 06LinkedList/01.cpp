//
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

int main()
{
    system("cls");
    LinkedList l1;
    l1.addAtTail(5);
    l1.addAtTail(9);
    l1.addAtTail(7);
    l1.addAtTail(15);
    l1.addAtHead(99);
    l1.printLS();
    l1.deleteAtIndex(4);
    l1.addAtTail(909);
    l1.printLS();
    return 0;
}