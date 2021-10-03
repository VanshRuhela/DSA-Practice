/*=============================================================================
#  PROBLEM:          you are given a N*N matrix and a integer k s.t 1<k<N
                     first you have to form an array P, that stores the max element
                     for each submatrix of size k*k
                     Now in the array P, your task is to find the number of elements that are greater than or equal to a given value M
                     you, also need to find the max and min element greater than or equal to M in the array P

                     T testcase given : N,K,M

                     ex
                     N = 2
                     1 2
                     3 4
                     array P : {1 ,2 , 3, 4};
                     find 3 integers
                     > 

                     ans : 3 , 2 , 4 


=============================================================================*/
#include <bits/stdc++.h> 
using namespace std;




int main() {
    int N;
    vector<vector<int>> V(N, vector<int> (-1));

    for(int i=0; i<N; i++){
        cin>> V[i];
    }

   return 0;
}   