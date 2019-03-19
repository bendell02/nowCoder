/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head) {
        // convertListToVector
        vector<int> data;
        while (head != NULL) {
            data.push_back(head->val);
            head = head->next;
        }
 
        return helper(data, 0, data.size() - 1);
    }
 
    TreeNode* helper(vector<int> &data, int left, int right) {
        if (left > right) {
            return NULL;
        }
         
        int mid = left + (right - left+1) / 2;
        TreeNode *node = new TreeNode(data[mid]);
        node->left = helper(data, left, mid - 1);
        node->right = helper(data, mid + 1, right);
 
        return node;
    }
};
