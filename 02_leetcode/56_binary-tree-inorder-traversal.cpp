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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> path;
         
        stack< pair<TreeNode *, bool> > s;
        s.push(make_pair(root, false));
        bool visited;
        while(!s.empty())
        {
            root = s.top().first;
            visited = s.top().second;
            s.pop();
            if(root == NULL)
                continue;
            if(visited)
            {
                path.push_back(root->val);
            }
            else
            {
                s.push(make_pair(root->right, false));
                s.push(make_pair(root, true));
                s.push(make_pair(root->left, false));
            }
        }
         
        return path;
    }
};
