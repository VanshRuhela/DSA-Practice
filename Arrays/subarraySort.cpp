/*=============================================================================
#  PROBLEM:          Subarray sort,return the starting and ending index of the subarray which is not sorted, such that after sorting it 
                     the whole array becomes sorted
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

// order of NlogB + N
pair<int, int> subarraySort1(vector<int> arr) {
    vector<int> sorted = arr;
    sort(sorted.begin(), sorted.end());
    int i, j;
    for (i = 0; i < arr.size(); i++) {
        if (arr[i] != sorted[i])
            break;
    }

    for (j = arr.size() - 1; j >= 0; j--) {
        if (arr[j] != sorted[j])
            break;
    }

    if (i == arr.size()) {
        return {-1, -1};
    }

    return {i, j};
}

// order of N
pair<int, int> subarraySort2(vector<int> arr) {
    // 1. find the smallest and largest element which is out of order
    // 2. find the places where they should be placed

    int smallest = INT_MAX, greatest = INT_MIN;

    for (int i = 1; i < arr.size() - 1; i++) {
        if (arr[i] < arr[i - 1])
            smallest = min(smallest, arr[i]);
        if (arr[i] > arr[i + 1])
            greatest = max(arr[i], greatest);
    }

    if (smallest == INT_MAX)
        return {-1, -1};

    int left = 0;
    while (smallest >= arr[left])
        left++;

    int right = arr.size() - 1;
    while (greatest <= arr[right])
        right--;

    return {left, right};
}

int main() {
    fast_cin();
    vector<int> arr{1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11};
    auto p = subarraySort1(arr);
    auto q = subarraySort2(arr);
    cout<<"1st : " << p.first <<" "<<p.second;
    cout<<"\n2nd : " << q.first <<" "<<q.second;
    return 0;
}