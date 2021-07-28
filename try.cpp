/*=============================================================================
#  PROBLEM:           Prob 
=============================================================================*/
#include <bits/stdc++.h> 
using namespace std;
 
int solve(int n, int k, vecotr<vector<int>> arr){

    multimap<int,pair<int,int>> r;
    for(int i=0; i<n; i++){
        
        if(arr[i][0]+arr[i][1] > arr[i][1]+arr[i][2]){
             r.insert(arr[i][0]+arr[i][1], {0,1});
        }
        else{
            r.insert(arr[i][1]+arr[i][2], {1,2});
        }
    }
    multimap<int,pair<int,int>> c;

    int max = INT_MIN;
    for(int i=1; i<n; i++){

    }

}


int main() {
   return 0;
}