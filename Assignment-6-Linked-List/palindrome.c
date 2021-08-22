/**
* To Run -> Test on Leetcode Q.No 234.
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

// finds the middle of the given linked list.
// param : struct ListNode* head - head of the linked list.
// return : struct ListNode* - middle node of the list.
struct ListNode* findMiddle(struct ListNode* head) {
    if(head->next == NULL) {
        return head;
    }
    
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    
    while(fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}

// reverses the given linked list.
// param : struct ListNode* head - head of the linked list.
// return : struct ListNode* - head of the reversed list.
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* next = NULL;
    
    while(head != NULL) {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    
    return prev;
}

// checks if given linked list is palindrome or not.
// param : struct ListNode* head - head of the linked list.
// return : int - 1 is list is palindrome else 0.
int isPalindrome(struct ListNode* head){
    if(head->next == NULL) {
        return 1;
    }
    
    struct ListNode* midOfList = findMiddle(head);
    struct ListNode* head2 = midOfList->next;
    midOfList->next = NULL;
    
    head2 = reverseList(head2);
    
    while(head != NULL && head2 != NULL) {
        if(head->val != head2->val) {
            return 0;
        }
        
        head = head->next;
        head2 = head2->next;
    }
    
    return 1;
}

