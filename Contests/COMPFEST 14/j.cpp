#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<vector<pair<ll,ll>>> g;
vector<ll> depth,diameter;
ll ans = 0,all;


void calc(ll u,ll p){

	depth[u] = diameter[u] = 0;

	for(auto &[v,w] : g[u]){
		if(v == p)continue;

		calc(v,u);

		depth[v] += w;
		diameter[u] = max({diameter[u] , depth[u] + depth[v], diameter[v]});
		depth[u] = max(depth[u] , depth[v]);

	}

}

void calcUp(ll u,ll p,ll D,ll ud){
	vector<ll> mxDia = {D,0};
	vector<ll> d = {ud,0,0,0};


	for(auto &[v,w] : g[u]){
		if(v == p)continue;

		mxDia.push_back(diameter[v]);
		sort(all(mxDia));
		reverse(all(mxDia));
		mxDia.pop_back();

		d.push_back(depth[v]);
		sort(all(d));
		reverse(all(d));
		d.pop_back();

	}

	ans = min(ans , all * 2 - (d[0] + d[1] + d[2] + d[3]));

	for(auto &[v,w] : g[u]){
		if(v == p)continue;

		ll upDiamiter = mxDia[0];
		if(upDiamiter == diameter[v])upDiamiter = mxDia[1];

		ll curDepth = depth[v];
		if(curDepth == d[0])upDiamiter = max(upDiamiter , d[1] + d[2]);
		else if(curDepth == d[1])upDiamiter = max(upDiamiter , d[0] + d[2]);
		else upDiamiter = max(upDiamiter , d[0] + d[1]);

		ll mxDepth = d[0];
		if(d[0] == curDepth)mxDepth = d[1];

		ans = min(ans , (all - w)*2LL - diameter[v] - upDiamiter);

		calcUp(v,u,upDiamiter,mxDepth + w);


	}

	ans = min(ans , all*2 - diameter[u]);
}

int main(){
	fast
	ll n;
	cin>>n;

	g.resize(n);
	depth = diameter = vector<ll>(n,0);
	ans = 1e18;
	all = 0;

	for(ll i=0;i<n-1;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		u--;v--;
		all += w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}

	calc(0,-1);
	calcUp(0,-1,0,0);

	if(n == 1)ans = 0;

	cout << ans << '\n';
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/