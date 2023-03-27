//Check whether the given linked list is either NULL-terminated or ends in a cycle(cyclic).
//floyd algorithm
#include<iostream>

using namespace std;


class Node {
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

bool isNUllTerminated(Node *head)
{
    if(!head || !head->next) return true;
    Node *slowPtr = head;
    Node *fastPtr = head->next->next;
    while(slowPtr && fastPtr && slowPtr->next && fastPtr->next)
    {
        if(slowPtr == fastPtr) return false;
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }
    return true;
}


int main()
{
    system("cls");
    Node *a, *b, *c, *d, *e, *f, *g;
    g = new Node(7);
    f = new Node(6, g);
    e = new Node(5, f);
    d = new Node(4, e);
    c = new Node(3, d);
    b = new Node(2, c);
    a = new Node(1, b);
    g->next = d;
    cout<<isNUllTerminated(a);
    return 0;
}