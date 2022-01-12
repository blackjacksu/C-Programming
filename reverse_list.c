/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include "reverse_list.h"

struct ListNode* reverseList(struct ListNode* head){
    struct  ListNode * prevNode;
    struct  ListNode * currNode;

    prevNode = NULL;
    currNode = head;

    while (head != NULL)
    {
        currNode = head->next;
        head->next = prevNode;
        prevNode = head;
        head = currNode;
    }

    head = prevNode;

    return head;
}