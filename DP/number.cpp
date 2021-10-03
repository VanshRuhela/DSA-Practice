/*=============================================================================
#  PROBLEM:          Number of words
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

int findSentencesHavingWord(vector<map<string, int>> line, string word){

    int cnt =0;
    for(auto l : line){

        if(l.find(word) != l.end()){
            cnt ++;
        }
    }

    return cnt;
}

vector<vector<float>> fn(vector<string> document) {
    int n = document.size();  // tot lines
    map<string, int> totalw;
    vector<map<string, int>> line(n);  // words rakhega line ke

    vector<vector<pair<string, int>>> l;
    
    for (int i = 0; i < n; i++) {
        string s = document[i];  //  tOm hello? ,tom
        // ????? ///// *****
        int sn = s.size();
        string temp;

        map<string, int> t;

        for (int j = 0; j < sn; j++) {
            char c = s[j];
            // a-z or A-Z
            if ((c < 'Z' and c > 'A') || (c > 'a' and c < 'z')) {
                temp.push_back(tolower(c));
            }
            
            else if(c == ' ') {
                if (!temp.empty()) {
                    totalw[temp]++;
                    t[temp]++;
                    temp.erase();
                }
            }
        }
        if (!temp.empty()) {
            totalw[temp]++;
            t[temp]++;
            temp.erase();
        }

        line[i] = t;
    }

    vector<vector<float>> res;

    // ans = (freq of word in sentence / no words in the sentence) * (no of sentensce / no of sents haveing this word)

    for (int i = 0; i < n; i++) {
        map<string, int> m;
        vector<float> a;
        m = line[i];

        float word_in_line = m.size();

        for(auto word : m){
            
            float freq_word = word.second;

            float tot_freq_word = findSentencesHavingWord(line,word.first);

            float ans = ((freq_word)/(float)(word_in_line))*(((float)n/tot_freq_word));

            a.push_back(ans);

        }

        res.push_back(a);
        
        
    }
    return res;


}

int main() {
    vector<string> d { "Hello Tom" , "hello Jerry" , "How are you, Tom, tom?" };

   vector<vector<float>> res= fn(d);

   for(auto i : res){
       for(auto j : i){
           cout << j << " ";
       }
       cout<<"\n";
   }
}