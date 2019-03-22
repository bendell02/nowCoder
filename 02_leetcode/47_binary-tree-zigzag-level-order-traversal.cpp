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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > rlt;
        if (NULL == root) {
            return rlt;
        }
 
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        TreeNode *currentNode = NULL;
        vector<int> layer;
        bool needReverse = false;
        while (!q.empty()) {
            currentNode = q.front(); q.pop();
 
            if (NULL == currentNode) {
                if (needReverse) {
                    reverse(layer.begin(), layer.end());
                }
                needReverse = (!needReverse);
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
 
        return rlt;
    }
};
