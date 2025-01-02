#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


struct Trie{
	vector<vector<int>> g;
	vector<int> hv,sz;

	int max_edge;

	void init(int x){
		max_edge = x;
		g.push_back(vector<int> (max_edge,-1));
		hv.push_back(0);
	}

	void add(string val){
		int cur = 0;
		for(int k=0;k<val.size();k++){
			int b = val[k] - 'a';
			if(g[cur][b] == -1){
				g[cur][b] = g.size();
				hv.push_back(0);
				g.push_back(vector<int> (max_edge , -1));
			}
			cur = g[cur][b];
		}
		hv[cur]++;
		
	}


	int get(string val){
		int cur = 0;
		for(int k=0;k<val.size();k++){
			int b = val[k] - 'a';
			cur = g[cur][b];
		}
		return hv[cur];
	}
};

int main(){
    fast
    int n,c;
    cin>>n>>c;

    Trie tree;
    tree.init(26);
    vector<string> s(n);
    for(int i=0;i<n;i++){
    	cin>>s[i];

    	for(char x='a';x<='z';x++){
    		string cur = s[i];
    		for(int j=0;j<c;j++){
    			if(cur[j] == '*'){
    				cur[j] = x;
    				break;
    			}
    		}
	    	tree.add(cur);
    	}
    }

    string ans="";
    int mx = -1;
    for(int i=0;i<n;i++){
    	cin>>s[i];

    	for(char x='a';x<='z';x++){
    		string cur = s[i];
    		for(int j=0;j<c;j++){
    			if(cur[j] == '*'){
    				cur[j] = x;
    				break;
    			}
    		}
	    	int hv = tree.get(cur);
	    	if(hv > mx){
	    		mx = hv;
	    		ans = cur;
	    	}
	    	if(hv == mx)ans = min(ans , cur);
    	}
    }
    cout << ans << ' ' << mx << '\n';
}
