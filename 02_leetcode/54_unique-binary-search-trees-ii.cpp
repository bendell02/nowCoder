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
    vector<TreeNode*> generateTrees(int n) {
        return *helper(1, n);
    }
 
    vector<TreeNode*>* helper(int left, int right) {
        vector<TreeNode*> *result = new vector<TreeNode*>();
        if (left > right) {
            result->push_back(NULL);
            return result;
        }
        if (left == right) {
            result->push_back(new TreeNode(left));
            return result;
        }
 
        //recursion
        for (int i = left; i <= right; i++) {
            vector<TreeNode*> *lefts = helper(left, i-1);
            vector<TreeNode*> *rights = helper(i+1, right);
            for (int j = 0; j < lefts->size(); j++) {
                for (int k = 0; k < rights->size(); k++) {
                    TreeNode *node = new TreeNode(i);
                    node->left = (*lefts)[j];
                    node->right = (*rights)[k];
                    result->push_back(node);
                }
            }
        }
 
        return result;
    }
};
