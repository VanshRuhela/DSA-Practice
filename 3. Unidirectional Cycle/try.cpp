#include <bits/stdc++.h>  
using namespace std;
typedef long long int ll;
typedef long double ld;
#define P 1000000007
#define rep(i,n) for(int i=0;i<n;++i)
#define re(i,a,n) for(i=a;i<=n;++i)
#define repr(i,a,n) for(i=a;i>=n;--i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ub(v,val) upper_bound(v.begin(),v.end(),val)
#define np(str) next_permutation(str.begin(),str.end())
#define lb(v,val) lower_bound(v.begin(),v.end(),val)
#define sortv(vec) sort(vec.begin(),vec.end())
#define rev(p) reverse(p.begin(),p.end());
#define mset(a,val) memset(a,val,sizeof(a));
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 

void solve(){
    string s; 
    cin>>s;
    int flag = 0;
    if(is_sorted(s.begin(), s.end())){
        cout<<"YES\n";
    }
    else{
        int y =0;
        for(int i = s.length()-1; i>0; i--){
                if(s[i] == '0' && s[i-1] =='0'){
                    y = i-1;
                    flag =1;
                    break;
                }
            }
            if(flag == 0){
                cout <<"YES\n";
                 return;
            }
            int flag2 =0;
            for(int i =y; i>0; i --){
                if(s[i] =='1' && s[i-1] == '1'){
                    flag2 = 1;
                    break;
                }
            }
            if(flag2==0){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
                return;
            }
     }

}
int main()
{
    fast_cin();
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++) {
        solve();
    }
    return 0;
}