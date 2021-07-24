#include <bits/stdc++.h>
using namespace std;

class Graph {
    // Adjacency list
    vector<pair<int, int>>* l;
    int V;

   public:
    Graph(int n) {
        V = n;
        l = new vector<pair<int, int>>[n];
        // weighted egdes
        // l[i] = x, pair<int,int> = y, w
    }

    void addEdge(int x, int y, int w) {
        l[x].push_back(make_pair(y, w));
        l[y].push_back(make_pair(x, w));
    }

    int prim_mst() {

        // will use minheap - priority queue to store weight , and to which it is connected to
        // way to create min heap using priority queue
        priority_queue <pair<int,int>, vector<pair<int,int>> , greater<pair<int, int> > > Q;

        // MST set array - whether a node has been included in MST or not
        bool* visited = new bool[V]{0};
        int ans=0;

        //begin
        Q.push({0,0}); // weight, node comparison is made on first element of the pair

        while(!Q.empty()){
            //pick out the edge with min weight
        }
        
    }
}

int
main() {
    return 0;
}