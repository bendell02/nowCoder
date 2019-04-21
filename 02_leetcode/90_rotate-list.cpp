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
    ListNode *rotateRight(ListNode *head, int k) {
        // boundary
        if (head == NULL) { return NULL; }
 
        int len = getLength(head);
        k = k % (len);
 
        if (0 == k) { return head; }
 
        int first_steps = len - k;
        ListNode *node = head;
        while (--first_steps) { node = node->next; }
 
        ListNode *fake_head = new ListNode(-1);
        fake_head->next = node->next;
        node->next = NULL;
        node = fake_head->next;
        while (node->next) { node = node->next; }
        node->next = head;
 
        return fake_head->next;
    }
 
    int getLength(ListNode* head) {
        int len = 0;
        while (head) {
            len++;
            head = head->next;
        }
 
        return len;
    }
};
