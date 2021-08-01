/*=============================================================================
#  PROBLEM:          Two strings are anagrams of each other if the letters of one string can be rearranged to dorm the other string.
Given a string that are anagrams of each other.

=============================================================================*/
#include <bits/stdc++.h> 
using namespace std;

int toNum(char c){
    return (c-'a');
}

int countAnagrams(string s){
    
    map<vector<int> , int>  mp;

    int n = s.length();
    for(int i =0; i<n; i++){
        vector<int> hash(26,0);
        for(int j = i; j<n; j++){
            hash[toNum(s[j])]++;

            mp[hash] ++;
        }
    }

    int result = 0;
    for (auto it=mp.begin(); it!=mp.end(); it++)
    {
        int freq = it->second;
        result += ((freq) * (freq-1))/2;
    }
    return result;

}
 
int main() {

    cout<< countAnagrams("xyzyx");
   return 0;
}