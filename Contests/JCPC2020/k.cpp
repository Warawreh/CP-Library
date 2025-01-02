#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(){
	fast
	#ifndef LOCAL
		freopen("string.in","r",stdin);
	#endif
	int t;
	cin>>t;
	while(t--){
		int n;
		string s;
		cin>>n>>s;
		int mx = 0;
		vector<int> l(26);
		for(int i=0;i<n;i++){
			l[s[i] - 'a']++;
			mx = max(mx , l[s[i] - 'a']);
		}

		cout << n - mx << '\n';
	}
}