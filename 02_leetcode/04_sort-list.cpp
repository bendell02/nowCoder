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
    // merge sort
    ListNode* sortList(ListNode* head) {
        if (NULL == head || NULL == head->next) {
            return head;
        }
 
        // find mid pointer
        ListNode *fast = head, *slow = head;
        while (NULL != (fast->next) && NULL != (fast->next->next)) {
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow;
        slow = slow->next;
        fast->next = NULL;
 
        fast = sortList(head);
        slow = sortList(slow);
 
        return merge(fast, slow);
    }
 
    ListNode* merge(ListNode* head_first, ListNode* head_second)
    {
        // boundary
        if (NULL == head_first) return head_second;
        if (NULL == head_second) return head_first;
 
        // determine the new head
        ListNode *new_head, *temp_ptr;
        if (head_first->val < head_second->val) {
            new_head = head_first;
            head_first = head_first->next;
        }
        else {
            new_head = head_second;
            head_second = head_second->next;
        }
        temp_ptr = new_head;
 
        // merge
        while (NULL != head_first && NULL != head_second) {
            if (head_first->val < head_second->val) {
                temp_ptr->next = head_first;
                head_first = head_first->next;
            }
            else {
                temp_ptr->next = head_second;
                head_second = head_second->next;
            }
            temp_ptr = temp_ptr->next;
        }
 
        // tail
        if (NULL != head_first) {
            temp_ptr->next = head_first;
        }
        if (NULL != head_second) {
            temp_ptr->next = head_second;
        }
 
        return new_head;
    }
};
