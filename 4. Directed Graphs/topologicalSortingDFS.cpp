#include <bits/stdc++.h>
using namespace std;

template <typename T>

class Graph {
    unordered_map<T, list<T>> l;

   public:
    void addEdge(T x, T y) {
        l[x].push_back(y);
        //directiional
    }

    void dfs_helper(T src, unordered_map<T, bool>& visited, list<T>& ordering) {
        visited[src] = true;

        for (T nbr : l[src]) {
            if (!visited[nbr]) {
                dfs_helper(nbr, visited, ordering);
            }
        }

        ordering.push_front(src);
        return;
    }

    void dfs() {
        unordered_map<T, bool> visited;
        list<T> ordering;
        cout << "size of hash map :" << l.size() << "\n";
        // mark all the nodes !visited
        for (auto p : l) {
            T node = p.first;
            visited[node] = false;
        }

        // call the helper
        for (auto p : l){
            cout<< p.first<<"\n";
        }

        for (auto p = l.begin(); p != l.end(); p++) {
            T node = p->first;
            cout << "calling the fuction on node :" << node << "\n";
            cout << "Size of order after it : " << ordering.size() << "\n";
            if (!visited[node])
                dfs_helper(node, visited, ordering);
        }

        for (auto p : visited) {
            cout << p.first << " visited :? " << p.second << "\n";
        }
        for (auto node : ordering)
            cout << node << endl;
    }
};

int main() {
    Graph<string> g;

    g.addEdge("Python", "DataPreprossing");
    g.addEdge("Python", "Pytorch");
    g.addEdge("Python", "ML");
    g.addEdge("DataPreprossing", "ML");
    g.addEdge("Pytorch", "DL");
    g.addEdge("ML", "DL");
    g.addEdge("DL", "facerecog");
    g.addEdge("DataSet", "facerecog");

    g.dfs();
}