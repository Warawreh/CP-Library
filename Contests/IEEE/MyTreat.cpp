#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

unordered_map<string,int> to;
int at;
vector<int> in,out;

inline int get(string &s){
	if(to[s] == 0){
		in.push_back(0);
		out.push_back(0);
		to[s] = ++at;
	}
	return to[s];
}

void solve(){
	int n;
	cin>>n;

	to.clear();
	in = out = {0};
	at = 0;

	for(int i=0;i<n;i++){
		string s;
		int k;
		cin>>s>>k;
		int u = get(s);
		for(int j=0;j<k;j++){
			cin>>s;
			int v = get(s);
			out[u]++;
			in[v]++;
		}
	}

	int m=0,d=0;
	for(int i=1;i<=at;i++){
		if(in[i] >= out[i])continue;
		// cerr << i << ' ' << in[i] << ' ' << out[i] << '\n';
		m += out[i] - in[i];
		d = max(d, out[i] - in[i]);
	}
	cout << m << ' ' << d <<'\n';
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