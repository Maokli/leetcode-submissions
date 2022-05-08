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
void postorderTraverse(int* index, struct TreeNode* root, int* nodes)
{
    if(root == NULL) return;
    
    postorderTraverse(index,root->left,nodes);
    postorderTraverse(index,root->right,nodes);
    *(nodes+*index) = root->val;
    (*index)++;
}

int length(struct TreeNode* root)
{
    if(root == NULL) return 0;
    
    int p1 = length(root->left);
    int p2 = length(root->right);
    
    return 1+p1+p2;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize){
    int len = length(root);
    
    int* nodes = (int*)malloc(len * sizeof(int));
    *returnSize = 0;
    
    postorderTraverse(returnSize,root,nodes);
    
    return nodes;
}