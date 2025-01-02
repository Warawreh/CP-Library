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
		int n;
		cin>>n;
		vector<pair<int,int>> a(n);
		for(int i=0;i<n;i++){
			cin>>a[i].first;
			a[i].second = i;
		}
		sort(all(a));
		int lo=0,hi=n-1,at = -1;
		while(lo <= hi){
			int md = (lo + hi)/2;
			ll s = a[md].first;
			bool good = true;
			for(int i=0;i<n;i++){
				if(i == md)continue;
				if(a[i].first > s)good = false;
				s += a[i].first;
			}
			if(good){
				hi = md-1;
				at = md;
			}else lo = md+1;
		}
		vector<int> ans;
		assert(at != -1);
		if(at != -1){
			for(int i=at;i<n;i++)ans.push_back(a[i].second + 1);
		}
		sort(all(ans));
		cout << ans.size() << '\n';
		for(int i : ans)
			cout << i << ' ';
		cout << '\n';
	}
}