#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
	int n,m,a,b;
	cin>>n>>m>>a>>b;
	b = min(b , a*2);
	ll ans = 0;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		for(int j=0;j<m;j++){
			if(j + 1 < m && s[j] == '.' && s[j+1] == '.'){
				ans += b;
				j++;
			}else if(s[j] == '.')ans += a;
		}
	}
	cout << ans << '\n';
}

int main(){
	fast
	int t;
	cin>>t;
	while(t--)solve();
}