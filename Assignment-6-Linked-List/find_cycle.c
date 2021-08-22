/**
* To Run -> Test on Leetcode Q.No 142.
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


// returns the node where the cycle begins. If there is no cycle, returns NULL.
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow == fast) {
            slow = head;
            
            while(slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            
            return slow;
        }
    }
    
    return NULL;
}
