#include <bits/stdc++.h>  
using namespace std;
typedef long long int ll;
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
template<typename T>
class Graph{
   unordered_map<T, list<T>> l;

    public:

    int fact(int n){
        int res = 1;
        for (int i = 2; i <= n; i++)
        res = res * i;
        return res;
    };
 
    int nCr(int n, int r)
    { return fact(n) / (fact(r) * fact(n - r));}
 

    void addEdege (int x, int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }

    int dfs_helper( T src, unordered_map<T, bool> & visited){
        // recursive fn that will traverse the graoh
      
        visited[src] = true;
        // go to nbrs
        for( T nbr:l[src])
            if(!visited[nbr]){
               return 1+dfs_helper(nbr, visited);
            }
        return 1;
        
        }

    void dfs(int n){
        unordered_map<T, bool> visited;
        // mark all nodes not visited
        for( auto p: l){
            T node = p.fi;
            visited[node] = false;
        }
        int cnt=0;

        vector <int> country_size;

        for(auto p: visited){
            T node = p.fi;
           
            if(!visited[node])
               {    cnt++; 
                    int c = dfs_helper(node,visited);
                    country_size.push_back(c);
               }
           
        }

        // astronout choisce
        int totalAst = nCr(n, 2);
        int bothSame =0;
        for(int i : country_size){
            bothSame += nCr(i,2);
        }
        cout << totalAst - bothSame <<"\n";
    }
};

int main() {
    fast_cin();
    Graph <int> g;
    int n; int p;
    cin>>n;
    cin>>p;
    rep(i,p){
        int f,s;
        cin>> f >> s;
        g.addEdege(f,s);
    }
    g.dfs(n);
    
   return 0;
}