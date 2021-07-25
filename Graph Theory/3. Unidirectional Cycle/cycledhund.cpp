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

class Graph{
    int V;
    list<int>* l;
public:
    Graph(int V){
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int x, int y){
        l[x].pb(y);
        l[y].pb(x);
    }

    bool cycle_help(int node, bool* visited, int parent){
        visited[node] = true;
        for(auto nbr: l[node]){
            if(!visited[nbr])
            {
                bool cycle_mila = cycle_help(nbr, visited, node);
                if(cycle_mila)
                return true;
            }
            else if( nbr != parent){
                return true;
            }
        }
        return false;
    }

    bool containsCycle(){
        bool *visited = new bool[V];
        rep(i,V){
            visited[i] = false;
        }
        return cycle_help(0,visited,-1);
    }
};


int main() {
    fast_cin();
     Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(2,3);
    g.addEdge(1,2);
    cout<<g.containsCycle();
   
   return 0;
}