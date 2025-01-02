#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<bool> isSource,on;
vector<vector<pair<int,int>>> g;
string ans;
string d = "LRDU";
bool can;
vector<vector<int>> event;
vector<int> par;

const int nax = 1e5 + 10;
int dp[nax][6][2];

int canDoIt(int u,int p,int dir){

	int ord = 0;
	for(auto &[v,d] : g[u]){
		if(v == p)break;
		if(d == dir)ord++;
	}
	ord = min(ord , 1);

	int &ret = dp[u][dir][ord];
	if(ret != -1)return ret;
	ret = 1;
	int all = 0;
	for(auto &[v,d] : g[u]){
		if(v == p)continue;
		if((all >> d) & 1)return ret = 0;
		if(d == (dir ^ 1))return ret = 0;
		all |= (1 << d);
		ret &= canDoIt(v , u, d);
		if(!ret)return ret;
	}
	return ret;
}


int dfs(int u,int p){

	int ret = -1;
	if(isSource[u])ret = u;

	int at = 0;
	for(auto &[v,i] : g[u]){
		if(v == p)continue;
		par[v] = u;
		int cur = dfs(v,u);
		if(cur == -1)continue;

		if(isSource[u]){
			if(at == 4){
				can = false;
				break;
			}
			event.push_back({cur , u , at});
			at+=2;
		}else{
			if(ret == -1)ret = cur;
			else{
				can = false;
				break;
			}
		}
	}

	if(ret != -1){
		on[u] = 1;
	}

	return ret;
}

void fixIt(int u,int p,int dir = 4){


	set<int> st;
	for(int i=0;i<4;i++)st.insert(i);
	for(auto &[v,i] : g[u]){
		if(v == p)continue;
		if(ans[i] == 'W')continue;

		for(int x=0;x<4;x++){
			if(ans[i] == d[x]){
				st.erase(x);
				break;
			}
		}
	}

	vector<int> colors;

	if(isSource[u] == 0){
		if(st.find(dir ^ 1) != st.end())
			st.erase(dir ^ 1);
	}else{
		if(st.find(dir) != st.end())
			st.erase(dir);
	}

	if(st.find(0) != st.end() && st.find(1) != st.end()){
		colors.push_back(0);
		colors.push_back(1);
		st.erase(0);
		st.erase(1);
	}else if(st.find(2) != st.end() && st.find(3) != st.end()){
		colors.push_back(2);
		colors.push_back(3);
		st.erase(2);
		st.erase(3);
	}

	while(st.size()){
		colors.push_back(*st.begin());
		st.erase(st.begin());
	}

	int at = 0;
	for(auto &[v,i] : g[u]){
		if(v == p)continue;
		if(ans[i] != 'W')continue;


		if(at == colors.size()){
			ans[i] = d[0];
			assert(0);
			fixIt(v,u , 0);
		}
		else{
			ans[i] = d[colors[at++]];
			fixIt(v,u , colors[at - 1]);
		}
	}
}

map<pair<int,int>,int> e;

void solve(){
	int n,k;
	cin>>n>>k;

	{//init
		ans = string(n-1,'W');
		isSource = on = vector<bool>(n,0);
		par = vector<int>(n,-1);
		g.clear();
		g.resize(n);
		event.clear();
		can = 1;
	}

	int st = 0;
	for(int i=0;i<k;i++){
		int u;
		cin>>u;
		u--;
		st = u;
		isSource[u] = 1;
	}

	for(int i=0;i<n-1;i++){
		int u,v;
		cin>>u>>v;
		u--;v--;

		e[{u,v}] = i;
		e[{v,u}] = i;
		g[u].push_back({v,i});
		g[v].push_back({u,i});
	}

	for(int u=0;u<n;u++){
		if(g[u].size() > 4){
			cout << "-1\n";
			return;
		}
	}

	dfs(st,-1);
	if(!can){
		cout << -1 << '\n';
		return;
	}
	for(vector<int> cur : event){
		int u = cur[0];
		int to = cur[1];
		int dir = cur[2];

		while(u != to){
			int i = e[{u,par[u]}];
			ans[i] = d[dir];
			u = par[u];
		}
	}

	for(int i=0;i<n;i++){
		if(isSource[i])
			fixIt(i,-1);
	}

	for(int i=0;i<n;i++){
		fixIt(i,-1);
	}

	for(int i=0;i<n;i++)
		for(int j=0;j<6;j++)
			for(int l=0;l<2;l++)
				dp[i][j][l] = -1;

	for(int u=0;u<n;u++){
		for(auto &[v,i] : g[u]){
			char c = ans[i];
			for(int x=0;x<4;x++){
				if(c == d[x]){
					i = x;
					break;
				}
			}

		}
	}

	for(int i=0;i<n;i++){
		if(canDoIt(i , -1 , 5)){
			if(isSource[i] == 0){
				cout << "-1\n";
				return;
			}
		}else if(isSource[i] == 1){
			cout << "-1\n";
			return;
		}
	}

	cout << ans << '\n';
}

int main(){
	fast
	int t;
	cin>>t;
	while(t--)solve();
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/