/*=============================================================================
#  PROBLEM:          Given numRows, generate the first numRows of Pascal’s triangle.

Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.

Example:

Given numRows = 5,

Return

[
     [1],
     [1,1],
     [1,2,1],
     [1,3,3,1],
     [1,4,6,4,1]
]
=============================================================================*/
#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > PascalsTraingle(int numRows) {
      vector<vector<int>> r(numRows);

        for (int i = 0; i < numRows; i++) {
            r[i].resize(i + 1);
            r[i][0] = r[i][i] = 1;
  
            for (int j = 1; j < i; j++)
                r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
        }
        
        return r;
    
}


int main(){

    auto p = PascalsTraingle(8);

    for(auto i : p){
        for(int j : i){
            cout<< j <<" ";
        }
        cout<<"\n";
    }

    return 0;

}

