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
		int n,k;
		string s;
		cin>>n>>k>>s;
		vector<pair<int,int>> pre(n);
		bool can = 1;
		int o=0,z=0;
		for(int i=0;i<n;i++){
			if(i >= k){
				if(s[i-k] == '1')o--;
				if(s[i-k] == '0')z--;	
			}
			if(s[i] == '1')o++;
			if(s[i] == '0')z++;
			if(o * 2 > k || z * 2 > k){
				can = 0;
				break;
			}
			if(i <= k-1){
				pre[i] = {(s[i] == '0') + (i ? pre[i-1].first : 0),(s[i] == '1') + (i ? pre[i-1].second : 0)};
			}else{
				pre[i] = {k/2 + pre[i-k].first,k/2 + pre[i-k].second};
			}
		}
		for(int i=k;i<n;i++){
			// cerr << pre[i].first << ' ' << pre[i-k].first << '\n';
			if(pre[i].first - (pre[i-k].first) != k/2){
				can = 0;
				break;
			}
		}
		cout << (can ? "Yes\n" : "No\n");
	}
}