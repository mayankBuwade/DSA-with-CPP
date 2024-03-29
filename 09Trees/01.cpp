//level order traversal
#include<iostream>
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
public:
    BT();
    void insertLevelWise(int);
    void levelOrderTraversal();
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

void BT::levelOrderTraversal()
{
    if(root == NULL) return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        cout<<temp->val<<" ";
        if(temp->left != NULL) q.push(temp->left);
        if(temp->right != NULL) q.push(temp->right);
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
    b.levelOrderTraversal();
    cout<<endl;
    return 0;
}