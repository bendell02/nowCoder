/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        // boundary
        if (NULL == head) {
            return NULL;
        }
 
        RandomListNode *fake_head_copy_list = new RandomListNode(0);
        RandomListNode *prev = head, *prev_copy_list = fake_head_copy_list;
        std::map<RandomListNode*, RandomListNode*> mapping;
        // build next pointer and mapping
        while (NULL != prev) {
            prev_copy_list->next = new RandomListNode(prev->label);
            mapping[prev] = prev_copy_list->next;
            prev = prev->next;
            prev_copy_list = prev_copy_list->next;
        }
 
        // build random pointer
        prev = head; prev_copy_list = fake_head_copy_list->next;
        while (NULL != prev) {
            if (NULL != prev->random) {
                prev_copy_list->random = mapping[prev->random];
            }
 
            prev = prev->next;
            prev_copy_list = prev_copy_list->next;
        }
 
        return fake_head_copy_list->next;
    }
};