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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (NULL == l1) { return l2; }
        if (NULL == l2) { return l1; }
 
        ListNode *fakeNode = new ListNode(-1);
        ListNode *node = fakeNode;
        while (NULL != l1 && NULL != l2) {
            if (l1->val < l2->val) {
                node->next = l1;
                l1 = l1->next;
            }
            else {
                node->next = l2;
                l2 = l2->next;
            }
            node = node->next;
        }
 
        if (NULL != l1) { node->next = l1; }
        if (NULL != l2) { node->next = l2; }
 
        return fakeNode->next;
    }
};
