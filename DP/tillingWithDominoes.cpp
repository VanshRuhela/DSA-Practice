/*=============================================================================
#  PROBLEM:           tile a long 2 * n unit path using 2 * 1 unit infinite tiles in all possible ways. In this problem, 

1. You are given a number n representing the length of a floor space which is 2m wide. It's a 2 * n board.
2. You've an infinite supply of 2 * 1 tiles.

3. You are required to calculate and print the number of ways floor can be tiled using tiles. 
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

int tilling(int n) {
    // 2 ways
    // agr 2*1 verticall laga diya ->tilling( n-1) ways to tile 
    // 2*1 ko hortizontal laga do -> isko tyle krne ke tilling(1*n-2) ways of tilling

    // if(n==0){
    //     return 0;
    // }

    // if(n==1){
    //     return 1;
    // }

    // int vertical = tilling(n-1);
    // int horizontal = tilling(n-2);

    // return vertical + horizontal;

    int dp[n+1];
    dp[1] = 1;
    dp[2] = 2;

    for(int i =3; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

int main() {
    return 0;
}