#include<bits/stdc++.h>

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
};


TreeNode *successor(TreeNode *root)
{
    // detaches the inorder successor it is exists
    if (root == NULL)
        return NULL;
    TreeNode *parent = root;
    TreeNode *cur = root->right;
    while (cur && cur->left)
    {
        parent = cur;
        cur = cur->left;
    }
    if (cur)
        parent->left = cur->right;
    return cur;
}
TreeNode *deleteFromBST(TreeNode *root, int x)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == x)
    {
        // if root is a leaf
        if (!root->left && !root->right)
        {
            delete root;
            return NULL;
        }
        // if root has one child
        if (!root->left)
        {
            TreeNode *tmp = root->right;
            delete root;
            return tmp;
        }
        if (!root->right)
        {
            TreeNode *tmp = root->left;
            delete root;
            return tmp;
        }
        // if root has 2 children
        TreeNode *inOrderSuccessor = successor(root);
        inOrderSuccessor->left = root->left;
        inOrderSuccessor->right = root->right;
        delete root;
        return inOrderSuccessor;
    }
    if (root->data > x)
    {
        root->left = deleteFromBST(root->left, x);
        return root;
    }
    else
    {
        root->right = deleteFromBST(root->right, x);
        return root;
    }
}