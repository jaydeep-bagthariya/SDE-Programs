#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node*left;
    Node*right;
    Node(int data){this->data = data,left=NULL,right=NULL;}
};
void preOrder2(Node*root)  // based on bfs
{
    stack<Node*> s;
    Node* curr = root;
    s.push(curr);
    while(!s.empty())
    {
        curr = s.top();
        s.pop();
        cout << curr->data << " ";

        if(curr->right) s.push(curr->right);
        if(curr->left) s.push(curr->left);
    }
}
void preOrder(Node* root)  // based on dfs
{
    stack<Node*> s;
    Node* curr = root;
    while(curr != NULL || s.empty() == false)
    {
        while(curr != NULL)
        {
            cout << curr->data << " ";
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        curr = curr->right;
    }
}
void preOrderWithRec(Node* root)
{
    if(root == NULL) return;
    cout << root->data << " ";
    preOrderWithRec(root->left);
    preOrderWithRec(root->right);
}
int main()
{
 
    /* Constructed binary tree is
              1
            /   \
          2      3
        /  \
      4     5
    */
    struct Node *root = new Node(1);
    root->left        = new Node(2);
    root->right       = new Node(3);
    root->left->left  = new Node(4);
    root->left->right = new Node(5);

    cout <<"Preorder Traversal without recursion method 1 : " ;
    preOrder(root);
    
    cout << endl << "Preorder Traversal without recursion method 2 : " ;
    preOrder2(root);

    cout << endl << "Preorder Traversal with recursion: ";
    preOrderWithRec(root);
    return 0;
}