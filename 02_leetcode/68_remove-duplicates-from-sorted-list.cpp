/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // boudary 
        if (NULL == head) { return head; }
 
        int last_val = head->val;
        ListNode *node = head;
        while (node->next) {
            if (last_val != node->next->val) {
                node = node->next;
                last_val = node->val;
            }
            else {
                node->next = node->next->next;
            }
        }
 
        return head;
    }
};
