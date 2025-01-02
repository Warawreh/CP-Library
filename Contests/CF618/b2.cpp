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
	if(n % 2){
		cout << "no\n";
		return 0;
	}
	vector<pair<ll,ll>> p(n);
	int v = n/2;
	bool can = true;
	for(int i=0;i<n;i++){
		cin>>p[i].first>>p[i].second;
		if(i > v){
			ll a = (p[i].second - p[i-1].second);
			ll b = (p[i].first - p[i-1].first);
			if(a <= 0 && b <= 0 || a < 0){
				a = -a;b = -b;
			}
			ll c = (p[i-v].second - p[i-v-1].second);
			ll d = (p[i-v].first - p[i-v-1].first);
			if(c <= 0 && d <= 0 || c < 0){
				c = -c;d = -d;
			}
			if(a != c || d != b)
				can = false;
		}
	}
	cout << (can ? "yes\n" : "no\n");
}	