// // 98. Validate Binary Search Tree

// Given the root of a binary tree, determine if it is a valid binary search tree (BST).

// A valid BST is defined as follows:

// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.
 

// Example 1:


// Input: root = [2,1,3]
// Output: true
// Example 2:


// Input: root = [5,1,4,null,null,3,6]
// Output: false
// Explanation: The root node's value is 5 but its right child's value is 4.
 

// Constraints:

// The number of nodes in the tree is in the range [1, 104].
// -231 <= Node.val <= 231 - 1


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
 
//using inorder traversal
class Solution {
public:
    bool helper(TreeNode* root, TreeNode* &pre)
    {
        if(root == NULL) return true;
        if(!helper(root->left,pre)) return false;
        if(pre!=NULL && pre->val>=root->val) return false;
        pre = root;
        return helper(root->right,pre);
    }
    bool isValidBST(TreeNode* root) {
        TreeNode* pre = NULL;
        return helper(root,pre);
    }
};

//using recursion
class Solution {
public:
    bool helper(TreeNode* root, long Max, long Min)
    {
        if(root == NULL) return true;
        return (root->val<Max && root->val>Min) && helper(root->left,root->val,Min) && helper(root->right,Max,root->val);
    }
    bool isValidBST(TreeNode* root) {
        return helper(root,LONG_MAX,LONG_MIN);
    }
};