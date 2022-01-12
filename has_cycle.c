#include "has_cycle.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
        
    bool ret = false;
    struct ListNode *ptr_end = head;
    struct ListNode *ptr;
    
    while (ptr_end->next)
    {
        ptr = head;
        while (ptr != ptr_end)
        {
            if (ptr_end->next == ptr)
            {
                // List cycle detected
                ret = true;
                break;
            }
            ptr = ptr->next;
        }
        if (ret)
        {
            break;
        }

        ptr_end = ptr_end->next;
    }
    // End of list
    return ret;
}