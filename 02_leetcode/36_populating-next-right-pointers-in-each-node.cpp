/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // boundary
        if (NULL == root) {
            return ;
        }
 
        queue<TreeLinkNode*> q;
        q.push(NULL);
        TreeLinkNode* current_node = NULL;
        TreeLinkNode* previous_node = root;
        while(!q.empty()) {
            current_node = q.front(); q.pop();
            previous_node->next = current_node;
 
            if (NULL != previous_node->left) {
                q.push(previous_node->left);
            }
            if (NULL != previous_node->right) {
                q.push(previous_node->right);
            }
 
            if (NULL == current_node) {
                q.push(NULL);
                while((!q.empty()) && (NULL==q.front())) {
                    q.pop();
                }
                if (!q.empty()) {
                    previous_node = q.front(); q.pop();
                }
            }
            else {
                previous_node = current_node;
            }
        }
    }
};
