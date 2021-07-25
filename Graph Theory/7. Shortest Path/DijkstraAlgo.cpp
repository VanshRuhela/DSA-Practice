#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph {
    //using adjacency list representation
    //             key    //  connected to //  weight

    unordered_map<T, list<pair<T, int> > > l;

   public:
    void addEdge(T u, T v, int dist, bool bidir = true) {
        l[u].push_back({v, dist});
        if (bidir) {
            l[v].push_back({u, dist});
        }
    }

    void printAdj() {
        cout << "list :\n";
        for (auto p : l) {
            cout << p.first << "->";
            for (auto nbr : p.second) {
                cout << "(" << nbr.first << "," << nbr.second << ")";
            }
            cout << "\n";
        }
        
    }

    void dijkstra(T src) {
        unordered_map<T, int> dist;
        for (auto p : l) {
            dist[p.first] = INT_MAX;
        }

        // create a set to find min distance
        set<pair<int, T> > s;
        dist[src] = 0;
        s.insert({0, src});

        while (!s.empty()) {
            auto p = *(s.begin());
            T node = p.second;

            int nodeDist = p.first;
            s.erase(s.begin());

            // iterate over the nbrs of the current node
            for (auto nbr : l[node]) {
                if (nodeDist + nbr.second < dist[nbr.first]) {
                    //remove the old pair, and insert the new
                    T dest = nbr.first;
                    auto f = s.find({dist[dest], dest});

                    if (f != s.end())
                        s.erase(f);

                    // insert the new pair
                    dist[dest] = nodeDist + nbr.second;
                    s.insert({dist[dest], dest});
                }
            }
        }

        // printing all the dist from src to nbrs
        cout<<"\n";
        for (auto nbr : dist) {
            cout << nbr.first << " is located at a distance of " << nbr.second << "\n";
        }
    }
};

int main() {
    Graph<int> g;
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 4);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 2);
    g.addEdge(1, 4, 7);

    g.printAdj();

    g.dijkstra(1);

    return 0;
}