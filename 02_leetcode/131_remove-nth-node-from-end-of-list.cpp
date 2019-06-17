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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode fakeHead(-1);
        ListNode *pFakeHead = &fakeHead;
        pFakeHead->next = head;
 
        int length = getLength(head);
        int index = length - n; // 0-based
        ListNode *temp = pFakeHead;
        while (index > 0) {
            --index;
            temp = temp->next;
        }
        temp->next = temp->next->next;
 
        return pFakeHead->next;
    }
     
    int getLength(ListNode *head) {
        int length = 0;
        while (NULL != head) {
            length++;
            head = head->next;
        }
 
        return length;
    }
};
