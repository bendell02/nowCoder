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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.size() != postorder.size()) {
            return NULL;
        }
 
        int length = inorder.size();
        return helper(inorder, postorder, 0, length - 1, 0, length - 1);
    }
 
    TreeNode* helper(vector<int> &inorder, vector<int> &postorder, int left_i, int right_i, int left_p, int right_p) {
        if (left_i > right_i) {
            return NULL;
        }
 
        int mid = 0, current_val = postorder[right_p];
        TreeNode* node = new TreeNode(current_val);
        for (int i = left_i; i <= right_i; i++) {
            if (current_val == inorder[i]) {
                mid = i;
                break;
            }
        }
 
        node->left = helper(inorder, postorder, left_i, mid - 1, left_p, left_p + mid-left_i-1);
        node->right = helper(inorder, postorder, mid + 1, right_i, right_p - (right_i - mid), right_p - 1);
 
        return node;
    }
};
