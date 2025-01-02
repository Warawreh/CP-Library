#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct BIT{
	vector<ll> tree;
	int n;
	void init(int N){
		n = N;
		tree = vector<ll> (n+1,0);
	}
	void update(int x,ll val){
		while(x <= n){
			tree[x]+=val;
			x += x&(-x);
		}
	}
	ll get(int x){
		ll res = 0;
		while(x){
			res += tree[x];
			x -= x&(-x);
		}
		return res;
	}
	ll get(int l,int r){
		if(l > r)return 0;
		return get(r) - get(l-1);
	}
};

BIT tree;

void solve(){
	int n;
	cin>>n;

	vector<int> a;
	vector<pair<int,int>> s(n);
	for(int i=0;i<n;i++){
		cin>>s[i].first>>s[i].second;
		a.push_back(s[i].first);
		a.push_back(s[i].second);
	}
	sort(all(a));
	a.resize(unique(all(a)) - a.begin());
	vector<vector<int>> at(3*n);
	for(int i=0;i<n;i++){
		s[i].first = lower_bound(all(a) , s[i].first) - a.begin();
		s[i].second = lower_bound(all(a) , s[i].second) - a.begin();
		s[i].first++;
		s[i].second++;
		at[s[i].first].push_back(s[i].second);
		tree.update(s[i].first, 1);
	}
	ll ans = 0;
	for(int i=1;i<3*n;i++){
		for(int to : at[i]){
			ans = max(ans , tree.get(i , to));
			tree.update(i , -1);
			tree.update(to , 1);
		}
	}
	for(int i=0;i<n;i++)tree.update(s[i].second , -1);

	cout << n - ans << '\n';
}

int main(){
	fast
	int t;
	cin>>t;
	tree.init(1e6 + 10);
	while(t--)solve();
}