#include<bits/stdc++.h>
using namespace std;

/*
        12
       / \
      5   15
     / \ / \
    3  7 13 17
        \
         9
*/

//In this problem we have to see three seniarios
//1. Delete leaf node
//2. Delete not which has either left child or right child
//3. Delete not which has both side child

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int data){ this->data = data,left=NULL,right=NULL;}
};
Node* findMin(Node* root)
{
    while(root->left != NULL) root = root->left;
    return root;
}
Node* Delete(Node* root, int val)
{
    if(root == NULL) return root;
    if(val<root->data) root->left = Delete(root->left,val);
    else if(val>root->data) root->right = Delete(root->right,val);
    else
    {
        //case:1 if root is leaf node
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }

        //case:2 if root has left or right child
        else if(root->left == NULL)
        {
            // Node* temp = findMin(root->right);
            Node* temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right == NULL)
        {
            Node* temp = root;
            root = root->left;
            delete temp;
        }

        //case:2 if root has left and right child
        else
        {
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right,temp->data);
        }
    }
    return root;
} 
void Inorder(Node* root)
{
    if(root == NULL) return;
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}
int main()
{
    Node* root = new Node(12);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->left = new Node(13);
    root->right->right = new Node(17);
    root->left->right->right = new Node(9);

    cout << "Enter a value you want to delete: ";
    int val;
    cin>>val;
    Node* root1 = Delete(root,val);
    Inorder(root1);
}