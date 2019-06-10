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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp_head = head;
        int index = 0;
         
        ListNode *first = new ListNode(-1); first->next = head;
        ListNode *second = head;
        while (NULL != second) {
            index++;
 
            if (index == k) {
                temp_head = second;
            }
 
            if (0 == (index%k)) {
                ListNode *temp = second->next; 
 
                reverseList(first->next, second);
                first->next->next = temp;
                temp = first->next;
                first->next = second;
                second = temp;
                first = temp;
            }
 
            second = second->next;
        }
 
        return temp_head;
    }
 
    ListNode* reverseList(ListNode *first, ListNode *second) {
        ListNode* temp_head = NULL;
        ListNode *post = first;
        ListNode *target = second->next;
 
        // change every node
        while (target != post) {
            first = post;
            post = post->next;
            first->next = temp_head;
            temp_head = first;
        }
 
        return temp_head;
    }
};
