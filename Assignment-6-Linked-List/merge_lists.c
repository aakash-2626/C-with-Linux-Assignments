/**
* To Run -> Test on Leetcode Q.No 21.
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

// returns the resultant head after merging the two given lists.
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* resHead = (struct ListNode*) malloc(sizeof(struct ListNode));
    struct ListNode* temp = resHead;
    
    while(l1 != NULL && l2 != NULL) {
        if(l1->val < l2->val) {
            temp->next = l1;
            l1 = l1->next;
        } else {
            temp->next = l2;
            l2 = l2->next;
        }
        
        temp = temp->next;
    }
    
    temp->next = l1 != NULL ? l1 : l2;
    return resHead->next;
}
