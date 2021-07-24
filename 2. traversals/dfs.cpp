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
    void addEdege (int x, int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void dfs_helper( T src, unordered_map<T, bool> & visited){
        // recursive fn that will traverse the graph
        cout << src <<" ";
        visited[src] = true;
        // go to nbrs
        for( T nbr:l[src])
            if(!visited[nbr]){
                dfs_helper(nbr, visited);
            }
        }

    void dfs(T src){
        unordered_map<T, bool> visited;
        // mark all nodes not visited
        for( auto p: l){
            T node = p.fi;
            visited[node] = false;
        }

        dfs_helper(src, visited);

    }
};

int main() {
    fast_cin();
   
   Graph<int> g;
   g.addEdege(0,1);
   g.addEdege(1,2);
    g.addEdege(2,3);
     g.addEdege(3,0);
      g.addEdege(3,4);
       g.addEdege(4,5);
    g.dfs(0);
   return 0;
}