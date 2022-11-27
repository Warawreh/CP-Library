/*
Name: Trie
Description: Convert string into a tree 
Time: O(N) where N is the sum of all string size added for build. O(H) where H is the height of the tree
Space: O(N) 
*/

struct Trie{
	vector<vector<int>> g;
	vector<int> have,sz;

	int max_edge;

	void init(int x){
		max_edge = x;
		g.push_back(vector<int> (max_edge,-1));
		have.push_back(0);
	}

	void add(vector<int> val){
		int cur = 0;
		for(int k=0;k<val.size();k++){
			int b = val[k];
			if(g[cur][b] == -1){
				g[cur][b] = g.size();
				have.push_back(0);
				g.push_back(vector<int> (max_edge , -1));
			}
			cur = g[cur][b];
		}
		have[cur]++;
		
	}

	void dfs(int u,int p){
		for(int v : g[u]){
			if(v == -1)continue;
			dfs(v,u);
			sz[u] += sz[v];
		}
	}

	void build(){
		sz = have;
		dfs(0,-1);
	}

	int get(vector<int> val){
		int res = 0;
		int cur = 0;
		for(int k=0;k<val.size();k++){
			int b = val[k];
			
			cur = g[cur][b];
		}
		return res;
	}
};
