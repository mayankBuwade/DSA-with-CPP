//circular linked list

#include<iostream>

using namespace std;

class Node {
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        next = this;
    }
    Node(int val, Node *next)
    {
        this->val = val;
        this->next = next;
    }
};

class CLL {
private:
    Node *head;
public:
    CLL();
    void insertAtHead(int);
    void insertAtTail(int);
    void insertAtIndex(int, int);
    void deleteAtIndex(int);
    int get(int);
    void print();
};

CLL::CLL() {
    head = NULL;
}

void CLL::insertAtHead(int val)
{
    if(!head) 
    {
        head = new Node(val);
        return;
    }
    Node *newHead = new Node(val, head);
    Node *temp = head;
    //iterating to the last node so can update its next pointer
    while(temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newHead;
    //updating current head
    head = newHead;
}

void CLL::insertAtTail(int val) 
{
    if(head == NULL) 
    {
        insertAtHead(val);
        return;
    }
    Node *tail = new Node(val, head);
    Node *temp = head;
    //iterating to the tail
    while(temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = tail;
}

void CLL::insertAtIndex(int index, int val)
{
    if(head == NULL)
    {
        return;
    }
    if(index == 0)
    {
        insertAtHead(val);
        return;
    }
    Node *temp = head;
    while(temp->next != head && --index)
    {
        temp = temp->next;
    }
    if(index != 0 && index != 1) 
    {
        cout<<"out of range"<<endl;
        return;
    }
    temp->next = new Node(val, temp->next);
}

void CLL::deleteAtIndex(int index)
{
    if(head == NULL)
    {
        return;
    }
    //deleting head
    if(index == 0)
    {
        if(head == NULL) return;
        if(head->next == head) 
        {
            delete head;
            head = NULL;
        }
        Node* newHead = head->next;
        Node* temp = head;
        while(temp->next != head)
        {
            temp = temp->next;
        }
        //updating next of the last node
        temp->next = newHead;
        delete head;
        head = newHead;
        return;
    }
    //delete at any indext other than head
    Node *temp = head;
    while(temp->next != head && --index)
    {
        temp = temp->next;
    }
    if(index != 0) 
    {
        cout<<"out of range"<<endl;
        return;
    }
    Node* deletingNode = temp->next;
    temp->next = deletingNode->next;
    delete deletingNode;
    return;
}

int CLL::get(int index)
{
    Node *temp = head;
    if(head == NULL)
    {
        cout<<"List is empty"<<endl;
        return -1;
    }
    while(index && temp->next != head)
    {
        temp = temp->next;
        --index;
    }
    if(index == 0)
    {
        return temp->val;
    }
    cout<<"out of range"<<endl;
    return -1;
}

void CLL::print()
{
    if(!head) return;
    Node *temp = head;
    cout<<temp->val<<" ";
    while(temp->next != head)
    {
        temp = temp->next;
        cout<<temp->val<<" ";
    }
    cout<<endl;
}

int main()
{
    system("cls");
    CLL l1;
    l1.insertAtTail(1);
    l1.insertAtTail(2);
    l1.insertAtTail(3);
    l1.insertAtTail(4);
    l1.insertAtHead(99);
    l1.insertAtIndex(0, 55);
    l1.deleteAtIndex(2);
    l1.print();
    cout<<l1.get(-1);
    return 0;
}