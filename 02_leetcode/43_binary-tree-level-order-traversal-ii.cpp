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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > rlt;
        if (NULL == root) {
            return rlt;
        }
 
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        TreeNode *currentNode = NULL;
        vector<int> layer;
        while (!q.empty()) {
            currentNode = q.front(); q.pop();
 
            if (NULL == currentNode) {
                rlt.push_back(layer);
                layer.clear();
                 
                if (q.empty()) break;
                q.push(NULL);
            }
            else {
                layer.push_back(currentNode->val);
                 
                if(currentNode->left) q.push(currentNode->left);
                if(currentNode->right) q.push(currentNode->right);
            }
        }
         
        reverse(rlt.begin(), rlt.end());
 
        return rlt;
    }
};
