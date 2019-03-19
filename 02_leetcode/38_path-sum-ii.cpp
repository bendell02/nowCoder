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
private:
    vector<vector<int> > result;
 
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> currentPath;
        int currentSum = 0;
        if (NULL != root) {
            dfs(root, currentSum, sum, currentPath);
        }      
 
        return result;
    }
 
    void dfs(TreeNode* root, int &currentSum, const int &requestSum, vector<int> &currentPath) {
        currentPath.push_back(root->val);
        currentSum += root->val;
         
        if (NULL != root->left) {
            dfs(root->left, currentSum, requestSum, currentPath);
        }
        if (NULL != root->right) {
            dfs(root->right, currentSum, requestSum, currentPath);
        }
 
        if ((root->right == NULL) && (root->left == NULL) && (currentSum == requestSum)) {
            result.push_back(currentPath);
        }
 
        currentSum -= root->val;
        currentPath.pop_back();
    }
};
