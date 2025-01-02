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
	int t = 1;
	while(t--){
		int n,q,k;
		cin>>n>>q>>k;
		ll ans = 0;
		vector<ll> pre(n),a(n);
		for(int i=0;i<n;i++){
			cin>>a[i];
			if(i)pre[i] = pre[i-1];
			if(i >= 2)pre[i] += a[i] - a[i-2] - 2;
		}
		for(int i=0;i<q;i++){
			int l,r;
			cin>>l>>r;
			l--;r--;
			if(l == r)cout << k-1 << '\n';
			else if(r - l == 1){
				cout << a[r]-2 + k-a[l]-1 << '\n';
			}else{
				cout << pre[r] - pre[l + 1] + a[l+1]-2 + k-a[r-1]-1 << '\n';
			}
		}
	}
}