/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include "merge_sorted_list.h"
#include "list_stdlib.h"

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    
    struct ListNode * head;
    struct ListNode * temp;

    if (list1->val <= list2->val)
    {
        head = list1;
        list1 = list1->next;
    }
    else
    {
        head = list2;
        list2 = list2->next;
        head->next = list1;
    }

    while (list1 && list2)
    {
        if (list1->val <= list2->val)
        {
            list1 = list1->next;
        }
        else
        {
            // Insert element to list1(head)
            temp = list1->next;
            list1->next = list2;
            list2 = list2->next;
            list1 = list1->next;
            list1->next->next = temp;
        }
    }

    return head;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){

}