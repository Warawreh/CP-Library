#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
	int n,c;
	cin>>n>>c;
	vector<pair<int,int>> r(c);
	vector<int> p(n);
	for(int i=0;i<c;i++)cin>>r[i].first>>r[i].second;
	for(int i=0;i<n;i++){
		cin>>p[i];
		p[i]--;
		p.push_back(p[i]);
	}
	int ans = 0;
	for(int i=0;i<n + n;i++){
		vector<int> hv(c);
		int good = c;
		for(int j=i;j>=0;j--){
			if(i - j + 1 >= n)break;
			if(hv[p[j]] == 0 && r[p[j]].first != 0)good--;	
			if(hv[p[j]] == r[p[j]].second)break;
			hv[p[j]]++;
			if(hv[p[j]] == r[p[j]].first)good++;

			if(good == c && i != j){
				if(i >= n && j >= n)continue;
				cerr << j << ' ' << i << '\n';
				ans++;		
			}
		}
	}

	cout << ans << '\n';


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