/*=============================================================================
#  PROBLEM:          Given a running stream of integers. Weite an algo to o/p median of numbers read so far after every input.
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

//
// 1,2,3,5,8,10,12
// for 1,2,3 left largest -> max heap
// for 8,10,12 right of array we need smallest element i.e min heap
//
//
//
//

int main() {
    priority_queue<int> leftheap;  // max heap
    priority_queue<int, vector<int>, greater<int>> rightheap;
    int d;
    cin >> d;
    leftheap.push(d);

    float med = d;
    cout << med << " ";

    cin >> d;
    while (d != -1) {
        // left or right or equal
        if (leftheap.size() > rightheap.size()) {
            if (d < med) {
                rightheap.push(leftheap.top());
                leftheap.pop();
                leftheap.push(d);
            }

            else {
                rightheap.push(d);
            }

            med = (leftheap.top() + rightheap.top()) / 2.0;

        }

        else if (leftheap.size() == rightheap.size()) {
            if (d < med) {
                leftheap.push(d);
                med = leftheap.top();
            }

            else {
                rightheap.push(d);
                med = rightheap.top();
            }
        }

        else {
            if (d < med) {
                leftheap.push(d);
            } else {
                leftheap.push(rightheap.top());
                rightheap.pop();
                rightheap.push(d);
            }
            med = (leftheap.top() + rightheap.top()) / 2.0;
        }

        cout << med << " ";
    }

    return 0;
}