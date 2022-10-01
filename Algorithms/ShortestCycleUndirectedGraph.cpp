int shortest_cycle(int n){
    for(int i=1;i<=n;i++){
  		if(g[i].empty())continue;
		memset(depth,-1,sizeof(depth));  
        vector<int> par(n+1, -1); 
        depth[i] = 0; 
        queue<int> q; 
        q.push(i); 
        while(q.size()){
            int u = q.front(); 
            q.pop(); 
            for(int v : g[u]){
                if (depth[v] == -1){ 
                    depth[v] = 1 + depth[u]; 
                    par[v] = u;
                    q.push(v); 
                }else if (par[u] != v && par[v] != u) 
                    ans = min(ans, depth[u] + depth[v] + 1); 
            } 
        } 
    } 
    if (ans == 1e9)ans = -1;
    return ans;
} 
