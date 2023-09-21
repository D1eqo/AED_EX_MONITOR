//Minimum deapth of binary tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int minDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    if (root->left == NULL) {
        return minDepth(root->right) + 1; //Every time that there is a comfirmed left or right child node get +1. [Remember the +1's are actually summed when returning from the recursions]
    }
    if (root->right == NULL) {
        return minDepth(root->left) + 1;
    }
    // If both exist, return +1 for whichever is smaller
    int L = minDepth(root->left);
    int R = minDepth(root->right);
  
    if (L > R){
        return R + 1;
    }
    else{
        return L + 1;
    } 
}
