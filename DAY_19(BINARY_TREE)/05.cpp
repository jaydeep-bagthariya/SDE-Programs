//   ******  114. Flatten Binary Tree to Linked List  ******

// Given the root of a binary tree, flatten the tree into a "linked list":

// The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
// The "linked list" should be in the same order as a pre-order traversal of the binary tree.
 

// Example 1:


// Input: root = [1,2,5,3,4,null,6]
// Output: [1,null,2,null,3,null,4,null,5,null,6]
// Example 2:

// Input: root = []
// Output: []
// Example 3:

// Input: root = [0]
// Output: [0]

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

// Gharni approach NOT RECOMMENDED :)
class Solution {
public:
    TreeNode* insert(vector<TreeNode*>& temp)
    {
        TreeNode* dummy = new TreeNode(0);
        TreeNode* fake = dummy;
        for(auto i : temp)
        {
            while(fake->right)
                fake = fake->right;
            fake->right = i;
            i->left = NULL;
            i->right = NULL;
        }
        return dummy->right;
    }
    void preOrder(TreeNode* root, vector<TreeNode*>& temp)
    {
        if(root == NULL) return;
        temp.push_back(root);
        preOrder(root->left,temp);
        preOrder(root->right,temp);
    }
    void flatten(TreeNode* root) {
        if (root == NULL) return;
        vector<TreeNode*> temp;
        preOrder(root, temp);
        TreeNode* rt =  insert(temp);
    }
};

//USING RECURSION   (mind blowing approach)
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        flatten(root->left);
        flatten(root->right);
        if(root->left)
        {
            TreeNode* right = root->right;
            root->right = root->left;
            root->left = NULL;
            while(root->right) root = root->right;
            root->right = right;
        }
    }
};

//USING STACK

class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty())
        {
            TreeNode* curr = s.top();
            s.pop();
            if(curr->right) s.push(curr->right);
            if(curr->left) s.push(curr->left);
            if(!s.empty())
                curr->right = s.top();
            curr->left = NULL;
        }
    }
};