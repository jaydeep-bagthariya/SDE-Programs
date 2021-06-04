//Boundry of a binary tree

// In this problem we have to print our ans in anticlock wise
// We break the problem in 3 parts:
// 1. Print the left boundary in top-down manner.
// 2. Print all leaf nodes from left to right, which can again be sub-divided into two sub-parts:
// …..2.1 Print all leaf nodes of left sub-tree from left to right.
// …..2.2 Print all leaf nodes of right subtree from left to right.
// 3. Print the right boundary in bottom-up manner.

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int data) : data{data}, left{NULL}, right{NULL}{}
};
Node* findAncestor(Node* root, int v1, int v2)
{
    if(root == NULL) return root;
    if((v1<=root->data && v2>=root->data) || (v1>=root->data && v2<=root->data))
        return root;
    if(v1<root->data && v2<root->data) return findAncestor(root->left,v1,v2);
    else return findAncestor(root->right,v1,v2);
}
void leftSide(Node* root,vector<int>& ans)
{
    if(!root) return;
    if(root->left) {
        ans.push_back(root->data);
        leftSide(root->left,ans);
    }
    else if(root->right) {
        ans.push_back(root->data);
        leftSide(root->right,ans);
    }
}
void leafNode(Node* root,vector<int>& ans)
{
    if(!root) return;
    leafNode(root->left,ans);
    if(!(root->left) and !(root->right)) ans.push_back(root->data);
    leafNode(root->right,ans);
}
void reverseRightSide(Node* root,vector<int>& ans)
{
    if(!root) return;
    if(root->right){
        reverseRightSide(root->right,ans);
        ans.push_back(root->data);
    }
    else if(root->left) {
        reverseRightSide(root->left,ans);
        ans.push_back(root->data);
    } 
}
void findBoundry(Node* root,vector<int>& ans)
{
    if(root == NULL) return;
    ans.push_back(root->data);
    leftSide(root->left,ans);
    leafNode(root,ans);
    reverseRightSide(root->right,ans);
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

    Node* ancestor = findAncestor(root,17,25);
    cout << ancestor->data << endl;

    vector<int> ans;
    findBoundry(root,ans);
    for(int i : ans)
        cout << i << " ";

    return 0;
}