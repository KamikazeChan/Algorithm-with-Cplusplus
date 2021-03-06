#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int key) {
    // find the lower_bound and upper_bound
    int start = 0, end = 1;
    while(arr[end] < key) {
        start = end;
        end = 2 * start;
    }
    while(start <= end) {
        // the safest way to find the middle of two numbers without getting an overflow
        int mid = start + (end - start) / 2;  
        
        if(arr[mid] == key)
            return mid;

        if(key > arr[mid])
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}
