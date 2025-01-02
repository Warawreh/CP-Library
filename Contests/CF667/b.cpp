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
		ll a,b,x,y,n;
		cin>>a>>b>>x>>y>>n;
		ll ans1,ans2;
		{
			ll aa=a,bb=b;
			ll n2 = n;
			ll down = min(a - x , n);
			n -= down;
			a -= down;
			down = min(b - y , n);
			n -= down;
			b -= down;
			ans1 = a*b;
			n = n2;
			a = aa;b = bb;
		}
		{
			ll n2 = n;
			ll down = min(b - y , n);
			n -= down;
			b -= down;
			down = min(a - x , n);
			n -= down;
			a -= down;
			ans2 = a*b;
			n = n2;
		}
		cout << min(ans1,ans2) << '\n';
	}	
}