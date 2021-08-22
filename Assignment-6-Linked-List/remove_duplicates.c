/**
* To Run -> Test on Leetcode Q.No 82.
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

// returns list with nodes of values which don't have any duplicates in the input list.
struct ListNode* deleteDuplicates(struct ListNode* head){
    if(head == NULL || head->next == NULL) {
        return head;
    }
    
    struct ListNode* resHead = (struct ListNode*) (malloc(sizeof(struct ListNode)));
    struct ListNode* temp = resHead;
    
    while(head != NULL && head->next != NULL) {
        if(head->val != head->next->val) {
            temp->next = head;
            temp = temp->next;
        } else {
            while(head->next != NULL && head->val == head->next->val) {
                head = head->next;
            }
        }
        
        head = head->next;
    }
    
    temp->next = head;
    return resHead->next;
}
