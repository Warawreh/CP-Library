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
		if(max(y , b - n) < max(x , a - n)){
			swap(a,b);
			swap(x,y);
		}
		ll down = min(a - x , n);
		n -= down;
		a -= down;
		down = min(b - y , n);
		n -= down;
		b -= down;
		cout << a*b << '\n';
	}	
}