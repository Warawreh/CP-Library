#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int type(char c){
	if(c == 'A' || c == 'U' || c == 'E' || c == 'I' || c == 'O')return 1;
	return 0;
}

void solve(){
	string s;
	int k;
	vector<vector<int>> d(26,vector<int>(26,1e5));
	cin>>s>>k;
	for(int i=0;i<k;i++){
		string e;
		cin>>e;
		d[e[0]-'A'][e[1]-'A'] = 1;
	}
	for(int i=0;i<26;i++)d[i][i] = 0;
	for(int k=0;k<26;k++){
		for(int i=0;i<26;i++){
			for(int j=0;j<26;j++){
				d[i][j] = min(d[i][j] , d[i][k] + d[k][j]);
			}
		}
	}

	int ans = 1e9;
	for(char c = 'A';c<='Z';c++){
		int cur = 0;
		for(int i=0;i<s.size();i++){
			cur += d[s[i] - 'A'][c - 'A'];
		}
		ans = min(ans , cur);
	}
	if(ans > 26 * s.size())ans = -1;
	cout << ans << '\n';
}

int main(){
	fast
	int t;
	cin>>t;
	for(int T=1;T<=t;T++){
		cout << "Case #" << T << ": ";
		solve();
	}
}
