#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
	vector<vector<int>> a(3,vector<int>(4));
	vector<int> b(4,1e7);
	for(int i=0;i<3;i++){
		for(int j=0;j<4;j++){
			cin>>a[i][j];
			b[j] = min(b[j] , a[i][j]);
		}
	}
	vector<int> c(4,0);
	int need = 1e6;
	for(int i=0;i<4;i++){
		int take = min(need , b[i]);
		c[i] = take;
		need -= take;
	}
	if(need == 0){
		for(int i=0;i<4;i++)
			cout << c[i] << ' ';
		cout << '\n';
	}else{
		cout << "IMPOSSIBLE\n";
	}
}

int main(){
	fast
	int t;
	cin>>t;
	for(int T=1;T<=t;T++){
		cout << "Case #" << T << ": ";
		solve();
	}
}