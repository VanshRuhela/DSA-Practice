/*=============================================================================
#  PROBLEM:           merge k sorted arrays
Given k sorted arrays of different sizes, produce a single sorted array
I/P:
k=3
A1 ={1,3,15}, A2={2,4,6}, A3={0,9,10,11}
op : 0 1 2 3 4 6 9 10 11 15
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int> > ppi;

vector<int> mergeKarrays(vector<vector<int> > arr) {
    vector<int> op;
    priority_queue<ppi, vector<ppi>, greater<ppi> > pq;

    for (int i = 0; i < arr.size(); i++) {
        pq.push({arr[i][0], {i, 0}});
    }

    while (!pq.empty()) {
        ppi curr = pq.top();
        pq.pop();

        int i = curr.second.first;
        int j = curr.second.second;

        op.push_back(curr.first);

        if (j + 1 < arr[i].size()) {
            pq.push({arr[i][j + 1], {i, j + 1}});
        }
    }

    return op;
}
int main() {
    vector<vector<int> > arr{{2, 6, 12},
                             {1, 9},
                             {23, 34, 90, 2000}};

    vector<int> output = mergeKarrays(arr);

    for (auto x : output){
        cout<< x <<" ";
    }

        return 0;
}