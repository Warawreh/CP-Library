/*
Name: Strongly Connected components (SCC)
Description: Compress an undirected graph to components where each two nodes in a component can reach each other
Time: O(N) 
Space: O(N)
*/

vector<vector<int>> comp;
struct SCC{
	int T,cmp;
	vector<vector<int>> g;
	vector<int> idx,low,gid,s;
	vector<bool> vis;
	int n;
	void init(int N){// Number of vertexes in graph
		n = N;
		idx.resize(n+1);low.resize(n+1);gid.resize(n+1);vis.resize(n+1);g.resize(n+1);
	}
	void add_Edge(int u,int v){
		// cerr << u << ' ' << v << '\n';
		g[u].push_back(v);
	}
	void search_for_scc(int u){
		idx[u] = low[u] = ++T;
		s.push_back(u);
		vis[u]=1;
		for(int i=0;i<g[u].size();i++){
			int v = g[u][i];
			if(!idx[v])search_for_scc(v);
			if(vis[v])low[u] = min(low[u],low[v]);
		} 
		if(low[u] == idx[u]){ // if this is the highest vertec you can reach
			cmp++;
			vector<int> t;
			while(1){// take all the nodes under me that is in this component
				int v = s.back();
				t.push_back(v);
				s.pop_back();
				vis[v] = 0;	
				gid[v] = cmp;
				if(v == u)break;
			}
			comp.push_back(t);
		}
	}
	void make_scc(){
		for(int u=1;u<=n;u++){
			if(idx[u] == 0){ // if this vertex haven't been visited before
				search_for_scc(u); // find the SCC from vertex u
			}
		}
		// Print the group id for every node just for checking
		// for(int i=1;i<=n;i++){
		// 	cout << gid[i] << ' '; // for each vertex print its group
		// }
		// cout << '\n';
	}
};

SCC g;
