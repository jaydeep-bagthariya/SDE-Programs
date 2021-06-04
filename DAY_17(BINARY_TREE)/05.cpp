#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int data){this->data = data, left = right = NULL;}
};
 
 /*
          1
        /    \ 
       2      3
      / \   /   \
     4   5  6   7
               /  \ 
              8    9   */

void topView(Node* root)
{
    if(root == NULL) return;

    queue<pair<Node*,int>>q;
    unordered_map<int,int> m;
    q.push({root,0});

    while(!q.empty())
    {
        Node* curr = q.front().first;
        int hd = q.front().second;
        q.pop();

        if(!m.count(hd))
        {
            cout << curr->data << " ";
            m[hd] = curr->data;
        }
        if(curr->left) q.push({curr->left,hd-1});
        if(curr->right) q.push({curr->right,hd+1});
    }
} 

void bottomView(Node* root)
{
    if(root == NULL) return;

    queue<pair<Node*,int>>q;
    map<int,int> m;
    q.push({root,0});

    while(!q.empty())
    {
        Node* curr = q.front().first;
        int hd = q.front().second;
        q.pop();

        m[hd]=curr->data;
        if(curr->left) q.push({curr->left,hd-1});
        if(curr->right) q.push({curr->right,hd+1});
    }
    for(auto i = m.begin(); i!=m.end();i++)
        cout << i->second << " ";
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);
    root->right->right->right = new Node(9);

    cout << "Top view of binary tree is: " << endl;
    topView(root);

    cout << endl << "Bottom view of binary tree is: " << endl;
    bottomView(root);
    // vector<vector<int>> ans = levelOrder(root); 

    return 0;
}