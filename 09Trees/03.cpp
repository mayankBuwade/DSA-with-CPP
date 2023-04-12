//in-order traversal
#include<iostream>
#include<stack>
#include<queue>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node(int val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }

};

class BT {
private:
    Node *root;
    void preOrderTraversalRec(Node*);
    void preOrderTraversalLoop();
public:
    BT();
    void insertLevelWise(int);
    void preOrderTraversal();
};

BT::BT() {
    root = NULL;
}

void BT::insertLevelWise(int val)
{
    if(root == NULL)
    {
        root = new Node(val);
        return;
    }
    queue<Node*> q;
    q.push(root);
    
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if(temp->left == NULL)
        {
            temp->left = new Node(val);
            return;
        }  
        else {
            q.push(temp->left);
        }
        if(temp->right == NULL)
        {
            temp->right = new Node(val);
            return;
        }
        else
        {
            q.push(temp->right);
        }
    }
}

void BT::preOrderTraversal()
{
    //preOrderTraversalRec(root);
    preOrderTraversalLoop();
}

void BT::preOrderTraversalRec(Node *temp)
{
    if(temp == NULL) return;
    cout<<temp->val<<" ";
    preOrderTraversalRec(temp->left);
    preOrderTraversalRec(temp->right);
}

void BT::preOrderTraversalLoop()
{
    Node *temp = root;
    stack<Node *> s;

    while(true)
    {
        while (temp != NULL)
        {
            cout<<temp->val<<" ";
            s.push(temp);
            temp = temp->left;
        }
        if(s.empty()) return;
        temp = s.top();
        s.pop();
        temp = temp->right; 
    }
}

int main()
{
    system("cls");
    BT b;
    b.insertLevelWise(1);
    b.insertLevelWise(2);
    b.insertLevelWise(3);
    b.insertLevelWise(4);
    b.insertLevelWise(5);
    b.preOrderTraversal();
    return 0;
}