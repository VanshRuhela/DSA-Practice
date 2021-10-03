#include <bits/stdc++.h>
using namespace std;

vector<int> arrange(int N, vector<vector<int> >& H) {
    vector<int> sol;
    for (int k = 0; k < N; k++) {
        int maxx = INT_MIN;
        int ind = -1;
        for (int i = 0; i < N; i++) {
            if (find(sol.begin(), sol.end(), i) != sol.end())
                continue;

            int count = 0;
            for (int j = 0; j < N; j++) {
                if (find(sol.begin(), sol.end(), j) == sol.end())
                    count += H[i][j] - H[j][i];
            }

            if (count > maxx) {
                maxx = count;
                ind = i;
            }
        }
        sol.push_back(ind);
    }
    for (int a = 0; a < N; a++) {
        sol[a]++;
    }
    return sol;
}

int main() {
    vector<vector<int>> v{{0, 7, 2},
                          {4, 0, 8},
                          {10, 1, 0}};

    vector<int> ans = arrange(3, v);
    for (int i : ans) {
        cout << i << " ";
    }
}