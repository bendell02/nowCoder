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
    vector<int> preorderTraversal(TreeNode *root) {
        std::vector<int> rlt;
        if (NULL == root) {
            return rlt;
        }
 
        std::stack<TreeNode*> s;
        s.push(root);
 
        TreeNode* current = NULL;
        while (!s.empty()) {
            current = s.top();
            s.pop();
            rlt.push_back(current->val);
 
            if (NULL != current->right) {
                s.push(current->right);
            }
            if (NULL != current->left) {
                s.push(current->left);
            }
        }
 
        return rlt;
    }
};