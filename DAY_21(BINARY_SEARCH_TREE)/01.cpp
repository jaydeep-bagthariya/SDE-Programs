//  ******  116. Populating Next Right Pointers in Each Node ******

// You are given a perfect binary tree where all leaves are on the same level,
//  and every parent has two children. The binary tree has the following definition:

// struct Node {
//   int val;
//   Node *left;
//   Node *right;
//   Node *next;
// }
// Populate each next pointer to point to its next right node.
//  If there is no next right node, the next pointer should be set to NULL.

// Initially, all next pointers are set to NULL.

 

// Follow up:

// You may only use constant extra space.
// Recursive approach is fine, you may assume implicit stack space does not
//  count as extra space for this problem.
 

// Example 1:



// Input: root = [1,2,3,4,5,6,7]
// Output: [1,#,2,3,#,4,5,6,7,#]
// Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer
// to point to its next right node, just like in Figure B. The serialized output is in level order as connected
// by the next pointers, with '#' signifying the end of each level.


#include<bits/stdc++.h>
using namespace std;

/*
        1->NULL
       / \
      2-> 3->NULL
     / \ / \
    4->5>6->7->NULL
        \
         8->NULL
*/

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

// iterative method
class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return root;
        Node* pre = root;
        Node* curr = NULL;
        while(pre->left)
        {
            curr = pre;
            while(curr)
            {
                curr->left->next = curr->right;
                if(curr->next) curr->right->next = curr->next->left;
                curr = curr->next;
            }
            pre = pre->left;
        }
        return root;
    }
};


//using recursion;
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;
        if(root->left) {
            root->left->next = root->right;
            if(root->next) root->right->next = root->next->left;
            root->left = connect(root->left);
            root->right = connect(root->right);
        }
        return root;
    }
};

//it can be done by using queue(just for understanding)
class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if (root) q.push(root);
        while (q.size()) {
            int len = q.size();
            Node* curr;
            while (len--) {
                curr = q.front(), q.pop();
                curr->next = len ? q.front():NULL;
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);         
            }
        }         
        return root;
    }
};