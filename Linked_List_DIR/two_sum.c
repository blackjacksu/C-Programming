/*
Source:Linux kernel jserv
Year:2022 quiz-2
Leetcode: 82 Remove Duplicates from Sorted List II
*/

#include <stdlib.h>
static int cmp(const void *lhs, const void *rhs) {
    if (*(int *) lhs == *(int *) rhs)
        return 0;
    return *(int *) lhs < *(int *) rhs ? -1 : 1;
}

static int *alloc_wrapper(int a, int b, int *returnSize) {
    *returnSize = 2;
    int *res = (int *) malloc(sizeof(int) * 2);
    res[0] = a, res[1] = b;
    return res;
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    *returnSize = 2;
    int arr[numsSize][2];  /* {value, index} pair */
    for (int i = 0; i < numsSize; ++i) {
        arr[i][0] = nums[i];
        arr[i][1] = i;
    }
    qsort(arr, numsSize, sizeof(arr[0]), cmp);
    for (int i = 0, j = numsSize - 1; i < j; ) {
        if (arr[i][0] + arr[j][0] == target)
            return alloc_wrapper(arr[i][1], arr[j][1], returnSize);
        if (arr[i][0] + arr[j][0] < target)
            ++i;
        else
            --j;
    }
    *returnSize = 0;
    return NULL;
}