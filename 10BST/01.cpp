//Binary Search Tree
//Insertion
#include <iostream>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

class BST {
private:
    Node *root;
public:
    BST();
    void insert(int);
    void levelOrderTraversal();
    bool isExist(int);
    int findMin();
    int findMax();
};

BST::BST()
{
    root = NULL;
}

void BST::levelOrderTraversal()
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
    cout<<endl;
}

void BST::insert(int val)
{
    Node *newNode = new Node(val);
    if(root == NULL)
    {
        root = newNode;
        return;
    }
    Node *temp = root;
    
    while(temp)
    {
        //move left
        if(temp->val > val)
        {
            if(temp->left == NULL)
            {
                temp->left = newNode;
                return;
            }
            temp = temp->left;
        }
        //move right
        else
        {
            if(temp->right == NULL)
            {
                temp->right = newNode;
                return;
            }
            temp = temp->right;
        }
    }
}

bool BST::isExist(int val)
{
    Node* temp = root;
    while(temp)
    {
        if(temp->val == val) return true;
        if(temp->val > val) temp = temp->left;
        else temp = temp->right;
    }
    return false;
}

int BST::findMin()
{
    if(root == NULL)
    {
        cout<<"Tree is empty"<<endl;
        return -1;
    }
    Node *temp = root;
    while(temp)
    {
        if(temp->left == NULL)
        {
            break;
        }
        temp = temp->left;
    }
    return temp->val;
    
}

int BST::findMax()
{
    if(root == NULL)
    {
        cout<<"Tree is empty"<<endl;
        return -1;
    }
    Node *temp = root;
    while(temp)
    {
        if(temp->right == NULL)
        {
            break;
        }
        temp = temp->right;
    }
    return temp->val;
    
}

int main()
{
    system("cls");
    BST bst;
    bst.insert(8);
    bst.insert(7);
    bst.insert(99);
    bst.insert(-1);
    bst.insert(101);
    bst.insert(57);
    bst.insert(-2000);
    bst.insert(2000);
    cout<<bst.findMin()<<endl;
    cout<<bst.findMax()<<endl;
    return 0;
}