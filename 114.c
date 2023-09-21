//flatten binary tree into a linked list

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void flatten(struct TreeNode* root){
    if (root == NULL) return;
    
    struct TreeNode* L = root->left; //Stores the values of right and left on a new TreeNode
    struct TreeNode* R = root->right;
    
    root->left = NULL; //Removes left
    flatten(L); //Recursion; Goes on until it reaches a Null.
    flatten(R);
    
    root->right = L; // Then it returns and attaches a new right value as L (Keep in mind that the previous right is stored in R). 
    struct TreeNode* current = root;
    while (current->right != NULL) {
        current = current->right; // Finds a proper place to attach R
    }
    current->right = R; // Attaches R
}
// First it works on the left most side of the tree and gradually works its way to the right. After the entire left side of the root has been worked on, when the root->right = L happens, the L already contains all previous L's and R's flattened.
