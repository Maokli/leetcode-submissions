/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


void preorderTraverse(int* index, struct TreeNode* root, int* nodes)
{
    if(root == NULL) return;
    
    *(nodes+*index) = root->val;
    (*index)++;
    preorderTraverse(index,root->left,nodes);
    preorderTraverse(index,root->right,nodes);
}

int length(struct TreeNode* root)
{
    if(root == NULL) return 0;
    
    int p1 = length(root->left);
    int p2 = length(root->right);
    
    return 1+p1+p2;
}

int* preorderTraversal(struct TreeNode* root, int* returnSize){
    int len = length(root);
    
    int* nodes = (int*)malloc(len * sizeof(int));
    *returnSize = 0;
    
    preorderTraverse(returnSize,root,nodes);
    
    return nodes;
    
}