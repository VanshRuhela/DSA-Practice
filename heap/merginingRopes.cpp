/*=============================================================================
#  PROBLEM:     Merging Ropes     
Given N ropes each having a fifferent size, your task is join the ropes together.
The cost of joining 2 ropes of different sizes X and Y is (X+Y). Find the min cost to join all the ropes together.
IP: N = 4 
ropes[] = {4,3,2,6};
OP: 29
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

// Algo:
// 1. Add the elements in min heap
// 2. Pick the smallest pair of ropes, join them and add their cost.
// 3. Add the new rope in min heap.
// 4. Repeat untill a single rope is left

int join_ropes(int ropes[], int n) {
    priority_queue<int, vector<int>, greater<int> > pq(ropes, ropes + n);

    int cost = 0;
    while (pq.size() > 1) {
        int A = pq.top();
        pq.pop();
        int B = pq.top();
        pq.pop();

        int newRope = A + B;
        cost += newRope;
        pq.push(newRope);
    }

    return cost;
}

int main() {
    int ropes[] = {4, 3, 2, 6};
    int n = 4;
    cout << join_ropes(ropes, n) << "\n";
    return 0;
}
