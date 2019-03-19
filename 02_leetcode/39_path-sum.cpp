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
    bool hasPathSum(TreeNode *root, int sum) {
        if (NULL == root) {
            return false;
        }
 
        return doesItOK(root, 0, sum);
    }
 
    bool doesItOK(TreeNode *root, int currentSum, const int &requestSum) {
        currentSum += root->val;
        if (NULL==root->left && NULL==root->right) {
            if (currentSum == requestSum) {
                return true;
            }
            else {
                return false;
            }
        }
 
        bool rlt_left = false, rlt_right = false;
        if (root->left) {
            rlt_left = doesItOK(root->left, currentSum, requestSum);
        }
        if (root->right) {
            rlt_right = doesItOK(root->right, currentSum, requestSum);
        }
 
        return (rlt_left||rlt_right);
    }
};
