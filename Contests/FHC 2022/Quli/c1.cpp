#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
	int n;
	string s;
	cin>>n>>s;
	string neg = s;
	for(int i=0;i<s.size();i++){
		if(neg[i] == '.')neg[i] = '-';
		else neg[i] = '.';
	}

	cout << '\n';
	for(int i=0;i<n-1;i++){
		string cur = string(n, '.') + neg;
		cur[i] = '-';
		cout << cur << '\n';
	}
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