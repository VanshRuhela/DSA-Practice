#include <iostream>
#include <unordered_map>
using namespace std;
#include<list>

class Graph {
     unordered_map <string, list < pair < string, int>>> l; // as we have strings as key therfore we made a hash map
                   // key ,  Value // value -> list of pairs of <string,int> string -> connected to, int-> value i.e the weight
    
     public:
     void addEdge(string x, string y, bool bidir, int wt){
         // x,y are connected node , bidir is for unidirectional or bidirectional 
         
         l[x].push_back(make_pair(y, wt));
         if(bidir){
             l[y].push_back(make_pair(x,wt));
         }
     }

     void print(){
         for(auto p : l){
             // map -> 2 vals, 1st is key 2nd is val 
             string city = p.first; // key of map
             cout<< city  << "->";
             list<pair<string, int>> nbrs = p.second; // val of the key
             for(auto nbr : nbrs){
                 string des = nbr.first; // list is an array of pairs
                 int dist = nbr.second;
                 cout<< des << " " <<dist <<", ";
             }
             cout<<endl;
         }
     }
};

int main(){
    Graph g;
    g.addEdge("A", "B", true, 20);
    g.addEdge("D", "B", true, 30);
    g.addEdge("C", "D", true, 50);
    g.addEdge("A", "C", true, 10);
    g.addEdge("A", "D", false, 50);
    g.print();
}