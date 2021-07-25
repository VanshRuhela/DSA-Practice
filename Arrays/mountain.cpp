/*=============================================================================
#  PROBLEM: Write a function to i/p an array of distinct integres and resturn the length of the highest mountain.
            Mountain is defined as adjacent integers that are strictly increasing until they reach a peak, at which they become striclty decreasing.
            At least 3 numbers are req to form a mountain.        
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

/*================================
        Logic part
=======================================*/

int mountians(vector<int> a) {
    int n = a.size();

    int largest = 0;

    for (int i = 1; i <= n - 2;) {
        // check for peak
        if (a[i] > a[i - 1] and a[i] > a[i + 1]) {
            // check left and right
            int cnt = 1;
            int j = i;
            //count backwards
            while(j>=1 and a[j]>a[j-1]){
                j--; cnt++;
            }
            while(i<=n-2 and a[i]>a[i+1]){
                i++;
                cnt++;
            }

            largest = max(largest, cnt);

        } else {
            i++;
        }
    }

    return largest;
}

int main() {
    fast_cin();
    vector<int> arr{5, 6, 1, 2, 3, 4, 5, 4, 3, 2, 0, 1, 2, 3, -2, 4};
    cout << mountians(arr);
    return 0;
}