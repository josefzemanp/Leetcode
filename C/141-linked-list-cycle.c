/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {

    struct ListNode *slow = head;
    struct ListNode *fast = head;

     do {
        if(fast == NULL || fast->next == NULL) return 0;

        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);
    
    return 1;
}
