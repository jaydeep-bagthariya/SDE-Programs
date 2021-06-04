//inorder successor 

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int data) : data{data}, left{NULL}, right{NULL}{}
};

Node* find(Node* root, int val)
{
    if(root->data == val) return root;
    Node* newNode;
    if(root->data > val) newNode = find(root->left,val);
    else newNode = find(root->right,val);
    return newNode;
}
Node* findMin(Node* root)
{
    if(root->left == NULL) return root;
    return findMin(root->left);
}
Node* getSuccessor(Node* root, int val)
{
    Node* curr = find(root,val);

    //case 1: node has right substree
    if(curr->right != NULL)
        return findMin(curr->right);
    
    //case 2: No right substree
    Node* successor = NULL;
    Node* ancestor = root;
    while(curr->data != ancestor->data)
    {
        if(curr->data < ancestor->data)
        {
            successor = ancestor;
            ancestor = ancestor->left;
        }
        else ancestor = ancestor->right;
    }
    return successor;
}
int main()
{
    Node* root = new Node(15);
    root->left = new Node(10);
    root->right = new Node(20);
    root->left->left = new Node(8);
    root->left->right = new Node(12);
    root->right->left = new Node(17);
    root->right->right = new Node(25);
    root->left->right->left = new Node(11);

    int val = 12;
    Node* successor = getSuccessor(root,val);
    cout << successor->data;
    return 0;
}