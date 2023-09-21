//Path Sum

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool hasPathSum(struct TreeNode* root, int targetSum) {
    if (root == NULL) {
        return false;
    }
    if (root->left == NULL && root->right == NULL) { // Checks if the ultimate value equals the targetSum
        if (targetSum == root->val)
        return true;
    }
    return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val); // Goes down the tree, decreasing the targetSum by the root's value until there are no more paths
}
