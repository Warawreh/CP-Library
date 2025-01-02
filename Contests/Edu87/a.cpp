#include <bits/stdc++.h>

using namespace std;

#define fast ios::sync_with_stdio(false);cin.tie(0);
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(){
	fast
	int t;
	cin>>t;
	while(t--){
		ll a,b,c,d;
		cin>>a>>b>>c>>d;
		if(a <= b){
			cout << b << '\n';
		}else{
			if(d >= c)cout << -1 << '\n';
			else{
				a -= b;
				ll dif = c - d;
				a = (a + dif - 1)/dif;
				cout << b + c * a << '\n';
			}
		}
	}
}