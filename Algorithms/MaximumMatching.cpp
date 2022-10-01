/*
Name: Maximum Biprtite matching
Description: find the maximum edges of the graph so no two edges share a node in a biprtite graph
Time: O(NM) 
Space: O(N + M)
*/

template<int SZ> struct MAXM{
	vector<int> g[SZ];
	bool seen[SZ];
	int matchR[SZ],n,m;

	void init(int N,int M){
		n = N;
		m = M;
	}
		
	bool bpm(int u){ 
	    for(int v : g[u]){ 
	        if (!seen[v]){
	            seen[v] = true;
	            if (matchR[v] == -1 || bpm(matchR[v])){
	                matchR[v] = u; 
	                return true; 
	            }
	        }
	    }
	    return false; 
	} 
	void maxBPM(){
	    memset(matchR, -1, sizeof(matchR)); 
	    int result = 0;
	    for (int u=0;u<n; u++) { 
	        memset(seen, 0, sizeof(seen)); 
	        if (bpm(u)) result++;
	    } 
	    cout << result << endl;
	    for(int i=0;i<SZ;i++){
	    	if(matchR[i] == -1)continue;
	    	cout << matchR[i] << ' ' << i << '\n';
	    }
	}
};

