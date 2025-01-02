#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll p[100];
const int nax = 1e6;
ll sum[nax],sum2[nax];

int main(){
	fast
	int t;
	p[0] = 1;
	for(int i=1;i<=18;i++)p[i] = p[i-1] * 10LL;
	for(int i=1;i<nax;i++){
		ll x = floor(log10(10*i));
		sum[i] = (i + 1) * x - (p[x] - 1) / 9;
		sum2[i] = sum2[i-1] + to_string(i).length();
		sum[i] += sum[i-1];
	}
	string s;
	for(int i=1;i<=nax;i++){
		s += to_string(i);
		if(s.size() >= (int)1e5)break;
	}
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		
		ll lo=0,hi = nax-1,ans=0;
		while(lo <= hi){
			ll md = (lo + hi)/2;
			ll cur = sum[md];
			if(cur < n){
				ans = md;
				lo = md+1;
			}else hi = md-1;
		}
		n -= sum[ans];
		cout << s[n-1] << '\n';
	}
}