/**
* To Run -> Test on Leetcode Q.No 19.
* Aakash Singla (1910990070), 20 August 2021
* Assignment 6 - Linked List
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// returns the resultant list after removing nth node from the end of given list.
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* temp = (struct ListNode*) malloc(sizeof(struct ListNode));
    temp->next = head;
    
    struct ListNode* slow = temp;
    struct ListNode* fast = temp;
    
    while(n-- > 0) {
        fast = fast->next;
    }
    
    if(fast->next == NULL) {
        return head->next;
    }
    
    while(fast->next != NULL) {
        slow = slow->next;
        fast = fast->next;
    }
    
    slow->next = slow->next->next;
    return head;
}
