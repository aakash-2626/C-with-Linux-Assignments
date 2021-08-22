/**
* To Run -> Test on Leetcode Q.No 61.
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

// returns the resultant head of the list after rotating the given list by k times.
struct ListNode* rotateRight(struct ListNode* head, int k){
    if(head == NULL || head->next == NULL || k == 0) {
        return head;
    }
    
    struct ListNode* temp = head;
    int length = 1;
    
    while(temp->next != NULL) {
        length++;
        temp = temp->next;
    }
    
    temp->next = head;
    k %= length;
    k = length - k;
    while(k-- > 0) {
        temp = temp->next;
    }
    
    head = temp->next;
    temp->next = NULL;
    
    return head;
}
