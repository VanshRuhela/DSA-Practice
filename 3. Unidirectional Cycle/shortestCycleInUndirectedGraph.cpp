#include <bits/stdc++.h>
using namespace std;
#define int long long int
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
const int N = 100005, M = 22;

vector<int> graph[N];

void bfs(int src, int n, int &ans) {
    vector<int> dis(n + 1, INT_MAX);
    queue<int> Q;
    Q.push(src);
    dis[src] = 0;

    while (!Q.empty()) {
        int curr = Q.front();
        Q.pop();

        for (auto negh : graph[curr]) {
            if (dis[negh] == INT_MAX) {
                // vivisted first time
                // never vivisted
                dis[negh] = 1 + dis[curr];
                Q.push(negh);
            } else if (dis[negh] >= dis[curr]) { // dist of parent will be less then dist of curr
                ans = min(ans, dis[negh] + dis[curr] + 1);
                               // 1 -> backedge
            }
        }
    }
}

unsigned main() {
    int i, j, n, m, ans;
    cin >> n >> m;
    rep(i, m) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    ans = n + 1;
    // doing bfs on whole graph
    // 1 based indexing
    for (i = 1; i <= n; i++) {
        bfs(i, n, ans);
    }

    if (ans == n + 1) {
        cout << "no cycle\n";
    } else {
        cout << "cycle is of lenght " << ans << "\n";
    }
}