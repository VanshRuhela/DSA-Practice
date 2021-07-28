#include<bits/stdc++.h>
#define fi first
#define se second
#define INF 100000000000000000LL
#define ll  long long 
#define debug(x) cout << #x << " "<< x <<endl; 
#define debug_vector(v) cout << #v << " "; _print(v);
const ll inf =1e9+44;
const int MAX=3e5+9;
const ll MOD= 1e9+7;
const double eps=1e-10;
double const PI=3.1415926535897931;
using namespace std;
int dx[4] = {1 ,0 , - 1, 0};
int dy[4] = {0 ,1 ,  0 , -1};


void _print(vector<int> v){
	cout << "[ ";
	for ( auto u : v)
		cout << u << " ";
	cout << " ]"<< endl;
}
vector < int > adj[MAX];

int dp[MAX][2];
int col[MAX];
int ans = 0;
void dfs(int u , int p){

	dp[u][col[u]]=1;
	int dif[2];
	dif[1]=dif[0]=0;
	for (auto v : adj[u]){
		if(v==p)
			continue;
		dfs(v , u);

		dp[u][col[u]]=max(dp[v][1-col[u]]+1 + dif[1-col[u]] , dp[u][col[u]]);
		dif[col[v]]=max(dif[col[v]] , dp[v][col[v]]);
	}

	ans = max(ans , dp[u][col[u]]);
}


int main(){
	int n;

	string s;
	cin >> s;

	for (int i = 0  ; i < s.size(); i++)
		col[i+1] = s[i]-'a';

	int u;
	n = s.size();
	for (int i=0 ; i < n; i++){
		cin >> u;
		if(u==-1)
			continue;
		else
		{
			adj[u+1].push_back(i+1);
			adj[i+1].push_back(u+1);
		}
	
	}

	dfs(1 , 0);

	cout << ans << endl;



}