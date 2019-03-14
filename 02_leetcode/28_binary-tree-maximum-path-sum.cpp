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
    int maxPathSum(TreeNode *root) {
        if (NULL == root) {
            return 0;
        }
        int maxSum = root->val;
        dfs(root, maxSum);
        return maxSum;
    }
     
    int dfs(TreeNode* root, int &maxSum) {
        if (NULL == root) {
            return 0;
        }
        int left = dfs(root->left, maxSum);
        int right = dfs(root->right, maxSum);
        left = std::max(0, left);
        right = std::max(0, right);
        int local_sum = root->val + left + right;
        maxSum = std::max(maxSum, local_sum);
        return std::max(root->val+left, root->val+right);
 
    }
};
