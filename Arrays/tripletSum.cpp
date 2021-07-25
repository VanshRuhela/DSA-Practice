#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> triplets(vector<int> arr, int sum) {
    //1. sort
    sort(arr.begin(), arr.end());

    // Pick every a[i] , do pair sum (2 pointer)
    vector<vector<int>> result;
    int n = arr.size();

    for (int i = 0; i <= n - 3; i++) {
        int s = i + 1;
        int e = n - 1;

        // 2 pointer
        while (s < e) {
            int curr_sum = arr[i];
            curr_sum += arr[s] + arr[e];

            if (curr_sum == sum) {
                result.push_back({arr[i], arr[s], arr[e]});
                s++;
                e--;
            }

            else if (curr_sum > sum) {
                e--;
            } else {
                s++;
            }
        }
    }

    return result;
}

int main() {
    vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 16, 32};
    int S = 18;

    auto res = triplets(arr, S);

    for (auto p : res) {
        for (int i : p) {
            cout << i << " ";
        }
        cout << "\n";
    }
}