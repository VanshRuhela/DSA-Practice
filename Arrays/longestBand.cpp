/*=============================================================================
#  PROBLEM:          given an array containting N integers, find length of longest band
                     A band is defined as a subsequence which can be reordered in such a manner all elements appear consecutive
                     A longest band is the band(subsequece) which contians max integers
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

int longestBand(vector<int> a) {
    int n = a.size();
    unordered_set<int> s;
    
    for(int x : a)
        s.insert(x);
    
    int largest = 0;
    // iterate over all the elements
    for(auto element : s){
        int parent = element-1;
        if(s.find(parent) == s.end()){// if parent dosnet exist then the chain starts form there

            int next = element+1;
            int cnt = 1;
            while(s.find(next) != s.end()){
                cnt++;
                next++;
            }
            largest = max(largest, cnt);
        } 
    }   

    return largest;
}

int main() {
    fast_cin();
    vector<int> arr { 1, 9, 3, 0, 18, 5, 2, 4, 10, 7, 12, 6 };
    cout<< longestBand(arr);
    return 0;
}