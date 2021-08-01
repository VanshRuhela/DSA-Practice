/*=============================================================================
#  PROBLEM:          Given N cartesian Points in 2D plane, find the number of axis parallel rectangles that can be formed?
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

int countRectangles(vector<pair<int, int>> points, int n) {
    // puting all the points for search
    set<pair<int, int>> s;

    for (auto p : points) {
        s.insert(p);
    }

    // logic
    
    int ans = 0;
    for (auto it = s.begin(); it != prev(s.end()); it++) {
        // not going till the last but to second last
        for (auto jt = next(it); jt != s.end(); jt++) {
            pair<int, int> p1 = *it;
            pair<int, int> p2 = *jt;

            if (p2.first == p1.first or p2.second == p1.second)
                continue;

            // try to find P3 and P4

            pair<int, int> p3 = {p1.first, p2.second};
            pair<int, int> p4 = {p2.first, p1.second};

            if (s.find(p3) != s.end() and s.find(p4) != s.end()) {
                ans += 1;
            }
        }
    }

    return ans / 2;
}

int main() {
    vector<pair<int, int>> arr{
        {0, 0}, {0, 1}, {1, 1}, {1, 0}, {2, 1}, {2, 0}, {3, 1}, {3, 0}};

    cout << countRectangles(arr, 8);

    return 0;
}