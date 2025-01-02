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
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		string a,b;
		cin>>a>>b;
		vector<vector<bool>> good(26,vector<bool>(26,0));
		for(int i=0;i+k-1<n;i++){
			good[a[i] - 'a'][a[i+k-1] - 'a'] = 1;
			// cerr << i << ' ' << a[i] - 'a' << ' ' << a[i+k-1] - 'a' << '\n';
		}
		vector<int> hv(26);
		ll ans = 0;
		for(int i=0;i<m;i++){
			hv[b[i] - 'a']++;
			for(int j=0;j<26;j++){
				if(good[j][b[i] - 'a'])ans += hv[j];
			}
		}
		cout << ans << '\n';
	}
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/