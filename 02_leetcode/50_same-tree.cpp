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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // boudary
        if (NULL == p && NULL == q) {
            return true;
        }
        if ((NULL == p && NULL != q) || (NULL != p && NULL == q)) {
            return false;
        }
 
        queue<TreeNode*> q_p;
        queue<TreeNode*> q_q;
        q_p.push(p);
        q_q.push(q);
        TreeNode *current_node_p=NULL, *current_node_q=NULL;
 
        while (!q_p.empty()) {
            if (q_q.empty()) {
                return false;
            }
 
            current_node_p = q_p.front(); q_p.pop();
            current_node_q = q_q.front(); q_q.pop();
             
            if (false == checkNode(current_node_p, current_node_q)) {
                return false;
            }
 
            if (current_node_p->left) {
                q_p.push(current_node_p->left);
                q_q.push(current_node_q->left);
            }
 
            if (current_node_p->right) {
                q_p.push(current_node_p->right);
                q_q.push(current_node_q->right);
            }
        }
 
        return true;
    }
 
    bool checkNode(TreeNode *node1, TreeNode *node2) {
        if (node1->val != node2->val) {
            return false;
        }
 
        if (NULL != node1->left) {
            if (NULL == node2->left) {
                return false;
            }
        }
        else {
            if (NULL != node2->left) {
                return false;
            }
        }
 
        if (NULL != node1->right) {
            if (NULL == node2->right) {
                return false;
            }
        }
        else {
            if (NULL != node2->right) {
                return false;
            }
        }
 
        return true;
    }
};
