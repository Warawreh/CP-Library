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
	int n;
	cin>>n;
	vector<ll> a(n),p(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
		p[i] = a[i] + (i ? p[i-1] : 0LL);
	}
	vector<int> pos,to(n);
	pos.push_back(n-1);
	vector<ld> ans(n);
	ans[n-1] = a[n-1];
	to[n-1] = n-1;
	for(int i=n-2;i>=0;i--){
		while(pos.size() > 1){
			ll r1 = pos.back();
			ll r2 = pos[pos.size() - 2];
			ll sum1 = (p[r1] - (i ? p[i-1] : 0LL)) * (r2 - i + 1);
			ll sum2 = (p[r2] - (i ? p[i-1] : 0LL)) * (r1 - i + 1);
			if(sum2 < sum1){
				pos.pop_back();
			}else{
				break;
			}
		}
		to[i] = pos.back();
		int r1 = to[i];
		ll sum1 = (p[r1] - (i ? p[i-1] : 0LL));
		if(a[i] * (r1 - i + 1) <= sum1){
			to[i] = i;
			pos.push_back(i);
		}
	}
	int l=0,r=0;
	while(l < n){
		r = to[l];
		ld sum = p[r] - (l ? p[l-1] : 0LL);
		sum /= ld(r - l + 1);
		while(l <= r){
			ans[l] = sum;
			l++;
		}
	}
	cout << setprecision(10) << fixed;
	for(int i=0;i<n;i++)cout << ans[i] << '\n';
}