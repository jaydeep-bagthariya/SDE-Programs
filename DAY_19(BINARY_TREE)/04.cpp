//   ****** 101. Symmetric Tree  ******

// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

// Example 1:
// Input: root = [1,2,2,3,4,4,3]
// Output: true

// Example 2:
// Input: root = [1,2,2,null,3,null,3]
// Output: false


#include<bits/stdc++.h>
using namespace std;


//  Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

//recursive approach
class Solution {
public:
    bool isMirror(TreeNode* r1, TreeNode* r2)
    {
        if(r1==NULL && r2==NULL) return true;
        if(r1==NULL || r2==NULL) return false;
        return (r1->val == r2->val) && isMirror(r1->left, r2->right) && isMirror(r1->right, r2->left);
    }
    bool isSymmetric(TreeNode* root) {
        return isMirror(root,root);
    }
};

//using queue
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        
        queue<TreeNode*>s1;
        queue<TreeNode*>s2;
        
        s1.push(root->left);
        s2.push(root->right);
        
        while(!s1.empty() && !s2.empty())
        {
            TreeNode* t1 = s1.front();
            TreeNode* t2 = s2.front();
            s1.pop();
            s2.pop();
            if(!t1 && !t2) continue;
            if(!t1 || !t2) return false;
            if(t1->val != t2->val) return false;
            
            s1.push(t1->left); s1.push(t1->right);
            s2.push(t2->right); s2.push(t2->left);
        }
        return true;
    }
};

//using stack
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        
        stack<TreeNode*>s1;
        stack<TreeNode*>s2;
        
        s1.push(root->left);
        s2.push(root->right);
        
        while(!s1.empty() && !s2.empty())
        {
            TreeNode* t1 = s1.top();
            TreeNode* t2 = s2.top();
            s1.pop();
            s2.pop();
            if(!t1 && !t2) continue;
            if(!t1 || !t2) return false;
            if(t1->val != t2->val) return false;
            
            s1.push(t1->left); s1.push(t1->right);
            s2.push(t2->right); s2.push(t2->left);
        }
        return true;
        
    }
};