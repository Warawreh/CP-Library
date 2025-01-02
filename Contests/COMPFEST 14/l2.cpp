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
		return get(r) - get(l-1);
	}
};


int main(){
	fast
	int n;
	cin>>n;
	vector<ll> a(n);
	vector<int> st(n);
	iota(all(st) , 0);

	vector<ll> pre(n),suf(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
		pre[i] = a[i] + (i ? pre[i-1] : 0LL);
		if(pre[i] < 0){
			cout << -1 << '\n';
			return 0;
		}
	}

	for(int i=n-1;i>=0;i--){
		suf[i] = (i + 1 < n ? suf[i + 1] : 0LL) + a[i];
		if(suf[i] < 0){
			cout << -1 << '\n';
			return 0;
		}
	}


	if(a[0] < 0 || a[n-1] < 0){
		cout << -1 << '\n';
		return 0;
	}

	for(int i=1;i<n-1;i++){
		if(a[i] < 0 && -a[i] > pre[i-1] && -a[i] > suf[i+1]){
			cout << -1 << '\n';
			return 0;
		}
	}

	sort(all(st) , [&] (int a,int b){
		if(pre[a] == pre[b])return a < b;
		return pre[a] < pre[b];
	});

	BIT tree;
	tree.init(n);
	ll ans = 0;
	for(int i=0;i<st.size();i++){
		ll cur = tree.get(st[i] + 1);
		// cerr << cur << ' ' << st[i] << '\n';
		ans += st[i] - cur;
		tree.update(st[i] + 1, 1);
	}


	cout << ans << '\n';
}	

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/