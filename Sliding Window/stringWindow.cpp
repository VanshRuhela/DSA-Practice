/*=============================================================================
#  PROBLEM:          Given 2 strings 1 big string 1 small string
                    find the smallest window in the big string that contains all characters of the samll string.
                    -window can have additional chareacters than required,
                    - if small string has duplicates then those duplicates must be present with same or higher count in window

input: s1 = hello_world
       s2 = lol
output: llo
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

string maxWindow(string s, string p) {  // string - s , pattern - p

    // frequecy map for pattern
    // array as hash map
    int FP[256] = {0};  // frequency of pattern
    int FS[256] = {0};  // frequecny of string given

    for (int i = 0; i < p.length(); i++) {
        FP[p[i]]++;
    }

    // sliding window
    int start = 0;  // left contraction
    int cnt = 0;
    int start_idx = -1;
    int min_so_far = INT_MAX;
    int window_size = 0;

    for (int i = 0; i < s.length(); i++) {
        // expend the window when the frequecy mis matches
        // contract it when it matches
        char ch = s[i];
        // expend by including current char
        FS[s[i]]++;
        // count how many chars have matched till now b/w pattern and string
        if (FP[ch] != 0 and FS[ch] <= FP[ch]) {
            cnt += 1;
        }

        // if all characters of the pattern are found in the current window then you can start contracting
        if (cnt == p.length()) {
            // contract from the left to remove unwanted characters
            // umwanted = not present in the pattern
            // unwanted = frequency is higher then what is required
            while (FP[s[start]] == 0 or FS[s[start]] > FP[s[start]]) {
                FS[s[start]]--;// because its unwanted
                start++;
            }

            // note the window size
            window_size = i - start + 1;
            if (window_size < min_so_far) {
                min_so_far = window_size;
                start_idx = start;
            }
        }
    }

    if(start_idx == -1){
        return "NO window found\n";
    }

    return s.substr(start_idx, min_so_far);
}

int main() {
    string str, pat;
    cin>> str >> pat;
    cout<< maxWindow(str,pat)<<"\n";
    return 0;
}