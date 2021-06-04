//   ******  700. Search in a Binary Search Tree  ******

// You are given the root of a binary search tree (BST) and an integer val.

// Find the node in the BST that the node's value equals val and return
// the subtree rooted with that node. If such a node does not exist, return null.


// Example 1:
// Input: root = [4,2,7,1,3], val = 2
// Output: [2,1,3]

// Example 2:
// Input: root = [4,2,7,1,3], val = 5
// Output: []

//IN SIMPLE WE HAVE TO FIND ROOT AND RETURN IT;

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

//recursive approach
class Solution {
public:
    TreeNode* search(TreeNode* root, int val)
    {
        if(root == NULL) return root;
        if(val == root->val) return root;
        if(val<root->val) root = search(root->left,val);
        else if(val>root->val) root = search(root->right,val);
        return root;
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* node = search(root, val);
        return node;
    }
};

//iterative approach
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root && root->val != val) {
            root = val<root->val?root->left:root->right;
        }
        return root;
    }
};