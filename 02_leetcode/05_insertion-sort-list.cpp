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
    ListNode *insertionSortList(ListNode *head) {
        ListNode *fake_head = new ListNode(0);
        fake_head->next = head;
        ListNode *prev_ptr = fake_head, *post_ptr = head;
        ListNode *current_ptr= fake_head, *temp_prev=NULL;
 
        while (NULL != post_ptr) {
            // get current pointer
            current_ptr = post_ptr;
            post_ptr = post_ptr->next;
 
            // find insert location
            temp_prev = fake_head;
            while (temp_prev->next->val < current_ptr->val) {
                temp_prev = temp_prev->next;
            }
 
            // insert the node
            if (temp_prev->next != current_ptr) {
                prev_ptr->next = current_ptr->next;
                current_ptr->next = temp_prev->next;
                temp_prev->next = current_ptr;
            }
            else {
                prev_ptr = current_ptr;
            }
        }
 
        return fake_head->next;
    }
};
