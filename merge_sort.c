#include <stdio.h>
#include <stdlib.h>

#include "merge_sort.h"

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int i, j;
    int temp;
    
    if (nums1Size == m+n)
    {
        for (i = m ; i < m+n ; i++)
        {
            nums1[i] = nums2[i-m];
        }
    }

    for (i = 0 ; i < nums1Size ; i++)
    {
        for (j = 0 ; j < nums1Size - 1 ; j++)
        {
            if (nums1[j] > nums1[j+1])
            {
                // swap
                temp = nums1[j];
                nums1[j] = nums1[j+1];
                nums1[j+1] = temp;
            }
        }
    }

}