//
#include<iostream>

using namespace std;

class MyStack {
    private:
        int *arr;
        int maxSize;
        int currIndex;
    public:
        MyStack();
        ~MyStack();
        void push(int);
        int pop();
        void print();
};

MyStack::MyStack() {
    maxSize = 10;
    currIndex = 0;
    arr = new int[maxSize];
}

int MyStack::pop()
{
    if(currIndex == 0)
    {
        cout<<"Stack is empty"<<endl;
        return -1;
    }
    --currIndex;
    return arr[currIndex];
}

void MyStack::push(int val)
{
    if(maxSize == currIndex)
    {
        maxSize = maxSize * 2;
        arr = (int*) realloc(arr, maxSize);
    }
    arr[currIndex] = val;
    ++currIndex;
}

void MyStack::print()
{
    for(int i  = 0; i<currIndex; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

MyStack::~MyStack() {
    delete[] arr;
}

int main()
{
    system("cls");
   
    return 0;
}