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
	int o=0;
	vector<ll> a[2];
	vector<ll> r(n),l(n);
	for(int i=0;i<n;i++){
		if(s[i] == '1'){
			o++;
			a[o % 2].push_back(i);
		}
	}
	int len = 0;
	for(int i=0;i<n;i++){
		if(s[i] == '1'){
			l[i] = len + 1;
			len = 0;
		}else{
			len++;
		}
	}

	len = 0;
	for(int i=n-1;i>=0;i--){
		if(s[i] == '1'){
			r[i] = len + 1;
			len = 0;
		}else len++;
	}

	ll ans = 0;
	for(int T=0;T<2;T++){
		ll sum = 0;
		for(int i=0;i<a[T].size();i++)sum += r[a[T][i]];

		for(int i=0;i<a[T].size();i++){
			sum -= r[a[T][i]];
			ans += l[a[T][i]] * sum;
			ans += (l[a[T][i]] - 1) * (r[a[T][i]] - 1);
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

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/