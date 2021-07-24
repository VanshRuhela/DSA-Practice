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

template <typename T>
//generic type of graph

class Graph{

    unordered_map<T, list <T>> l;
    //using map to make the adjaceny list
    // not a weighted graph

    public:
    void addEdge(T x, T y){
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void bfs(T src){
        unordered_map<T, bool> visited;
        queue<T> q;

        q.push(src);
        visited[src] = true;

        while(!q.empty()){
            T node = q.front();
            q.pop();

            cout<< node <<" ";
            
            for(auto nbr : l[node]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }

    }
};




int main() {
    fast_cin();
    Graph<int> g;

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(3,0);

    g.bfs(0); 
   
   return 0;
}