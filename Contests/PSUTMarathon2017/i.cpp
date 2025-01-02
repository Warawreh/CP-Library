#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1e4 + 10;

vector<int> g[2*N],s;
int ans[2*N];
int n,m,idx[2*N],DFS,cmp,gid[2*N],gh[2*N],low[2*N],gsz[2*N];
bool vis[2*N];
 
void dfs(int u){
	idx[u] = low[u] = ++DFS;
	s.push_back(u);
	vis[u]=1;
	for(int i=0;i<g[u].size();i++){
		int v = g[u][i];
		if(!idx[v])dfs(v);
		if(vis[v])low[u] = min(low[u],low[v]);
	}
	if(low[u] == idx[u]){
		gh[cmp] = u;
		while(1){
			int v = s.back();
			s.pop_back();
			vis[v] = 0;
			gid[v] = cmp;
			gsz[cmp]+=(v < m);
			if(v==u)break;
		}
		cmp++;
	}
}
 
int NOT(int x){
	if(x >= m)return x-m;
	return x+m;
}
 
vector<int> w;
short dp[N][N/2];

short calc(int i,int sum){
	// cout << i << ' ' << sum << ' ' << gsz[i] << '\n';
	if(i == w.size()){
		return (sum == m/2);
	}
	if(sum > m/2)return 0;
	short &ret = dp[i][sum];
	if(ret != -1)return ret;
	ret = 0;
	int id = w[i];
	if(id < gid[NOT(gh[id])]){
		ret = calc(id + 1,sum + gsz[gid[NOT(gh[id])]]) | calc(id + 1,sum + gsz[id]);
	}else{
		ret = calc(id + 1,sum);
	}
	return ret;
}

void build(int i,int sum){
	if(i == w.size()){
		return;
	}
	int id = w[i];
	if(id < gid[NOT(gh[id])]){
		if(calc(id,sum) == calc(id + 1,sum + gsz[id])){
			ans[id] = 1;
			ans[gid[NOT(gh[id])]] = 0;
			build(id + 1,sum + gsz[id]);
		}else{
			ans[id] = 0;
			ans[gid[NOT(gh[id])]] = 1;
			build(id + 1,sum + gsz[gid[NOT(gh[id])]]);

		}
	}else{
		build(id + 1,sum);
	}
}

int main(){
	fast
	cin>>m>>n;
	if(m % 2){
		cout << -1 << '\n';
		return 0;
	}
	for(int i=0;i<n;i++){
		int u,v;
		cin>>u>>v;
		u--;v--;
		g[u].push_back(NOT(v));
		g[v].push_back(NOT(u));
		g[NOT(u)].push_back(v);
		g[NOT(v)].push_back(u);
	}
	for(int i=0;i<2*m;i++)
		if(!idx[i])
			dfs(i);
	for(int i=0;i<m;i++)
		if(gid[i] == gid[NOT(i)]){
			cout << "-1\n";
			return 0;
		}
	memset(ans,-1,sizeof(ans));
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<cmp;i++){
		if(gsz[i]){
			w.push_back(i);
		}
	}
	if(calc(0,0) == 0){
		cout << -1 << '\n';
		return 0;
	}
	build(0,0);
	vector<int> a(m);
	int ate = 0;
	int atb = 1;
	for(int i=0;i<m;i++){
		if(ans[gid[i]]){
			a[ate] = i + 1;
			ate += 2;
		}else{
			a[atb] = i + 1;
			atb += 2;
		}
		// cerr << ans[gid[i]] << '\n';
	}
	for(int i : a)
		cout << i << ' ';
	puts("");
}
