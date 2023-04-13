//post-order traversal
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
    void postOrderTraversalRec(Node*);
    void postOrderTraversalLoop();
public:
    BT();
    void insertLevelWise(int);
    void postOrderTraversal();
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

void BT::postOrderTraversal()
{
    //postOrderTraversalRec(root); 
    postOrderTraversalLoop();
}

void BT::postOrderTraversalRec(Node *temp)
{
    if(temp == NULL) return;
    postOrderTraversalRec(temp->left);
    postOrderTraversalRec(temp->right);
    cout<<temp->val<<" ";
}

void BT::postOrderTraversalLoop()
{
   Node *temp = root;
   Node *prev = NULL;
   stack<Node *> s;
    do
    {
        while(temp != NULL)
        {
            s.push(temp);
            temp = temp->left;
        }

        while(temp == NULL && !s.empty())
        {
            temp = s.top();
            if(temp->right == NULL || temp->right == prev)
            {
                cout<<temp->val<<" ";
                s.pop();
                prev = temp;
                temp = NULL;
            }
            else
            {
                temp = temp->right;
            } 
        }
    } while(!s.empty());
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
    b.postOrderTraversal();
    return 0;
}