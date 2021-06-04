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
              8   9   */

void getVerticalOrder(Node*root,int hd, map<int,vector<int>>& m)
{
    if(root == NULL) return;
    m[hd].push_back(root->data);
    getVerticalOrder(root->left,hd-1,m);
    getVerticalOrder(root->right,hd+1,m);
}
void printVerticalOrder(Node* root)
{
    map<int, vector<int>> m;
    int hd = 0;
    getVerticalOrder(root,hd,m);

    for(auto it = m.begin();it!=m.end();it++)
    {
        for(int i=0;i<it->second.size();i++)
            cout << it->second[i] << " ";
        cout << endl;
    }
}
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

// vector<vector<int>> levelOrder(Node* root) {
//         vector<vector<int>> res;
//         queue<pair<Node*,int>>q;
//         int i=0;
//         q.push({root,0});
//         while(!q.empty())
//         {
//             Node* curr = q.front().first;
//             int t = q.front().second;
//             q.pop();
//             cout << t << " ";
//              if(res.size() == t)
//                 res.push_back(vector<int>());
//             res[t].push_back(curr->data);
//             if(curr->left) q.push({curr->left,t+1});
//             if(curr->right) q.push({curr->right,t+1});
//         }
//         return res;
//     }
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

    cout << "Vertical order traversal is : " << endl;
    printVerticalOrder(root);

    cout << "Top view of binary tree is: " << endl;
    topView(root);

    // vector<vector<int>> ans = levelOrder(root); 

    return 0;
}