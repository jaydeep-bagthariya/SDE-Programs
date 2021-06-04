//   ******  105. Construct Binary Tree from Preorder and Inorder Traversal ******

// Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

 

// Example 1:


// Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
// Output: [3,9,20,null,null,15,7]
// Example 2:

// Input: preorder = [-1], inorder = [-1]
// Output: [-1]


//IF YOU CAN'T UNDERSTAND THIS PROBLEM THEN WATCH CODING NINJA'S VIDEO

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
    TreeNode* helper(vector<int>& pre, vector<int>& in, int inS, int inE, int preS, int preE)
    {
        if(inS>inE) return NULL;
        
        int rootData = pre[preS];
        int rootPosition = -1;
        for(int i=inS;i<=inE;i++)
            if(in[i]==rootData)
            {
                rootPosition = i;
                break;
            }
        int lInS = inS;
        int rInE = inE;
        int lPreS = preS+1;
        int rPreE = preE;
        int lInE = rootPosition-1;
        int rInS = rootPosition+1;
        int lPreE = lInE-lInS+lPreS;
        int rPreS = lPreE+1;
        
        TreeNode* root = new TreeNode(rootData);
        root->left = helper(pre,in,lInS,lInE,lPreS,lPreE);
        root->right = helper(pre,in,rInS,rInE,rPreS,rPreE);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return helper(preorder,inorder,0,n-1,0,n-1);
    }
};