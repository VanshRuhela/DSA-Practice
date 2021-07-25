#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    list<int>* l;

   public:
    Graph(int V) {
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int x, int y) {
        l[x].push_back(y);
        // directed graph
    }

    bool cycle_helper(int node, bool* visited, bool* path) {
        // visiting a node
        visited[node] = true;
        path[node] = true;

        for (int nbr : l[node]) {
            // two cases
            if (path[nbr] == true)  // back edge case , found in path
                return true;

            if (visited[nbr] == false) {
                bool subprob = cycle_helper(nbr, visited, path);
                if(subprob == true)
                    return true;
            }
        }

        // leaving a node
        path[node] = false;
        return false;
    }

    bool contains_cycle() {
        bool* visited = new bool[V];
        bool* path = new bool[V];  // stack to store the current processing  path

        for (int i = 0; i < V; i++) {
            visited[i] = false;
            path[i] = false;
        }

        return cycle_helper(0,visited, path);
    }
};

int main() {
    Graph g(7);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 2);  //back edge
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.addEdge(1, 5);

   cout<< g.contains_cycle();
    return 0;
}