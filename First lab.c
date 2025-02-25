/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* prev = dummy;
    struct ListNode* curr = head;

     while (curr != NULL) {
        if (curr->val == val) {
            prev->next = curr->next;
            free(curr);  // Free memory of removed node
        } else {
            prev = curr;
        }
        curr = prev->next;
    }
    
    head = dummy->next;
    free(dummy); // Free the dummy node
    return head;
}
