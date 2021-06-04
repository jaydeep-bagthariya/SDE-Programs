#include<bits/stdc++.h>
using namespace std;

struct bstNode
{
    int data;
    bstNode* left;
    bstNode* right;

    bstNode(int data){this->data=data,left = NULL, right = NULL;}
};
bstNode* insert(bstNode* root, int data)
{
    bstNode* newNode = new bstNode(data);

    //reucrsive approach
    if(root == NULL)
        root = newNode;
    else if(data <= root->data)
        root->left=insert(root->left,data);
    else
        root->right=insert(root->right,data);
    return root;

    //iterative approach 
    // if(root == NULL)
    // {
    //     root = newNode;
    //     return root;
    // }
    // bstNode* temp = root;
    
    // while(root->left && root->right)
    // {
    //     if(data <= root->data)
    //         root = root->left;
    //     else
    //         root = root->right;
    // } 
    
    // if(data <= root->data) root->left = newNode;
    // else root->right = newNode;
    // return temp;

}
void print(bstNode* root)
{

}
bool search(bstNode* root,int data)
{
    if(root == NULL)
        return false;
    if(data == root->data)
        return true;
    if(data <= root->data) search(root->left,data);
    else search(root->right,data);
}
int maxElement(bstNode* root)
{
    if(root ==  NULL) return -1;
    if(root->right == NULL)
        return root->data;
    maxElement(root->right);
}
int minElement(bstNode* root)
{
    if(root == NULL) return -1;
    while(root->left != NULL)
        root = root->left;
    return root->data;
}

int findHeight(bstNode* root)
{
    if(root == NULL) return -1;
    // int leftHeight = findHeight(root->left);
    // int rightHeight = findHeight(root->right);
    // return max(leftHeight,rightHeight)+1;

    //Improved code;
    return max(findHeight(root->left),findHeight(root->right))+1;
}

void BFS(bstNode* root)
{
    queue<bstNode*> q;
    q.push(root);
    while(!q.empty())
    {
        bstNode* current = q.front();
        cout << current->data << " ";
        if(current->left)
            q.push(current->left);
        if(current->right)
            q.push(current->right);
        q.pop();
    }
}
void Preorder(bstNode* root)
{
    if(root==NULL) return;
    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}
void Postorder(bstNode* root)
{
    if(root == NULL)return;
    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << " ";
}
void Inorder(bstNode* root)
{
    if(root == NULL) return;
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}
int main()
{
    bstNode* root = NULL;
    root = insert(root,15);
    root = insert(root,10);
    root = insert(root,20);
    root = insert(root,9);
    root = insert(root,11);
    root = insert(root,29);
    root = insert(root,17);
    // print(root);
    if(search(root,20))
        cout << "Found";
    else
        cout << "Not found";
    
    cout << endl << "Max element is: ";
    int Max = maxElement(root);
    cout << endl << Max;

    cout << endl << "Min element is: ";
    int Min = minElement(root);
    cout << endl << Min << endl;

    cout << "Height of binary tree is: ";
    int height = findHeight(root);
    cout << height << endl;

    cout << "Nodes are: ";
    BFS(root);

    // cout << "Preorder Traversal: ";
    // Preorder(root);

    // cout << "Inorder Traversal: ";
    // Inorder(root);

    // cout << "Postorder Traversal: ";
    // Postorder(root);

    return 0;
}