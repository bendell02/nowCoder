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
    void recoverTree(TreeNode *root) {
        TreeNode *prev=NULL, *current;
        TreeNode *first_error=NULL, *seconde_error=NULL;
 
        stack< pair<TreeNode *, bool> > s;
        s.push(make_pair(root, false));
        bool visited;
        while (!s.empty()) {
            current = s.top().first;
            visited = s.top().second;
            s.pop();
            if (current == NULL) {
                continue;
            }              
 
            if (visited) {
                // find the prev
                if (NULL != prev) {
                    if (current->val < prev->val) {
                        first_error = (NULL != first_error) ? first_error : prev;
                        seconde_error = current;
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
 
        // swap the error node
        swap(first_error->val, seconde_error->val);
    }
};
