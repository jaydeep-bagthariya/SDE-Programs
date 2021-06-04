//  ******  106. Construct Binary Tree from Inorder and Postorder Traversal  ******

// Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

 

// Example 1:


// Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]    
// Output: [3,9,20,null,null,15,7]
// Example 2:

// Input: inorder = [-1], postorder = [-1]
// Output: [-1]


#include<bits/stdc++.h>
using namespace std;


// Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    TreeNode* helper(vector<int>& in, vector<int>&post, int inS, int inE, int postS, int postE)
    {
        if(inS>inE) return NULL;
        
        int rootData = post[postE];
        int rootPosition = -1;
        for(int i=inS;i<=inE;i++)
            if(in[i]==rootData)
            {
                rootPosition = i;
                break;
            }
        int lInS = inS;
        int rInE = inE;
        int lPostS = postS;
        int rPostE = postE-1;
        int lInE = rootPosition-1;
        int rInS = rootPosition+1;
        int lPostE = lInE-lInS+lPostS;
        int rPostS = lPostE+1;
        
        TreeNode* root = new TreeNode(rootData);
        root->left = helper(in,post,lInS,lInE,lPostS,lPostE);
        root->right = helper(in,post,rInS,rInE,rPostS,rPostE);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        return helper(inorder,postorder,0,n-1,0,n-1);
    }
};