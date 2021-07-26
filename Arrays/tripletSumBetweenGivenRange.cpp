/*=============================================================================
#  PROBLEM:          Triplets with Sum between given range
Given an array of real numbers greater than zero in form of strings.
Find if there exists a triplet (a,b,c) such that 1 < a+b+c < 2 .
Return 1 for true or 0 for false.

Example:

Given [0.6, 0.7, 0.8, 1.2, 0.4] ,

You should return 1

as

0.6+0.7+0.4=1.7

1<1.7<2

Hence, the output is 1.

O(n) solution is expected.

Note: You can assume the numbers in strings don’t 
overflow the primitive data type and there are no leading zeroes in numbers. Extra memory usage is allowed.
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

int solve(vector<string>& arr) {
    int n = arr.size();

    vector<double> ans;
    ans.push_back(stod(arr[0]));
    ans.push_back(stod(arr[1]));
    ans.push_back(stod(arr[2]));

    sort(ans.begin(), ans.end());

    double sum = ans[0] + ans[1] + ans[2];

    for (int i = 3; i < n; i++) {
        double num = stod(arr[i]);
        if (1 < sum and sum < 2)
            return 1;
        else if (sum >= 2)
            ans[2] = num;
        else if (sum <= 2)
            ans[0] = num;
        sort(ans.begin(), ans.end());
        sum = ans[0] + ans[1] + ans[2];
    }
    if (1 < sum and sum < 2)
        return 1;
    return 0;
}

int solve2(vector<string>& arr) {
    int n = arr.size();
    if (n < 3)
        return 0;
    sort(arr.begin(), arr.end());

    int i = 0, j = n - 1;

    while (j - i >= 2) {
        int mid = (i + j) / 2;

        double a = stod(arr[i]), b = stod(arr[mid]), c = stod(arr[j]);
        double sum = a + b + c;
        if (sum > 1 and sum < 2)
            return 1;
        else if (sum > 2)
            j--;
        else
            i++;
    }
    return 0;
}

int main() {
    vector<string> arr{"0.6", "0.7", "0.8", "1.2", "0.4"};
    cout << solve(arr) << endl;
    cout << solve2(arr) << endl;
    return 0;
}