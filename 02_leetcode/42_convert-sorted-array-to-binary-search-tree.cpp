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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
 
    TreeNode* helper(vector<int> &num, int left, int right) {
        if (left > right) {
            return NULL;
        }
 
        int mid = left + (right - left + 1) / 2;
        TreeNode *node = new TreeNode(num[mid]);
        node->left = helper(num, left, mid - 1);
        node->right = helper(num, mid + 1, right);
 
        return node;
    }
};
