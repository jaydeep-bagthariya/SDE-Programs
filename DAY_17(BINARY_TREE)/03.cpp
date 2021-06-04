#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node*left;
    Node*right;
    Node(int data){this->data = data,left=NULL,right=NULL;}
};
void postOrder(Node* root)
{
    stack<Node*> s1;
    stack<Node*> s2;
    Node* curr = root;
    s1.push(curr);

    while(!s1.empty())
    {
        curr = s1.top();
        s1.pop();
        s2.push(curr);
        if(curr->left) s1.push(curr->left);
        if(curr->right) s1.push(curr->right);
    }
    while(!s2.empty())
    {
        curr = s2.top();
        cout << curr->data << " ";
        s2.pop();
    }
}
void postOrderWithRec(Node* root)
{
    if(root == NULL) return;
    postOrderWithRec(root->left);
    postOrderWithRec(root->right);
    cout << root->data << " ";
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
    
    cout << "Post order Traversal without recursion : " ;
    postOrder(root);

    cout << endl << "Post order Traversal with recursion: ";
    postOrderWithRec(root);
    return 0;
}