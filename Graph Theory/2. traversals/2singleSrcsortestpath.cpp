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

class Graph{

    map<T, list <T>> l;

    public:
    void addEdge(T x, T y){
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void bfs(T src){

        unordered_map<T, int> dist;
        queue<T> q;
        
        // source will have distance 0 all other nodes will have distance infinity
        
        
        for( auto node_pair : l){
            T node = node_pair.first;
            dist[node] = INT_MAX;
        }

        dist[src] = 0;
        q.push(src);


        while(!q.empty()){
            T node = q.front();
            q.pop();

            for(auto nbr : l[node]){
                if(dist[nbr] == INT_MAX){ // unvisisted if true
                    q.push(nbr);
                    dist[nbr] = dist[node] + 1;
                }
            }
        }

        //printing the dist for every node

        for( auto node_pair : l){
            T node = node_pair.first;
            int d = dist[node];
            cout<< "Node " << node <<" D from src " << d <<"\n";
        }
    }
};




int main() {
    fast_cin();
    Graph <int>  g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(0,3);
    g.addEdge(3,4);
    g.addEdge(4,5);

    g.bfs(0);

   return 0;
}