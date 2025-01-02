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
		int n,x,y;
		cin>>n>>x>>y;
		vector<int> ans(n,1e9);
		for(int d = 1;d <= 100;d++){
			vector<int> cur;
			int good = 0;
			int st = y % d;
			if(st == 0)st+=d;
			int dif = y - st;
			if(dif / d >= n){
				int need = (dif/d) - n + 1;
				st += need * d;
			}
			if(st > x)continue;
			for(int j=0;j<n;j++){
				if(j*d+st == x || j*d+st == y)good++;
				cur.push_back(d*j+st);
			}
			if(good != 2)continue;
			if(cur.back() < ans.back())
				ans = cur;
		}
		for(int i : ans){
			cout << i << ' ';
		}
		cout << '\n';
	}	
}