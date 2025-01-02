#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
	int n,q;
	cin>>n>>q;
	vector<pair<int,string>> s(n);
	for(int i=0;i<n;i++){
		cin>>s[i].second>>s[i].first;
		if(s[i].first * 2 < q){
			s[i].first = q - s[i].first;
			for(int j=0;j<q;j++){
				if(s[i].second[j] == 'F')s[i].second[j] = 'T';
				else s[i].second[j] = 'F';
			}
		}
	}
	sort(all(s));
	cout << s.back().second << ' ' << s.back().first << "/1\n"; 
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