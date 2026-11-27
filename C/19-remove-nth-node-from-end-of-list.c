/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if(head == NULL) return NULL;
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    for (int i = 0; i < n; i++) {
        fast = fast->next;
    }

    if(fast == NULL) {
        struct ListNode *new = head->next;
        // for better memory
        free(head);
        return new;
    }

    while(fast->next != NULL){
        slow = slow->next;
        fast = fast->next;
    }
    
    if(slow->next == NULL) return NULL;

    struct ListNode *tmp = slow->next;
    slow->next = tmp->next;
    // for better memory
    free(tmp);

    return head;
}
