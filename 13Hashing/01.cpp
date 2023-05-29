//
#include<iostream>

using namespace std;

class Node {
    int key;
    int value;
    Node* next;
public:
    Node(int, int);
    friend class HashTable;
};

Node::Node(int key, int value)
{
    this->key = key;
    this->value = value;
    this->next  = nullptr;
}

class HashTable
{
private:
    int size;
    Node **table;
    int hashFunction(int key);
public:
    HashTable(int);
    void insert(int, int);
    int get(int);
    void remove(int);
};

int HashTable::hashFunction(int key)
{
    return key%size;
}

HashTable::HashTable(int size)
{
    this->size = size;
    table = new Node*[size]();
}

void HashTable::insert(int key, int value)
{
    int index = hashFunction(key);
    Node *newNode = new Node(key, value);

    if(table[index] == nullptr)
    {
        table[index] = newNode;
    }
    else
    {
        //O(n)
        // Node* current = table[index];
        // while (current->next)
        // {
        //     current = current->next;
        // }
        // current->next = newNode;
        Node* current = table[index];
        table[index] = newNode;
        newNode->next =  current;
    }
}

int HashTable::get(int key)
{
    int index = hashFunction(key);
    Node* current = table[index];
    while (current != nullptr)
    {
        if(current->key == key)
        {
            return current->value;
        }
        current = current->next;
    }
    cout<<"key not found"<<endl;
    return -1;
}

void HashTable::remove(int key)
{
    int index = hashFunction(key);
    Node *current = table[index];
    Node *prev = nullptr;

    while (current != nullptr)
    {
        if(current->key == key)
        {
            if(prev == nullptr)
            {
                table[index] = current->next;
            }
            else
            {
                 prev->next = current->next;
            }
            delete current;
            return;
        }
        prev = current;
        current = current->next;
    }
}


int main()
{
    system("cls");
    HashTable hs(10);
    hs.insert(0, 99);
    hs.insert(10, 57);
    hs.insert(90, 157);
    hs.insert(57, 87);
    cout<<hs.get(10)<<endl;
    cout<<hs.get(0)<<endl;
    cout<<hs.get(90)<<endl;
    cout<<hs.get(57)<<endl;
    hs.remove(0);
    cout<<hs.get(0)<<endl;
    cout<<hs.get(10)<<endl;
    return 0;
}