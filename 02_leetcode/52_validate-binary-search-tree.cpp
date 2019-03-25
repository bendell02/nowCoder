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
    bool isValidBST(TreeNode *root) {
        stack<pair<TreeNode*, bool> > s;
        s.push(make_pair(root, false));
 
        TreeNode *current = NULL, *prev = NULL;
        bool isVisited = false;
        while (!s.empty()) {
            current = s.top().first;
            isVisited = s.top().second;
            s.pop();
 
            if (NULL == current) {
                continue;
            }
 
            if (isVisited) {
                if (NULL != prev) {                
                    if (current->val <= prev->val) {
                        return false;
                    }
                }
                prev = current;
            }
            else {
                s.push(make_pair(current->right, false));
                s.push(make_pair(current, true));
                s.push(make_pair(current->left, false));
            }
        }
 
        return true;
    }
};
