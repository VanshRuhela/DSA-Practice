/*=============================================================================
#  PROBLEM:     Housing   
                Along one side od a road there is a squence of vancant plots of land. Each plot of land has a differnt area,
                So, the areas form a squence A[1], A[2] .... A[N]

                You want to buy K acres of land to build a house, you want to find all the segments of continguous plots of whose sum is exactly K
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> > housing(vector<int> plots, int k) {

    int n = plots.size();
    int i = 0, j = 0, curr_sum = 0;

    vector<pair<int,int>> ans;

    while (j < n){

        // moving towards right
        curr_sum += plots[j];
        j++;

        // remvoe elements form the left till curr_sum > sum and i<j
        while(curr_sum > k and i < j){
            curr_sum -= plots[i];
            i++;
        }

        // check
        if(curr_sum == k){
            ans.push_back({i, j-1});
        }
    }

    return ans;
}

int main() {
    vector<int> plots{1, 3, 2, 1, 4, 1, 3, 2, 1, 1};

    

    for(auto i : housing(plots, 8)){
        cout<< i.first << " "<< i.second<<"\n";
    }
    return 0;
}