//
//  searchSortUtils.c
//  Hello
//
//  Created by Hui Zhou on 6/7/14.
//  Copyright (c) 2014 Hui Zhou. All rights reserved.
//

#include <stdio.h>
#include "searchSortUtils.h"


void shellsort(int v[], int n){
    int gap, i, j, temp;
    
    for(gap = n/2; gap > 0; gap /= 2)
        for(i = gap; i < n; i++)
            for(j = i - gap; j >=0 && v[j] > v[j + gap]; j-= gap){
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }
}


/* Search functions */
int binsearch(int x, int v[], int n)
{
    int low, high, mid;
    
    low = 0;
    high = n - 1;
    //    while (low <= high) {
    //        mid = (low+high) / 2;
    //        if (x < v[mid])
    //            high = mid - 1;
    //        else if (x > v[mid])
    //            low = mid + 1;
    //        else    /* found match */
    //            return mid;
    //    }
    while(low < high){
        mid = (low + high) / 2;
        
        if(x <= v[mid])
            high = mid;
        else
            low = mid + 1;
        
    }
    
    if(v[low] == x)
        return low;
    else
        return -1;    /* no match */
}

void qsort(int v[], int left, int right){
    int i, last;
    void swap(int v[], int i, int j);
    
    if(left >= right)
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for(i = left+1; i <= right; i++)
        if(v[i] < v[left])
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}
void swap(int v[], int i, int j){
    int temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}