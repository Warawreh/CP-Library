#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

bool ispal(string a){
	vector<int> l(26);
	for(char c : a)l[c - 'a']++;
	int w = 0;
	for(int i : l)w += i % 2;
	return w <= 1;
}

int main(){
	fast
	#ifndef LOCAL
		freopen("name.in","r",stdin);
	#endif
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		map<string,int> f;
		for(int i=0;i<n;i++){
			string s;
			cin>>s;
			sort(all(s));
			f[s]++;
		}
		ll ans = 0;
		ll hv = 0;
		for(auto it : f){
			ans += it.second / 2;
			if(it.second % 2){
				if(ispal(it.first))
					hv = 1;
			}
		}
		cout << (ans * 2 + hv) * m << '\n';
	}
}