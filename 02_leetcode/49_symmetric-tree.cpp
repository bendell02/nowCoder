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
    bool isSymmetric(TreeNode* root) {
        // boundary
        if (NULL == root) {
            return true;
        }
 
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        TreeNode *current_node = NULL;
        vector<TreeNode*> row;
        while(!q.empty()) {
            current_node = q.front(); q.pop();
            if (NULL == current_node) {
                // check current row
                if (false == checkRow(row)) {
                    return false;
                }
                row.clear();
 
                if (q.empty()) break;
                q.push(NULL);
            }
            else {
                row.push_back(current_node);
 
                if (current_node->left) q.push(current_node->left);
                if (current_node->right) q.push(current_node->right);
            }
        }
 
        return true;
    }
 
    bool checkRow(vector<TreeNode*> &row) {
        int right = row.size()-1;
        int left = 0;
        while(left <= right) {
            if (false == checkNode(row[left], row[right])) {
                return false;
            }
            left++;
            right--;
        }
 
        return true;
    }
 
    bool checkNode(TreeNode *node1, TreeNode *node2) {
        if (node1->val != node2->val) {
            return false;
        }
 
        if (NULL != node1->left) {
            if (NULL == node2->right) {
                return false;
            }
        }
        else {
            if (NULL != node2->right) {
                return false;
            }
        }
 
        if (NULL != node1->right) {
            if (NULL == node2->left) {
                return false;
            }
        }
        else {
            if (NULL != node2->left) {
                return false;
            }
        }
 
        return true;
    }
};
