//level order traversal simple and with spiral 
//watch 103 leetcode problem

#include<bits/stdc++.h>
using namespace std;
/*
        1
       / \
      2   3
     / \ / \
    4  5 6  7
        \
         8
*/
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int data){ this->data = data,left=NULL,right=NULL;}
};
void levelOrderTraversal(Node* root)
{
    if(root == NULL) return;
    queue<Node*>q;
    q.push(root);

    while(!q.empty())
    {
        Node* curr = q.front();
        q.pop();
        cout << curr->data << " ";
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
}
void LOTWithSpiralForm(Node* root)
{
    if(root == NULL) return;
    stack<Node*> s1;
    stack<Node*> s2;

    s1.push(root);
    while(!s1.empty() || !s2.empty())
    {
        while(!s1.empty())
        {
            Node* curr = s1.top();
            s1.pop();
            cout << curr->data << " ";

            if(curr->right) s2.push(curr->right);
            if(curr->left) s2.push(curr->left);
        }
        while(!s2.empty())
        {
            Node* curr = s2.top();
            s2.pop();
            cout << curr->data << " ";
            
            if(curr->left) s1.push(curr->left);
            if(curr->right) s1.push(curr->right);
        }
    }
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->right->right = new Node(8);

    cout << "Level Order traversal of binary tree is  : ";
    levelOrderTraversal(root);

    cout << endl << "Level Order traversal with spiral form is  : ";
    LOTWithSpiralForm(root);  //Need two stack
}