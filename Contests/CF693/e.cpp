#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int nax = 4e5 + 10;
pair<int,int> seg[4*nax];
int n,to;

void update(int at,pair<int,int> val,int n = 1,int s = 1,int e = ::to){
	if(s > at || e < at)return;
	if(s == e){
		if(val.first == 1e9 && val.second == 1e9)seg[n] = val;
		else seg[n] = min(seg[n] , val);
		return;
	}
	update(at,val,n+n,s,(s+e)/2);
	update(at,val,n+n+1,(s+e)/2+1,e);
	seg[n] = min(seg[n+n] , seg[n+n+1]);
}

pair<int,int> get(int l,int r,int n = 1,int s = 1,int e = ::to){
	if(s > r || e < l || l > r)return {1e9,1e9};
	if(s >= l && e <= r)return seg[n];
	return min(get(l,r,n+n,s,(s+e)/2) , get(l,r,n+n+1,(s+e)/2+1,e));
}

void solve(){
	cin>>n;
	vector<pair<int,int>> p(n);
	vector<int> g;
	for(int i=0;i<n;i++){
		cin>>p[i].first>>p[i].second;
		g.push_back(p[i].first);
		g.push_back(p[i].second);
	}
	sort(all(g));
	g.resize(unique(all(g)) - g.begin());
	to = g.size();
	for(int i=1;i<=g.size();i++){
		update(i,{1e9,1e9});
	}
	for(int i=0;i<n;i++){
		p[i].first = lower_bound(all(g),p[i].first) - g.begin();
		p[i].second = lower_bound(all(g),p[i].second) - g.begin();
		// cerr << p[i].first << ' ' << p[i].second << '\n';
		update(p[i].first + 1,{p[i].second , i + 1});
	}
	vector<int> ans(n,-1);
	for(int i=0;i<n;i++){
		pair<int,int> v = get(1,p[i].first);
		// cerr << v.first << ' ' << p[i].second << '\n';
		if(v.first < p[i].second)ans[i] = v.second;
	}
	for(int i=1;i<=g.size();i++){
		update(i,{1e9,1e9});
	}
	for(int i=0;i<n;i++){
		// cerr << p[i].first << ' ' << p[i].second << '\n';
		update(p[i].first + 1,{p[i].second , i + 1});
		swap(p[i].first,p[i].second);
	}
	for(int i=0;i<n;i++){
		pair<int,int> v = get(1,p[i].first);
		// cerr << v.first << ' ' << p[i].second << '\n';
		if(v.first < p[i].second)ans[i] = v.second;
	}
	for(int i=0;i<n;i++)
		cout << ans[i] << ' ';
	cout << '\n';
}

int main(){
	fast
	int t;
	cin>>t;
	while(t--)solve();
}