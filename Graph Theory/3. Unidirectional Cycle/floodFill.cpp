#include <bits/stdc++.h>  
using namespace std;
#define int long long int
typedef long double ld;
#define rep(i,n) for(int i=0;i<n;++i)
#define re(i,a,n) for(int i=a;i<=n;++i)
#define repr(i,a,n) for(int i=a;i>=n;--i)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define R(a) ll a; cin>>a;
#define endl "\n"
using namespace std;
          // W, N, E, S
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};
int R;
int C;

void floodFill(char mat[][50], int i, int j, char ch, char color){
    // base case
    if(i<0 || j<0 || i>=R || j>=C)
        return;
    


    //figure  boundry conditions

    if(mat[i][j] != ch)
        return;

    //recursice calls
    mat[i][j] = color;
    for(int k=0; k<4; k++){
        floodFill(mat, i+dx[k], j+dy[k], ch, color);
    }
}

int main() {
    fast_cin();
    cin>>R>>C;

    char input[15][50];
    for(int i =0; i<R; i++){
        for(int j=0; j<C; j++){
            cin>>input[i][j];
        }
    }



   
   return 0;
}