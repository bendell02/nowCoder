/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        bool isBalance = true;
        getDepth(root, isBalance);
 
        return isBalance;
    }
 
    int getDepth(TreeNode *root, bool &isBalance) {
        if (NULL == root) {
            return 0;
        }
        int left_height = getDepth(root->left, isBalance);
        int right_height = getDepth(root->right, isBalance);
 
        if (std::abs(left_height-right_height) > 1) {
            isBalance = false;
        }
 
        return (1 + std::max(left_height, right_height));
    }
};
