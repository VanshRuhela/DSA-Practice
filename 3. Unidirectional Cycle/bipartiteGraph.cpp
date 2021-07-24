#include <iostream>
#include <vector>
using namespace std;
bool dfs_helper(vector<int> graph[], int node,int parent, int* visited, int color){
    // color the node
    visited[node] = color; // 1 or 2 both means visited

    for( auto nbr : graph[node]){
        if(visited[nbr]==0){ // this means not visited any time

            bool subprob  = dfs_helper(graph, nbr, node, visited,3-color);

            if(subprob == false){ // found an odd length cycle
                return false;
            }
        }
        else if(nbr != parent and color == visited[nbr]){
            return false;
        }

    }
    return true;

}

void dfs(vector<int> graph[], int N){
    int visited[N] ={0}; // 0 - unvisited. 1-visited color is 1, 2-visited color is 2
    int color = 1;
    bool ans= dfs_helper(graph, 0,-1, visited, color);
    if(ans){
        cout<<"yos";
    }else{
        cout<<"not";
    }
}

int main(){
    int N,M;
    cin>> N>>M;
    vector<int> graph[N];
    // adjacency list 
    // undirected graph

    while(M--){
        int x,y;
        cin>>x>>y;

        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    //bfs or dfs for cycle by coloring the nodes if colour of node 1 is 1 then node 2 should have 2 and node 3 should have 1

    dfs(graph, N);

}