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

int To = 1;
struct segTree{
	vector<int> seg,lazy;
	int n;
	void init(int N){
		To = n = N;
		seg = lazy = vector<int>(4*N,0);
	}

	void pro(int n,int s,int e){
		seg[n] += lazy[n];
		if(s != e){
			lazy[n+n] += lazy[n];
			lazy[n+n+1] += lazy[n];
		}
		lazy[n] = 0;
	}

	void update(int l,int r,int val,int n = 1,int s=1,int e = To){
		if(l > To || r <= 0)return;
		if(l > r)return;
		pro(n,s,e);
		if(s > r || e < l)return;
		if(s >= l && e <= r){
			lazy[n] += val;
			pro(n,s,e);
			return;
		}
		update(l,r,val,n+n,s,(s+e)/2);
		update(l,r,val,n+n+1,(s+e)/2+1,e);
		seg[n] = min(seg[n+n] , seg[n+n+1]);
	}
};


void solve(){
	int n,m,k,q;
	cin>>n>>m>>k>>q;
	k--;
	To = n;
	vector<string> g(n);
	vector<BIT> pre(m);
	for(int i=0;i<m;i++){
		pre[i].init(n);
	}
	for(int i=0;i<n;i++){
		cin>>g[i];
		for(int j=0;j<m;j++){
			if(g[i][j] == 'X'){
				pre[j].update(i+1,1);
			}
		}
	}
	vector<vector<int>> carDown(m,vector<int>(n));
	vector<vector<int>> carUP(m,vector<int>(n));
	for(int j=0;j<m;j++){
		int cnt = 0;
		for(int i=0;i<k;i++){
			cnt += g[i][j] == 'X';
		}
		for(int t=0;t<n;t++){
			if(k + t >= n)break;
			cnt += g[k + t][j] == 'X';
			if(cnt > k){
				carUP[j][t] = 1;
				continue;
			}
			carUP[j][t] = g[k + t][j] == 'X';
		}
		for(int t=n-k;t<n;t++){
			if(cnt > k)
				carUP[j][t] = 1;
			else{
				carUP[j][t] = 0;
			}
		}
	}

	for(int j=0;j<m;j++){
		int cnt = 0;
		for(int i=n-1;i>k;i--){
			cnt += g[i][j] == 'X';
		}
		for(int t=0;t<n;t++){
			if(k - t < 0)break;
			cnt += g[k - t][j] == 'X';
			if(cnt > n-k-1){
				carDown[j][t] = 1;
				continue;
			}
			carDown[j][t] = g[k - t][j] == 'X';
		}
		for(int t=k+1;t<n;t++){
			if(cnt > n-k-1)
				carDown[j][t] = 1;
			else{
				carDown[j][t] = 0;
			}
		}
	}

	segTree up,down;
	up.init(n);
	down.init(n);
	for(int t=0;t<n;t++){
		ll tot = 0;
		for(int j=0;j<m;j++){
			tot += carUP[j][t];
		}
		ll tot2 = 0;
		for(int j=0;j<m;j++){
			tot2 += carDown[j][t];
		}
		// cerr << t << ' ' << tot << ' ' << tot2 << '\n';
		up.update(t+1,t+1,tot + t);
		down.update(t+1,t+1,tot2 + t);
	}

	ll ans = 0;
	while(q--){
		int r,c;
		cin>>r>>c;
		r--;c--;

		int cnt = pre[c].get(r + 1);

		if(g[r][c] == '.'){
			if(r < k){
				if(cnt < n-k)
					down.update(k - r,k - r,1);
			}else{
				if(cnt < k)
					up.update(r - k,r - k,1);
			}


			if(1){
				{
					int bef,aft;
					{
						int lo = 1,hi = n,at = n+1;
						while(lo <= hi){
							int md = (lo + hi)/2;
							int cnt = pre[c].get(md);
							if(cnt > k){
								at = md;
								hi = md-1;
							}else lo = md+1;
						}
						bef = at;
					}
					pre[c].update(r+1,1);
					{
						int lo = 1,hi = n,at = n;
						while(lo <= hi){
							int md = (lo + hi)/2;
							int cnt = pre[c].get(md);
							if(cnt > k){
								at = md;
								hi = md-1;
							}else lo = md+1;
						}
						aft = at;
					}
					aft -= k;
					bef -= k;
					
					// cerr << aft << ' ' << bef << '\n';
					// cerr << up.seg[1] << '\n';
					up.update(aft,bef-1,1);
					// cerr << up.seg[1] << '\n';
				}


				{
					int bef,aft;
					{
						int lo = 1,hi = n,at = n+1;
						while(lo <= hi){
							int md = (lo + hi)/2;
							int cnt = pre[c].get(md,n);
							if(cnt > n-1-k){
								at = md;
								lo = md+1;
							}else hi = md-1;
						}
						bef = at;
					}
					pre[c].update(r+1,1);
					{
						int lo = 1,hi = n,at = n+1;
						while(lo <= hi){
							int md = (lo + hi)/2;
							int cnt = pre[c].get(md,n);
							if(cnt > n-1-k){
								at = md;
								lo = md+1;
							}else hi = md-1;
						}
						aft = at;
					}
					bef = k-bef;
					aft = k-aft;

					// cerr << aft << ' ' << bef << '\n';
					// cerr << down.seg[1] << '\n';
					down.update(aft,bef-1,1);
					// cerr << down.seg[1] << '\n';
				}
			}

			g[r][c] = 'X';
		}else{
			if(r < k){
				if(cnt < n-k)
					down.update(k - r,k - r,-1);
			}else{
				if(cnt < k)
					up.update(r - k,r - k,-1);
			}


			if(1){
				{
					int bef,aft;
					{
						int lo = 1,hi = n,at = n+1;
						while(lo <= hi){
							int md = (lo + hi)/2;
							int cnt = pre[c].get(md);
							if(cnt > k){
								at = md;
								hi = md-1;
							}else lo = md+1;
						}
						bef = at;
					}
					pre[c].update(r+1,-1);
					{
						int lo = 1,hi = n,at = n+1;
						while(lo <= hi){
							int md = (lo + hi)/2;
							int cnt = pre[c].get(md);
							if(cnt > k){
								at = md;
								hi = md-1;
							}else lo = md+1;
						}
						aft = at;
					}
					aft -= k;
					bef -= k;
					up.update(bef+1,aft,-1);
				}


				{
					int bef,aft;
					{
						int lo = 1,hi = n,at = n+1;
						while(lo <= hi){
							int md = (lo + hi)/2;
							int cnt = pre[c].get(md,n);
							if(cnt > n-1-k){
								at = md;
								lo = md+1;
							}else hi = md-1;
						}
						bef = at;
					}
					pre[c].update(r+1,-1);
					{
						int lo = 1,hi = n,at = n+1;
						while(lo <= hi){
							int md = (lo + hi)/2;
							int cnt = pre[c].get(md,n);
							if(cnt > n-1-k){
								at = md;
								lo = md+1;
							}else hi = md-1;
						}
						aft = at;
					}
					bef = k-bef;
					aft = k-aft;

					// cerr << bef << ' ' << aft << '\n';
					down.update(bef+1,aft,-1);

				}
			}

			g[r][c] = '.';
		}

		ans += min(up.seg[1],down.seg[1]);
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