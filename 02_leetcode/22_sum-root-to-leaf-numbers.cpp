class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if (NULL == root) {
            return 0;
        }

        vector<int> numbers;
        getLeafNumbers(numbers, root, 0);
        int sum = accumulate(numbers.begin() , numbers.end() , 0);
        return sum;
    }

    void getLeafNumbers(vector<int> &numbers, TreeNode *root, int current_num) {
        current_num = current_num*10+root->val;
        if((NULL==root->left) && NULL==root->right) {
            numbers.push_back(current_num);
        }
        if (NULL != root->left) {
            getLeafNumbers(numbers, root->left, current_num);
        }
        if (NULL != root->right) {
            getLeafNumbers(numbers, root->right, current_num);
        }
    }
};