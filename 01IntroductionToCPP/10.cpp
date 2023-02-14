//
#include<iostream>

using namespace std;

template <typename T>
class MyStack {
    private:
        T *arr;
        int maxSize;
        int currIndex;
    public:
        MyStack();
        void push(T);
        T pop();
        void print();
};

template <typename T>
MyStack<T>::MyStack() {
    maxSize = 10;
    currIndex = 0;
    arr = new T[maxSize];
}

template <typename T>
T MyStack<T>::pop()
{
    if(currIndex == 0)
    {
        cout<<"Stack is empty"<<endl;
        return -1;
    }
    --currIndex;
    return arr[currIndex];
}

template <typename T>
void MyStack<T>::push(T val)
{
    if(maxSize == currIndex)
    {
        maxSize = maxSize * 2;
        arr = (T*) realloc(arr, maxSize);
    }
    arr[currIndex] = val;
    ++currIndex;
}

template <typename T>
void MyStack<T>::print()
{
    for(int i  = 0; i<currIndex; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    system("cls");
    MyStack <char>s;
    MyStack <double>t;
    s.push('a');
    s.push('@');
    s.push('b');
    s.push(')');
    s.print();
    t.push(5.78);
    t.push(9.078);
    t.print();
    return 0;
}