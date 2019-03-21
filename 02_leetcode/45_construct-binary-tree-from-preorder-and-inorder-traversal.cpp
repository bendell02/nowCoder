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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.size() != inorder.size()) {
            return NULL;
        }
 
        int length = preorder.size();
        return helper(preorder, inorder, 0, length - 1, 0, length - 1);
    }
 
    TreeNode* helper(vector<int> &preorder, vector<int> &inorder, int left_pre, int right_pre, int left_i, int right_i) {
        if (left_i > right_i) {
            return NULL;
        }
 
        int mid = 0, current_val = preorder[left_pre];
        TreeNode* node = new TreeNode(current_val);
        for (int i = left_i; i <= right_i; i++) {
            if (current_val == inorder[i]) {
                mid = i;
                break;
            }
        }
 
        node->left = helper(preorder, inorder, left_pre + 1, left_pre + (mid - left_i), left_i, mid - 1);
        node->right = helper(preorder, inorder, right_pre - (right_i - mid - 1), right_pre, mid + 1, right_i);
 
        return node;
    }
};
