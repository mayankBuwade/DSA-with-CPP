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
        cout<<root->key;
        helperIOT(root->right);
    }
}

void AVLTree::insert(int key)
{
    root = helperInsert(root, key);
}

int AVLTree::getHeight(Node* root)
{
    if(root) return 0;
    return  root->height;
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

    //left left
    //right right
    //left right
    //rigth left

}

int main()
{
    system("cls");
    
    return 0;
}