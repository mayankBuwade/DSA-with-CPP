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

Node* insertAtHead(Node *head, int val)
{
    Node *newHead = new Node(val, head);
    Node *temp = head;
    //iterating to the last node so can update its next pointer
    while(temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newHead;
    return newHead;
}

void insertAtTail(Node *head, int val)
{
    Node *tail = new Node(val, head);
    Node *temp = head;
    while(temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = tail;
}

Node* insertAtIndex(Node *head, int val, int index)
{
    if(head == NULL)
    {
        return NULL;
    }
    if(index == 0)
    {
        return insertAtHead(head, val);
    }
    Node *temp = head;
    while(temp->next != head && --index)
    {
        temp = temp->next;
    }
    if(index != 0 && index != 1) 
    {
        cout<<"out of range"<<endl;
        return head;
    }
    temp->next = new Node(val, temp->next);
    return head;
}

Node* deleteHead(Node* head)
{
    if(head == NULL) return head;
    if(head->next == head) 
    {
        delete head;
        return NULL;
    }
    Node* newHead = head->next;
    Node* temp = head;
    while(temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newHead;
    delete head;
    return newHead;
}

Node* deleteTail(Node *head)
{
    if(head == NULL) return head;
    if(head->next == head) 
    {
        delete head;
        return NULL;
    }
    Node* temp = head;
    while(temp->next->next != head)
    {
        temp = temp->next;
    }
    Node* deletingNode = temp->next;
    temp->next = deletingNode->next;
    delete deletingNode;
    return head;
}

Node* deleteAtIndex(Node *head, int index)
{
    if(head == NULL)
    {
        return NULL;
    }
    if(index == 0)
    {
        return deleteHead(head);
    }
    Node *temp = head;
    while(temp->next != head && --index)
    {
        temp = temp->next;
    }
    if(index != 0) 
    {
        cout<<"out of range"<<endl;
        return head;
    }
    Node* deletingNode = temp->next;
    temp->next = deletingNode->next;
    delete deletingNode;
    return head;
}

void printCLL(Node *head)
{
    Node* temp = head;
    if(head == NULL) return;
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
    //system("cls");
    Node *head;
    head = new Node(5);
    head = insertAtHead(head, 10);
    head = insertAtHead(head, 15);
    head = insertAtHead(head, 20);
    head = insertAtHead(head, 25);
    printCLL(head);
    //head = deleteHead(head);
    head = deleteAtIndex(head, 5);
    printCLL(head);
    return 0;
}