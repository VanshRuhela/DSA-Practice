#include <bits/stdc++.h>  
using namespace std;


int main() {
    
   int s, r , c;
   cin>>s>>r>>c;

   vector< vector<int>> m;
   int k = s;
   for(int i=0; i<r; i++){
       vector<int> col (c);
       for(int j =0; j<c; j++){
           col[j] = k;
           k++;
       }
       m.push_back(col);
   }


   // transpose

   vector< vector<int>> t( c, vector<int> (r, 0));
   for(int i=0; i<c; i++){
       for(int j =0; j<r; j++){
           t[i][j] = m[j][i];
       }
   }
   

    for(int i=0; i<r; i++){
        for(int j =0; j<r; j++){
            int sum =0;
            for(int k =0; k<c; k++){
                sum += m[i][k] * t[k][j];
            }
            cout << sum <<" ";
        }
        cout << "\n";
    }


   return 0;
}