/*
Source:Linux kernel jserv
Year:2022 quiz-1
Leetcode: 82 Remove Duplicates from Sorted List II
*/

#include <stddef.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *deleteDuplicates(struct ListNode *head)
{
    if (!head)
        return NULL;

    if (COND1) {
        /* Remove all duplicate numbers */
        while (COND2)
            head = head->next;
        return deleteDuplicates(head->next);
    }

    head->next = deleteDuplicates(head->next);
    return head;
}