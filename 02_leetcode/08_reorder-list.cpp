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
    void reorderList(ListNode* head) {
        // boundary
        if (NULL == head) {
            return;
        }
 
        // split the list to two lists
        ListNode *fast = head, *slow = head;
        while ((NULL != fast->next) && (NULL!=fast->next->next)) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *head1 = head, *head2 = slow->next; // make the length of head1 is bigger than head2
        slow->next = NULL;
 
        // reverse head2
        head2 = reverseList(head2);
 
        // merge
        ListNode *post_head1=NULL, *post_head2 = NULL;
        while (NULL != head1 && NULL != head2) {
            post_head1 = head1->next;
            post_head2 = head2->next;
 
            head2->next = head1->next;
            head1->next = head2;
 
            head1 = post_head1;
            head2 = post_head2;
        }
    }
 
    ListNode* reverseList(ListNode* head) {
        ListNode* temp_head = NULL;
        ListNode *post = head;
 
        // change every node
        while (NULL != post) {
            head = post;
            post = post->next;
            head->next = temp_head;
            temp_head = head;
        }
 
        return temp_head;
    }
};