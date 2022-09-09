/*
Name: Virtual/Auxiliary Tree
Description: Compress a Tree for some tree queries
Time: O(NLogN) to build the new tree because of LCA and sorting
Space: O(N + M) To save the new edges
*/

vector<vector<pair<ll,ll>>> aux;

int buildAux(vector<int> cur){
	sort(all(cur) , [&](int u,int v){
		return fr[u] < fr[v];
	});

	vector<int> nodes = cur;

	for(int i=1;i<cur.size();i++){
		int u = cur[i];
		int v = cur[i-1];
		int l = lca.lca(u,v);

		nodes.push_back(l);
	}

	sort(all(nodes) , [&](int u,int v){	
		return fr[u] < fr[v];
	});
	nodes.resize(unique(all(nodes)) - nodes.begin());
	
	for(int u : nodes){
		aux[u].clear();
		good[u] = 0;
	}
	for(int u : cur)good[u] = 1;

	vector<int> st = {nodes[0]};
	for(int i=1;i<nodes.size();i++){

		int u = nodes[i];
		while(st.size() >= 2 && !(fr[st.back()] <= fr[u] && to[st.back()] >= fr[u])){
			int up = st[st.size() - 2];
			int down = st.back();
			aux[up].push_back({down , lca.depth[down] - lca.depth[up]});
			st.pop_back();
		}
		st.push_back(u);

	}

	while(st.size() >= 2){
		int up = st[st.size() - 2];
		int down = st.back();
		aux[up].push_back({down , lca.depth[down] - lca.depth[up]});
		st.pop_back();
	}

	return st[0];
}
