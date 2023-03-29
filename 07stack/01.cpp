//stack implementation using array
#include<iostream>
#define MAX_SIZE 10

using namespace std;

class Stack {
private: 
int arr[MAX_SIZE];
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
}

bool Stack::isEmpty()
{
    if(currI == -1) return true;
    return false;
}

void Stack::push(int val)
{
    if(currI+1 == MAX_SIZE)
    {
        cout<<"Stack is full"<<endl;
        return;
    }
    ++currI;
    arr[currI] = val;
}

int Stack::top()
{
    if(isEmpty())
    {
        cout<<"stack is empty"<<endl;
        return -1;
    }
    return arr[currI];
}

void Stack::pop()
{
    if(isEmpty()) 
    {
        cout<<"stack is empty"<<endl;
        return;
    }
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