#include <bits/stdc++.h>
using namespace std;
// optimised by path compression(for find function) and Union by Rank
class Graph {
    int V;
    list<pair<int, int>> l;
    // edge list represenation
    // 1<->2<->3<->4 rep:: (1,2) , (2,3) , (3,4)

   public:
    Graph(int V) { this->V = V; }

    void addEdge(int u, int v) {
        l.push_back(make_pair(u, v));
        // list of pairs
    }

    // DSU O/P find and union

    int findSet(int i, int parent[]) {
        if (parent[i] == -1) return i;

        return parent[i] = findSet(parent[i], parent);
    }

    void union_Set(int x, int y, int parent[], int rank[]) {
        int s1 = findSet(x, parent);
        int s2 = findSet(y, parent);

        // if (s1 != s2) {
        //     parent[s2] = s1;
        // }

        if (s1 != s2) {
            if (rank[s1] < rank[s2]) {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            } else {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }

    // cycle detection by DSU

    bool contains_cycle() {
        int* parent = new int[V];
        int* rank = new int[V];
        // V sets
        for (int i = 0; i < V; i++) {
            parent[i] = -1;
            rank[i] = 1;
        }

        // iterate over edge list
        for (auto edge : l) {
            int i = edge.first;
            int j = edge.second;

            int s1 = findSet(i, parent);
            int s2 = findSet(j, parent);

            if (s1 != s2) {
                union_Set(s1, s2, parent, rank);
            } else {
                cout << "no union " << s1 << " " << s2 << "\n";
                return true;
            }
        }

        delete[] parent;
        delete[] rank;
        return false;
    }
};

int main() {
    Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);  // back edge

    cout << g.contains_cycle() << "\n";
    return 0;
}