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
    ListNode *detectCycle(ListNode *head) {
        if (hasCycle(head)) {
            ListNode *fast = head, *slow = head;
            // first detect
            while (true) {
                fast = fast->next->next;
                slow = slow->next;
                if (fast == slow) {
                    break;
                }
            }
 
            // second detect
            ListNode *first = head, *second = slow;
            while (first != second) {
                first = first->next;
                second = second->next;
            }
            return first;
        }
 
        return NULL;
    }
 
    bool hasCycle(ListNode *head) {
        // boundary
        if (NULL == head) {
            return false;
        }
 
        ListNode *fast = head, *slow = head;
        while (NULL != fast->next && NULL != fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                return true;
            }
        }
 
        return false;
    }
};