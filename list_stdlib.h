/**
 * C program to reverse a Singly Linked List
 */

#include <stdio.h>
#include <stdlib.h>

#ifndef _LIST_STRUCT
#define _LIST_STRUCT
/* Structure of a node */
struct ListNode {
    int val;
    struct ListNode *next;
};
#endif
/* Functions used in the program */
void createList(int n, struct ListNode* head);
void createRandomList(int n, struct ListNode* head);
void displayList(struct ListNode* head);