/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    if(head == NULL) return NULL;
    if(head->next == NULL) return head;

    struct ListNode *second = head->next;
    struct ListNode *tmp = head->next->next;
    head->next->next = head;
    
    head->next = swapPairs(tmp);
    return second;
}
