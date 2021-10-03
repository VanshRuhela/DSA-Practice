/*=============================================================================
#  PROBLEM:          Paint Fence problem where we are required to paint all the fences in the minimum cost such that no two consecutive fences are of the same color using dynamic programming. In this question, 

1. You are given a number n and a number k in separate lines, representing the number of fences and number of colors.
2. You are required to calculate and print the number of ways in which the fences could be painted so that not more than two fences have same colors.
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

int fence(int n, int k) {
    long same = k * 1;
    long diff = k * (k - 1);
    long tot = same + diff;

    for (int i = 2; i <= n; i++) {
        same = diff * k;
        diff = tot * (k - 1);
        tot = same + diff;
    }


    return tot;
}

int main() {
    return 0;
}