//Validate Binary Search Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
struct TreeNode* prev;

bool checker(struct TreeNode* root) {
    if (root == NULL) {
        return true;
    }
    if (checker(root->left) == false) { // If false is returned it means that there's a problem on one of the left nodes.
        return false;
    }
    if (prev != NULL && prev->val >= root->val) { //Goes from left to right in the tree, so it makes sense that prev->val should always be less than the current root->val (When it reaches the right half it starts going "downwards")
        return false;
    }
    prev = root; // Remembers the last value (The left-most leaf will be the first prev)
    return checker(root->right);
}

bool isValidBST(struct TreeNode* root) {
    prev = NULL; // Using prev to keep track for comparison; Declared outside of checker to mantain its value throughout the recursive calls
    return checker(root);
}

