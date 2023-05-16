//AVL  tree
#include<iostream>

using namespace std;

class Node {
    int key;
    Node *left;
    Node *right;
    int height;
public: 
    Node(int val)
    {
        key = val;
        left = NULL;
        right = NULL;
        height = 1;
    }
friend class AVLTree;
};

class AVLTree {
private:
    Node *root;
    void helperIOT(Node*);
    Node* helperInsert(Node*, int);
    int getHeight(Node*);
    int getBalance(Node*);
    Node* rightRotate(Node *);
    Node* leftRotate(Node *);

public:
    AVLTree();
    void inOrderTraversal();
    void insert(int);
};

AVLTree::AVLTree() {
    root = NULL;
}

void AVLTree::inOrderTraversal()
{
    helperIOT(root);
}

void AVLTree::helperIOT(Node* root)
{
    if(root)
    {
        helperIOT(root->left);
        cout<<root->key<<" ";
        helperIOT(root->right);
    }
}

void AVLTree::insert(int key)
{
    root = helperInsert(root, key);
}

int AVLTree::getHeight(Node* root)
{
    if(root == NULL) return 0;
    return  root->height;
}

int AVLTree::getBalance(Node *root)
{
    if(root == NULL) return 0;
    return getHeight(root->left) - getHeight(root->right);
}

Node* AVLTree::rightRotate(Node* root)
{
    Node* temp = root->left->right;
    Node* newRoot = root->left;
    newRoot->right = root;
    root->left = temp;
    return newRoot;
}

Node* AVLTree::leftRotate(Node* root)
{
    Node* temp = root->right->left;
    Node* newRoot = root->right;
    newRoot->left = root;
    root->right = temp;
    return newRoot;
}


Node* AVLTree::helperInsert(Node* root, int key)
{
    Node* newNode = new Node(key);
    if(root == NULL) return newNode;

    if(key < root->key)
    {
        root->left = helperInsert(root->left, key);
    }
    else if(key > root->key)
    {
        root->right = helperInsert(root->right, key);
    }
    else return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balance = getBalance(root);
    //we are talking about loads
    //left left
    if(balance > 1 && key < root->left->key)
        return rightRotate(root);
    //right right
    if(balance < -1 && key > root->right->key)
        return leftRotate(root);
    //left right
    if(balance > 1 && key > root->left->key)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    //rigth left
    if(balance < -1 && key < root->right->key)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

int main()
{
    system("cls");
    AVLTree tree;
    tree.insert(10);
    tree.insert(9);
    tree.insert(8);
    tree.insert(15);
    tree.insert(1);
    tree.inOrderTraversal();
    return 0;
}