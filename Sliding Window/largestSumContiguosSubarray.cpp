/*=============================================================================
#  PROBLEM:          find the maximum sum of contiguous subarray
=============================================================================*/
#include <bits/stdc++.h> 
using namespace std;

int maxSumSubarray(vector<int> arr){
    int n = arr.size();
    int i=0, max_sum=INT_MAX, max_end=0;

    while(i<n){
        max_end += a[i];
        if(max_sum < max_end){
            max_sum = max_end;
        }

        if(max_end < 0)
            max_end = 0;
    }

    return max_sum;
}


// when all the numbs are -ve
// dp based
int maxSumNeg(vector<int> arr){
    int max_so_far = arr[0];
    int curr_max = arr[0];

    for(int i=1; i<arr.size(); i++){
        curr_max = max(a[i], curr_max+a[i]);
        max_so_far = max(max_so_far, curr_max);
    }

    return max_so_far;
}
 
int main() {
   
   return 0;
}