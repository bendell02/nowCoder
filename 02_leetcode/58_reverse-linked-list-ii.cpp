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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // fake head
        ListNode *fake_head = new ListNode(0);
        fake_head->next = head;
 
        // look for m_node
        ListNode *prev = fake_head;
        int index = 0;
        while (index++ < m-1) {
            prev = prev->next;
        }
        ListNode *cur = prev->next;
        ListNode *temp = NULL;
        for (int i = m; i < n; i++) {
            temp = cur->next;
            cur->next = temp->next;
            temp->next = prev->next;
            prev->next = temp;
        }
 
        head = fake_head->next;
        delete fake_head;
        return head;
    }
};
