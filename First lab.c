/** 203. Remove Linked List Items
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




/** 206. Reverse Linked List
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* current = head;
    struct ListNode* next = NULL;

    while (current != NULL) {
        next = current->next; // Store next node
        current->next = prev; // Reverse the current node's pointer
        prev = current;       // Move prev to current
        current = next;       // Move current to next
    }
    return prev;  //new head of the linked list
}
