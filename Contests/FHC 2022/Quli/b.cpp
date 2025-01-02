#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
	int n,m;
	cin>>n>>m;
	int tc = 0;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		for(int j=0;j<m;j++)tc += (s[j] == '^');
	}
	
	if(tc == 0){
		cout << "Possible\n";
		for(int i=0;i<n;i++)cout << string(m,'.') << '\n';
		return;
	}

	if(n == 1 || m == 1){
		cout << "Impossible\n";
		return;
	}

	cout << "Possible\n";
	for(int i=0;i<n;i++)cout << string(m,'^') << '\n';

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