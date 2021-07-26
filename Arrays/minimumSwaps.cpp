/*=============================================================================
#  PROBLEM:          Given an array of size N, find minmum number of swaps needed to make the array sorted
=============================================================================*/

#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define re(i, a, n) for (int i = a; i <= n; ++i)
#define repr(i, a, n) for (int i = a; i >= n; --i)
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define R(a) \
    ll a;    \
    cin >> a;
#define endl "\n"
using namespace std;

int maxSwaps(vector<int> arr) {
    int ans = 0;
    int n = arr.size();
    // 1. know the actual positions of elements (sorting)
    // store the cureent indices

    pair<int, int> ap[n];

    for (int i = 0; i < n; i++) {
        ap[i].fi = arr[i];
        ap[i].se = i;
    }

    // sorting
    sort(ap, ap + n);

    // logic

    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
        // if element is visited or its at the right position
        int old_pos = ap[i].second;
        if (visited[i] == true or old_pos == i)
            continue;

        // visiting for the fist time
        int node = i;
        int cycle = 0;

        while (!visited[node]) {
            visited[node] = true;
            int next_node = ap[node].second;
            node = next_node;
            cycle++;
        }

        ans += cycle - 1;
    }

    return ans;
}

int main() {
    fast_cin();
    vector <int> arr{2,4,5,7,1,3,6};
    cout << maxSwaps(arr)<<"\n";
    return 0;
}