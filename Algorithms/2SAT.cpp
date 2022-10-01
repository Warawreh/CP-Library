/*
Name: 2-SAT
Description: For some number of vars (a,b,c) assign values (0,1) to them such that some boolean 
expresion is satisfied:
(a | !b) & (!a | b) & ...
Time: O(n + m)
Space: O(N) 
*/

vector<int> g[N],s;
int ans[N];
int n,m,idx[N],DFS,cmp,gid[N],gh[N],low[N];
bool vis[N];
 
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
			if(v==u)break;
		}
		cmp++;
	}
}
 
int NOT(int x){
	if(x >= m)return x-m;
	return x+m;
}
 
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int u,v;
		char a,b;
		cin>>a>>u>>b>>v;
		u--;v--;
		if(a == '-')u = NOT(u);
		if(b == '-')v = NOT(v);
		g[NOT(u)].push_back(v);
		g[NOT(v)].push_back(u);
	}
	for(int i=0;i<2*m;i++)
		if(!idx[i])
			dfs(i);
	for(int i=0;i<m;i++)
		if(gid[i] == gid[NOT(i)]){
			cout << "IMPOSSIBLE\n";
			return 0;
		}
	memset(ans,-1,sizeof(ans));
	for(int i=0;i<cmp;i++)
		if(ans[i] == -1){
			ans[i] = 1;
			ans[gid[NOT(gh[i])]] = 0;
		}
	for(int i=0;i<m;i++){
		if(ans[gid[i]])printf("+");
		else printf("-");
	}
	puts("");
}
