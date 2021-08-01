/*=============================================================================
#  PROBLEM:          Given an array, count the number of triplets with indices i,j,k such that
the elements are in GP, for a given ratio r. (i<j<k)
=============================================================================*/
#include <bits/stdc++.h> 
using namespace std;

int countTriplets(vector<int> arr, int r){
    unordered_map<int, int> left,right; // key , freq in left and right part
    int n = arr.size();
    for(int i=0; i<n; i++){
        right[arr[i]]++;
        left[arr[i]] = 0;
    }

    int cnt = 0;
    for(int i =0; i<n; i++){
        int mid_element = arr[i];
        // remove it from right
        right[arr[i]]--;

        // look for left and right
        if((left.find(mid_element/r)!= left.end()) && (right.find(mid_element*r)!=right.end())){
            cnt += left[mid_element/r]*right[mid_element*r];
        }

        // insert it in left
        left[mid_element]++;
    }

    return cnt;


} 

int main() {
    vector<int> arr { 1, 16, 4, 16, 64, 16};

    cout<< countTriplets(arr, 4);
   return 0;
}