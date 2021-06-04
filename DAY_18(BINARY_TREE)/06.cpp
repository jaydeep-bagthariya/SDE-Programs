//   ******  100. Same Tree  ******

// Given the roots of two binary trees p and q, write a function to check if they are the same or not.

// Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

// Example 1:
// Input: p = [1,2,3], q = [1,2,3]
// Output: true

// Example 2:
// Input: p = [1,2], q = [1,null,2]
// Output: false

// Example 3:
// Input: p = [1,2,1], q = [1,1,2]
// Output: false

#include<bits/stdc++.h>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// recursion solution
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL) return true;
        if(p==NULL || q==NULL) return false;
        return p->val == q->val && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};

//iterative solution
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL) return true;
        if(p==NULL || q==NULL) return false;
        queue<pair<TreeNode*,TreeNode*>> que;
        que.push({p,q});
        while(!que.empty())
        {
            TreeNode* node1 = que.front().first;
            TreeNode* node2 = que.front().second;
            que.pop();
            if(node1->val != node2->val) return false;
            if(node1->left && node2->left) que.push({node1->left,node2->left});
            else if(node1->left || node2->left) return false;
            if(node1->right && node2->right) que.push({node1->right,node2->right});
            else if(node1->right || node2->right) return false;
        }
        return true;
    }
};

