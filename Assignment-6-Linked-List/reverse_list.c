/**
* To Run -> Test on Leetcode Q.No 92.
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

// reverses the list between node numbers left and right and returns the resultant head.
struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    struct ListNode* dummy = (struct ListNode*) malloc(sizeof(struct ListNode));
    dummy->next = head;
            
    struct ListNode* prevLeft = NULL;
    struct ListNode* curLeft = dummy;
    for(int i = 0; i < left; i++) {
        prevLeft = curLeft;
        curLeft = curLeft->next;
    }
    
    struct ListNode* prevRight = prevLeft;
    struct ListNode* curRight = curLeft;
    for(int i = left; i <= right; i++) {
        struct ListNode* next = curRight->next;
        curRight->next = prevRight;
        prevRight = curRight;
        curRight = next;
    }
    
    prevLeft->next = prevRight;
    curLeft->next = curRight;
    
    return dummy->next;
}
