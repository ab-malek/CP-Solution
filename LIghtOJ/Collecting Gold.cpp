#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// for equal type 'less_equal'

#define ll long long
#define int long long
#define nl '\n'
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define all(a) a.begin(),a.end()
#define flush fflush(stdout) 
const long long INF = 1e18;
#define check cout<<"ok"<<nl
#define printVec(v) for(int i=0;i<v.size();i++){cout<<v[i]<<" ";}cout<<nl
#define printVecPair(v) for(auto it : v){cout<<it.first<<" "<<it.second<<nl;}
// bool cmp(pair<int,int> &a, pair<int,int> &b){return a.second < b.second;}
#define SetBit(x, k) (x |= (1LL << k))
#define ClearBit(x, k) (x &= ~(1LL << k))
#define CheckBit(x, k) ((x>>k)&1)
#define dbg(x) cerr << #x << " " << x << "\n";
// const int mod = 998244353;
// const int N  = 2e5+5;
const int N = 20;
int dp[N][(1<<16)];
int dist[N][N];
vector<pair<int,int>> v(N);
int n,m;
int ct = 1;

int helper(int i,int mask){

	if( ((1<<ct) - 1)   == mask){
		return dist[i][0];
	}

	if(dp[i][mask] != -1) return dp[i][mask];
	int ans = INT_MAX;

	for(int j=1;j<ct;j++){
		if(!CheckBit(mask,j)){
			// dbg(j);
			// dbg(j);
			ans = min(ans, dist[i][j] + helper(j,mask | (1<<j)));
		}
	}

	return dp[i][mask] = ans;
}


void ab_malek(){
	cin>>n>>m;
	char ar[n+1][m+1];
	ct = 1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>ar[i][j];
			if(ar[i][j] == 'g'){
				v[ct] = {i,j};
				ct++;
			}
			else if(ar[i][j] == 'x'){
				v[0] = {i,j};
			}
		}
	}


	for(int i=0;i<ct;i++){
		for(int j=i+1;j<ct;j++){
			dist[i][j] = dist[j][i] = max(abs(v[i].first - v[j].first), abs(v[i].second - v[j].second));
			// dbg(dist[i][j]);
		}
	}

	memset(dp,-1,sizeof(dp));
	// dbg(ct);
	// dbg(dp[1][2]);
	cout<<helper(0,1)<<nl;


}		

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int _t = 1;
    cin>>_t;
    for(int i = 1;i<=_t;i++){
    	cout<<"Case "<<i<<": ";
    	ab_malek();
    }
}
