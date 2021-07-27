/*=============================================================================
#  PROBLEM:          Given a string, write a funciton to find the largest substring with unique characters(no duplicates)
                     Sample input:
                     prateekbhaiya
                     aabcb

                     Sample output:
                     ekbhaiy
                     abc
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

string uniqueSubstringHashing(string str) {
    // last occurence of current character
    unordered_map<char, int> m;

    int i = 0, j = 0;

    int window_len = 0;
    int start_window = -1;
    int max_window_len = 0;

    while (j < str.length()) {
        char ch = str[j];
        // check whether it is inside hashmap & its idx >= start of the current window
        if (m.count(ch) and m[ch] >= i) {
            i = m[ch] + 1;
            window_len = j-i; // updated rem window len excluding current char

        }

        // update the lase occurance
        m[ch] = j;
        window_len++;
        j++;
        // update max window length
        if(window_len > max_window_len){
        max_window_len =  window_len;
        start_window = i;
        }
    }

    return str.substr(start_window, max_window_len);
}

int main() {
    string s;
    cin>>s;
    cout<< uniqueSubstringHashing(s);
    return 0;
}