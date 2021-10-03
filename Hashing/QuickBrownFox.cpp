/*=============================================================================
#  PROBLEM:          Given a string without spaces and a list of words. Write a function that finds the min bars to be added to the string, so
that all resulting words in are found in the list.

IP :-string s ="thequickbrownfox"
     words -["the", "quickbrown", "fox", "quick", "brown"]
OP :- 2
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

// brute force :
//
//

string s = "thequickbrownfoxjumpsoverthehighbridge";
string words[] = {"the", "fox", "thequickbrownfox", "jumps", "lazy", "lazyfox", "highbridge", "the", "over", "bridge", "high", "tall", "quick", "brown"};

int min_bars_helper(string s, string words[], int idx, unordered_set<string>& m) {
    // base case
    if (s[idx] == '\0')
        return 0;

    // rec case
    int ans = INT_MAX;
    string curr_string = "";

    for (int j = idx; s[j] != '\0'; j++) {
        curr_string += s[j];
        // check whether this prefix is present in set or not
        if (m.find(curr_string) != m.end()) {
            int rem_ans = min_bars_helper(s, words, j + 1, m);
            if (rem_ans != -1) {  // rem prob can be solved
                ans = min(ans, 1 + rem_ans);
            }
        }
    }

    if (ans == INT_MAX)
        return -1;

    return ans ;
}

int min_bars() {
    unordered_set<string> m;

    for (string word : words) {
        m.insert(word);
    }

    // helper func
    int output = min_bars_helper(s, words, 0, m);

    return output-1;
}

int main() {
    cout << min_bars();
    return 0;
}



void helper(vector<int>&a, int target, set<vector<int>>&out,vector<int>&temp, int idx){
    if(target==0){
        out.insert(temp);
        return;
    }
    for(int i=idx;i<a.size();i++){
        
        if(a[i] > target) return;
        if(a[i] <= target)
            temp.push_back(a[i]);
        helper(a,target-a[i],out,temp,i);
        temp.pop_back();
    }
}

vector<vector<int> > Solution::combinationSum(vector<int> &a, int target) {
    sort(a.begin(),a.end());
    int n = a.size();
    set<vector<int>>out;
    vector<int>temp;
    helper(a,target,out,temp,0);
    vector<vector<int>>res;
    for(auto o : out)
        res.push_back(o);
    return res;
}