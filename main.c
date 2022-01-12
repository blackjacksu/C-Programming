#include <stdio.h>

#include "list_stdlib.h"
#include "two_sum.h"
#include "merge_sort.h"
#include "has_cycle.h"
#include "merge_sorted_list.h"
#include "string_encryption.h"



int test_has_cycle()
{
    
    return 0;
}

int test_merge_sort()
{
    int num1[6] = {1,2,3,0,0,0};
    int num2[3] = {2,5,6};
    int m = 3;
    int n = 3;
    int num1_sz, num2_sz = 0;

    num1_sz = sizeof(num1)/sizeof(int);
    num2_sz = sizeof(num2)/sizeof(int);
    merge(num1, num1_sz, m, num2, num2_sz, n);

    return 0;
}

int test_merge_sorted_list()
{
    struct ListNode * list_one;
    struct ListNode * list_two;
    struct ListNode * list_merged;
    
    int n, choice;

    /*
     * Create a singly linked list of n nodes
     */
    printf("Enter the total number of nodes for list 1 ");
    scanf("%d", &n);
    createList(n, list_one);
    
    printf("Enter the total number of nodes for list 2 ");
    scanf("%d", &n);
    createList(n, list_two);

    list_merged = mergeTwoLists(list_one, list_two);
    printf("\nData in the merged list\n");
    displayList(list_merged);

    return 0;
}

int test_string_encryption()
{
    FILE* fptr = fopen("string_encryption.txt", "w");

    char* s = readline();

    char* result = encryption(s);

    fprintf(fptr, "%s\n", result);

    fclose(fptr);

    return 0;
}


int main(){

    int option = 65535;
    int test_result = 0;
    while (option != 0)
    {
        printf("Enter the test number:\n");
        printf("[0] Terminated the process\n");
        printf("[1] Merge-sort two array\n");
        printf("[2] List has cycle\n");
        printf("[3] Merge two sorted lists\n");
        printf("[4] String Encryption\n");
        scanf("%d", &option);
        switch (option)
        {
            case 0:
                break;
            case 1:
                test_result = test_merge_sort();
                break;
            case 2:
                test_result = test_has_cycle();
                break;
            case 3:
                test_result = test_merge_sorted_list();
                break;
            case 4:
                test_result = test_string_encryption();
                break;
            default:   
                break;
        }
        printf("Test result: %d\n", test_result);
    }

    printf("See you next time\n");
    return 0;
}