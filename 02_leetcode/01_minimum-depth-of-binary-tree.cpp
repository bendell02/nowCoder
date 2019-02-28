class Solution {
public:
    int run(TreeNode *root) {
        // boundary
        if (NULL == root) {
            return 0;
        }
        if (NULL == root->left && NULL == root->right) {
            return 1;
        }
 
        // recursion
        if (NULL == root->left) {
            return (1 + run(root->right));
        }
        if (NULL == root->right) {
            return (1 + run(root->left));
        }
        return (1 + std::min(run(root->left), run(root->right)));
    }
};