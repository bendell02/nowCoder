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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = getLength(l1);
        int len2 = getLength(l2);
        if (len1 < len2) {
            swap(l1, l2);
        }
 
        int carry = 0;
        ListNode* node = l1;
        ListNode* preNode = NULL;
        while (l2) {
            int temp = l2->val + node->val + carry;
            node->val = temp % 10;
            carry = temp / 10;
 
            l2 = l2->next;
            preNode = node;
            node = node->next;
        }
 
        while (carry > 0) {
            if (node == NULL) {
                preNode->next = new ListNode(carry);
                break;
            }
 
            int temp = node->val + carry;
            node->val = temp % 10;
            carry = temp / 10;
 
            preNode = node;
            node = node->next;
        }
 
        return l1;
    }
 
    int getLength(ListNode* node) {
        int length = 0;
        while (node) {
            ++length;
            node = node->next;
        }
 
        return length;
    }
};
