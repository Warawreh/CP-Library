#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int nax = 1010;
vector<int> g[nax];

int main(){
	fast
	int t;
	cin>>t;
	while(t--){ 
		int n,x;
		cin>>n>>x;
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=0;i<n-1;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if(g[x].size() <= 1){
			cout << "Ayush\n";
		}else{
			cout << (n%2 ? "Ashish\n" : "Ayush\n");
		}
	}
}