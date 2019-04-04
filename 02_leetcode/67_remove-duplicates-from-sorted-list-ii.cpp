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
        if (NULL == head) { return head; }
 
        ListNode *fake_head = new ListNode(-1);
        fake_head->next = head;
        ListNode *prev = fake_head;
        ListNode *node = head ;
        int last_val = (head->val!=INT_MIN) ? INT_MIN : -1;  // make last_val is different from head->val;
        while (node && node->next) {
            if (node->val == node->next->val) {
                last_val = node->val;
                node = node->next->next;
                prev->next = node;
            }
            else if (node->val == last_val) {
                node = node->next;
                prev->next = node;
            }
            else {
                prev->next = node;
                prev = node;
 
                node = node->next;
            }
        }
        if (node && (node->val == last_val)) {
            prev->next = node->next;
        }
 
        return fake_head->next;
    }
};
