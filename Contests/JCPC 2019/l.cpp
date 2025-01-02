#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll solve(int k,vector<vector<pair<int,int>>> cost, vector<ll> &pre){
	vector<bool> skip(pre.size());

	vector<vector<int>> f(pre.size() + 1);
	for(int i=0;i<cost.size();i++){
		f[cost[i].size()].push_back(i);
	}

	int hv = 0;

	ll ans = 1e18;
	ll moved = 0,rem = 0;
	int at = pre.size()-1,total = pre.size()-1;

	if(k < cost.size()){
		hv = cost[k].size();

		for(auto &[c,i] : cost[k]){
			rem += c;
			skip[i] = 1;
			total--;
		}
	}

	for(int i=pre.size();i>0;i--){
		while(f[i].size()){
			int cur = f[i].back();
			pair<int,int> a = cost[cur].back();
			if(cur != k){
				// cerr << cur << ' ' << a.first << '\n';

				if(a.second <= at){
					total--;
					rem += a.first;
				}

				hv++;
				cost[cur].pop_back();
				moved += a.first;
				skip[a.second] = 1;
				f[i - 1].push_back(cur);
			}

			f[i].pop_back();
		}

		int need = max(0 , i - hv);
		while(total + 1 > need){

			if(skip[at] == 1){
				rem -= (pre[at] - (at ? pre[at - 1] : 0LL));
				at--;
				continue;
			}
			total--;
			at--;
		}
		ans = min(ans , moved + (at >= 0 ? pre[at] : 0LL) - rem);
		if(hv >= i)break;
	}
	f.clear();

	return ans;
}

int main(){
	fast
	int n,q;
	cin>>n>>q;
	vector<int> a(n);
	vector<pair<int,int>> c(n);
	vector<ll> pre(n);
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++){
		cin>>c[i].first;
		c[i].second = i;
	}

	vector<int> renum = a;
	sort(all(renum));
	renum.resize(unique(all(renum)) - renum.begin());

	auto getNewId = [&](int i){
		return lower_bound(all(renum) , i) - renum.begin();
	};

	for(int i=0;i<n;i++)a[i] = getNewId(a[i]);

	vector<vector<pair<int,int>>> cost(renum.size());
	sort(all(c));

	for(int i=0;i<n;i++){
		pre[i] = c[i].first + (i ? pre[i-1] : 0LL);
		cost[a[c[i].second]].push_back({c[i].first , i});
	}

	for(int i=0;i<renum.size();i++){
		sort(all(cost[i]));
		reverse(all(cost[i]));
	}

	while(q--){
		int k;
		cin>>k;
		int at = getNewId(k);
		if(at == renum.size() || renum[at] != k)k = renum.size();
		else k = at;

		cout << solve(k , cost , pre) << ' ';
	}

}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/