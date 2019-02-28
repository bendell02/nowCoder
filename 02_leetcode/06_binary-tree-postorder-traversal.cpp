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
    vector<int> postorderTraversal(TreeNode *root) {
        std::vector<int> rlt;
        std::stack<std::pair<TreeNode*, bool> > s;
        s.push(std::make_pair(root, false));
 
        TreeNode* current = NULL;
        bool isVisited = false;
        while (!s.empty()) {
            current = s.top().first;
            isVisited = s.top().second;
            s.pop();
            if (NULL == current) {
                continue;
            }
 
            if (isVisited) {
                rlt.push_back(current->val);
            }
            else {
                s.push(std::make_pair(current, true));
                s.push(std::make_pair(current->right, false));
                s.push(std::make_pair(current->left, false));
            }
        }
 
        return rlt;
    }
};