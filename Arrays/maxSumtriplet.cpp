/*=============================================================================
#  PROBLEM:          Problem Description

Given an array A containing N integers.

You need to find the maximum sum of triplet ( Ai + Aj + Ak ) such that 0 <= i < j < k < N and Ai < Aj < Ak.

If no such triplet exist return 0.



Problem Constraints
3 <= N <= 105.

1 <= A[i] <= 108.



Input Format
First argument is an integer array A.



Output Format
Return a single integer denoting the maximum sum of triplet as described in the question.



Example Input
Input 1:

 A = [2, 5, 3, 1, 4, 9]
Input 2:

 A = [1, 2, 3]


Example Output
Output 1:

 16
Output 2:

 6


Example Explanation
Explanation 1:

 All possible triplets are:-
    2 3 4 => sum = 9
    2 5 9 => sum = 16
    2 3 9 => sum = 14
    3 4 9 => sum = 16
    1 4 9 => sum = 14
  Maximum sum = 16
Explanation 2:

 All possible triplets are:-
    1 2 3 => sum = 6
 Maximum sum = 6
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;


// O(N^2) sol
// logic : greedily find the max every time in left and right part of the array
//          krrping the mid element fixed and then finding the max of all
int solve2loop(vector<int>& arr) {
    int n = arr.size();
    int ans = 0;

    for (int i = 0; i < n - 1; i++) {
        int max1 = 0, max2 = 0;

        //find max val less then arr[i]
        //from 0 to i-1
        for (int j = 0; j < i; j++) {
            if (arr[i] < arr[j])
                max1 = max(max1, arr[j]);
        }

        //find max value greater than arr[i]
        // from i+1 to n-1
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i])
                max2 = max(max2, arr[j]);
        }

        // strong the max ans
        if (max1 and max2) {
            ans = max(ans, max1 + arr[i] + max2);
        }
    }

    return ans;
}


// Best method: maximum suffix-array and binary search. 

// For finding a maximum number greater than given number beyond it, 
// we can maintain a maximum suffix-array such that for any number(suffixi)
// it would contain maximum number from index i, i+1, … n-1. Suffix array can be calculated in O(n) time.

// For finding maximum number smaller than the given number preceding it, we can maintain a sorted list of
// numbers before a given number such we can simply perform a binary search to find a number which is just
// smaller than the given number. can be done using set


int solve(vector<int>& A) {
    int n = A.size();

    // max suffice array for right
    vector<int> right(n);
    right[n - 1] = A[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        right[i] = max(right[i + 1], A[i]);
    }

    set<int> s;
    s.insert(A[0]);
    int ans = 0;

    for (int i = 1; i < n - 1; i++) {
        if (A[i] >= right[i + 1])
            continue;

        s.insert(A[i]);
        auto it = s.lower_bound(A[i]); // to get the 2nd max 

        if (it == s.begin())
            continue;

        it--;
        ans = max(ans, *it + A[i] + right[i + 1]);
    }

    return ans;
}

int main() {
    return 0;
}