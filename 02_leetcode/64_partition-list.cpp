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
    ListNode *partition(ListNode *head, int x) {
        if (NULL == head) { return NULL;}
 
        ListNode *fake_head = new ListNode(-1);
        fake_head->next = head;
        ListNode *left = fake_head, *cur = fake_head;
        while(NULL != cur->next) {
            ListNode *temp = cur->next;
            if (temp->val >= x) {
                cur = cur->next;
                continue;
            }
 
            // change
            if (left == cur) {
                left = left->next;
                cur = cur->next;
            }
            else {
                cur->next = temp->next;
                temp->next = left->next;
                left->next = temp;
 
                left = left->next;
                continue;
            }
        }
 
        return fake_head->next;
    }
};
