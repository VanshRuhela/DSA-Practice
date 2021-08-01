/*=============================================================================
#  PROBLEM:          sorting using heap
=============================================================================*/
#include <bits/stdc++.h> 
using namespace std;

class Compare{
    public:
    bool operator()(int a, int b){
        return a>b;
    }
};
 
int main() {

    int arr[] = {10,15,20,13,6,90};
    int n = sizeof(arr)/sizeof(int);

    priority_queue<int> heap; // max heap

    for(int x : arr){
        heap.push(x);
    }

    for(!heap.empty()){
        cout<< heap.top() <<"\n";
        heap.pop();
    }

    // to cheate heap
    priority_queue<int, vector<int> , greater<int>> minheap;
        //                             own comaptator

    priority_queue<int, vector<int> , Compare >> minheapCompare;




   return 0;
}       