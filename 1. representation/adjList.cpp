#include <iostream>
using namespace std;
#include <list>

class Graph{
    int V;
    //array of list
    list<int>* l; // this is a pointer to the list 
    public:
        Graph(int V){
            this->V = V;
            l = new list<int>[V]; // dynamically making an array of lists 
        }

        void addEdge(int x, int y){
            l[x].push_back(y);
            l[y].push_back(x);
        }

        void printAdjList(){
            //iterate over vertices
            for(int i =0; i <V; i++){
                cout<<"Vertex " <<i << "->";
                for(int nbr :l[i] ){
                    cout<< nbr << " ";
                }
                cout<<"\n";
            }

        }

};

int main(){
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(2,3);
    g.addEdge(1,2);
    g.printAdjList();
}