#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node*left;
    Node*right;
    Node(int data){this->data = data,left=NULL,right=NULL;}
};
void inOrder(Node*root)
{
    stack<Node*> s;
    Node* curr = root;
    while(s.empty()==false || curr != NULL)
    {
        while(curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}
void inOrderWithRec(Node* root)
{
    if(root == NULL) return;
    inOrderWithRec(root->left);
    cout << root->data << " ";
    inOrderWithRec(root->right);
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
    
    cout << "Inorder Traversal without recursion : " ;
    inOrder(root);

    cout << endl << "Inorder Traversal with recursion: ";
    inOrderWithRec(root);
    return 0;
}