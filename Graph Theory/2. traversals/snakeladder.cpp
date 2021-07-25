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
      
    }

    void bfs(T src, T dest){

        map<T, int> dist;
        map<T, T> parent;
        queue<T> q;
        
        // source will have distance 0 all other nodes will have distance infinity
        
        
        for( auto node_pair : l){
            T node = node_pair.first;
            dist[node] = INT_MAX;
        }

        dist[src] = 0;
        parent[src] = src;
        q.push(src);


        while(!q.empty()){
            T node = q.front();
            q.pop();

            for(int nbr : l[node]){
                if(dist[nbr] == INT_MAX){
                    q.push(nbr);
                    dist[nbr] = dist[node] + 1;
                    parent[nbr] = node;
                }
            }
        }

        //printting the dist for destination node only

        // for( auto node_pair : l){
        //     T node = node_pair.first;
        //     int d = dist[node];
        //     cout<< "Node " << node <<" D from src " << d <<"\n";
        // }

        cout << dist[dest] <<endl;
        // path from dest to source
        T temp = dest;
        while(temp != src){
            cout << temp << "<--";
            temp = parent[temp];
        }
        cout << src <<endl;
        
    }
};



int main() {
    fast_cin();
    
    int board[50] = {0};



    board[2] = 13;
    board[9] = 18;
    board[18] = 11 ;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = 10;
    board[32] = -2;
    board[34] = -22;

    // Add Edges to the graph
    Graph<int> g;
    rep(i,37){
        for(int dice = 1; dice<=6; dice++){
            int j = i+ dice;
            j+= board[j];
            //directed edegs
            if( j <=36){
                g.addEdge(i,j);
            }
        }
    }

    g.addEdge(36, 36);

    g.bfs(0, 36);

   return 0;
}