//check if it is a balance binary search tree or not
#include<iostream>
 
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

int getHeight(Node *root)
{
    if(root == NULL) return 0;
    return 1 + max(getHeight(root->left), getHeight(root->right));
}


bool isBalanced(Node *root)
{
    if(root == NULL) return true;

    int leftTreeHeight = getHeight(root->left);
    int rightTreeHeight = getHeight(root->right);

    if(abs(leftTreeHeight - rightTreeHeight) > 1) return false;
    return isBalanced(root->left) && isBalanced(root->right);
}



int main()
{
    system("cls");
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    
    cout<<isBalanced(root);
    return 0;
}