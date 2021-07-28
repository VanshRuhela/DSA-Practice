/*=============================================================================
#  PROBLEM:          Sliding Window Maximum (Maximum of all subarrays of size k)

Given an array and an integer K, find the maximum for each and every contiguous subarray of size k.

Examples : 

Input: arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6}, K = 3 
Output: 3 3 4 5 5 5 6
Explanation: 
Maximum of 1, 2, 3 is 3
Maximum of 2, 3, 1 is 3
Maximum of 3, 1, 4 is 4
Maximum of 1, 4, 5 is 5
Maximum of 4, 5, 2 is 5 
Maximum of 5, 2, 3 is 5
Maximum of 2, 3, 6 is 6

Input: arr[] = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13}, K = 4 
Output: 10 10 10 15 15 90 90
Explanation:
Maximum of first 4 elements is 10, similarly for next 4 
elements (i.e from index 1 to 4) is 10, So the sequence 
generated is 10 10 10 15 15 90 90
=============================================================================*/
#include <bits/stdc++.h> 
using namespace std;

// 1. brute force (2 nested loops)

void printMax(int arr[], int n, int k){
    int j , maxe;
    for(int i=0; i<=n-k; i++){
        maxe = arr[i];
        for(j=1; j<k; j++){
            maxe = max(max, arr[i+j]);
        }
        cout<< maxe <<" ";
    }
}

int printMaxusingdeque(int arr[], int n, int k){
    
}
 
int main() {
   
   return 0;
}   