/*=============================================================================
#  PROBLEM:          Given N cartesian Points in 2d, find the number of right triangles
such that the base or perpendicular is parallel to the X or Y axis
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

int countTriangles(vector<pair<int, int> > points) {
    map<int, int> x; // value, count
    unordered_map<int, int> y; // value, count
    for (auto point : points) {
        x[point.first]++;
        y[point.second]++;
    }


    for(auto it = x.begin(); it!=x.end(); it++){
        int key = it->first;
        int freq = it->second;

    }

    vector<int> a {7,2,3,4};
    for(auto i : a){
        cout << i;
    }



    int cnt = 0;
    for(auto point : points){

        int fx = x[point.first];
        int fy = y[point.second];

        cnt += (fx-1) * (fy-1);
    }

    return cnt;
}

int main() {
    vector<pair<int, int> > points {
        {1,2}, {2,1}, {2,2}, {2,3}, {3,2}
    };

    cout<< countTriangles(points);
    return 0;
}