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
	int r,c,m;
	cin>>r>>c>>m;
	vector<int> x(r+1,c + 1),y(c+1,r + 1);
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		if(x[a] == 0 || b < x[a])x[a] = b;
		if(y[b] == 0 || a < y[b])y[b] = a;
	}
	set<pair<int,int>> cell;
	for(int i=1;i<=r;i++){
		// cerr << x[i] << ' ';
		if(x[i] == 1)break;
		cell.insert({i,1});

	}
	// cerr << '\n';
	for(int i=1;i<=c;i++){
		if(y[i] == 1)break;
		cell.insert({1,i});
	}
	cell.erase({1,1});
	ll ans = 0;
	for(auto it : cell){
		int a = it.first;
		int b = it.second;
		// cerr << a << ' ' << b << '\n';
		if(a == 1){
			ans += y[b] - 1;
			// cerr << y[b] - 1 << '\n';
		}else{
			ans += x[a] - 1;
			// cerr << x[a] - 1 << '\n';
		}
	}

	cout << ans + 1 << '\n';
}