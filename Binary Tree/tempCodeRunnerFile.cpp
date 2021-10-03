#include <bits/stdc++.h> 
using namespace std;

string divisible(string num)
{
    
    const regex pattern("^0+(?!$)");
    num = regex_replace(num, pattern, "");


    int n = num.length();
    
    int sum = accumulate(begin(num),
                         end(num), 0) - '0' * 1;
 
    if (sum % 3 == 0)
        return num;
 
    if (n == 1)
        return "-1";
 
    for (int i = 0; i < n; i++)
        if (sum % 3 == (num[i] - '0') % 3){
            
            num.erase(num.begin() + i);
            return num;

        }
  
    if (n == 2)
        return "-1";
 
    return num.erase(num.length()-2);
}
 
int main()
{
    string num;
    cin>> num;
    cout << divisible(num)<<"\n";
}
