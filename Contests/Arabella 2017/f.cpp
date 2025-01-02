#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct SegTree{
    typedef ll T;
    int n;
    vector<T> seg,lazy;
    const T oo = 1e9;

    SegTree(int _n){
        n = _n;
        seg = lazy = vector<T>(4*n);
    }

    T merge(T l, T r){
        return min(l,r);
    }

    void pro(int n,int s,int e){
    	if(lazy[n] == 0)return;
        seg[n] = lazy[n];
        if(s != e){
            lazy[n+n] = lazy[n];
            lazy[n+n+1] = lazy[n];
        }
        lazy[n] = 0;

    }

    void update(int l,int r,T val,int n,int s,int e){
        pro(n,s,e);
        if(s > r || e < l || l > r)return;
        if(s >= l && e <= r){
            lazy[n] = val;
            pro(n,s,e);
            return;
        }

        update(l,r,val,n+n,s,(s+e)/2);
        update(l,r,val,n+n+1,(s+e)/2+1,e);

        seg[n] = merge(seg[n+n] , seg[n+n+1]);
    }

    T get(int l,int r,int n,int s,int e){
        pro(n,s,e);
        if(s > r || e < l || l > r)return oo;
        if(s >= l && e <= r){
            return seg[n];
        }
        return merge(get(l,r,n+n,s,(s+e)/2) , get(l,r,n+n+1,(s+e)/2+1,e));
    }

    void update(int l,int r,T val){
        update(l,r,val,1,1,n);
    }

    void update(int at,T val){
        update(at,at,val,1,1,n);
    }

    T get(int l,int r){
        return get(l,r,1,1,n);
    }

};

struct SegTreeAdd{
    typedef ll T;
    int n;
    vector<T> seg,lazy;
    const T oo = 1e9;

    SegTreeAdd(int _n){
        n = _n;
        seg = lazy = vector<T>(4*n);
    }

    T merge(T l, T r){
        return min(l,r);
    }

    void pro(int n,int s,int e){
        seg[n] += lazy[n] * 1LL * (e - s + 1);
        if(s != e){
            lazy[n+n] += lazy[n];
            lazy[n+n+1] += lazy[n];
        }
        lazy[n] = 0;

    }

    void update(int l,int r,T val,int n,int s,int e){
        pro(n,s,e);
        if(s > r || e < l || l > r)return;
        if(s >= l && e <= r){
            lazy[n] += val;
            pro(n,s,e);
            return;
        }

        update(l,r,val,n+n,s,(s+e)/2);
        update(l,r,val,n+n+1,(s+e)/2+1,e);

        seg[n] = merge(seg[n+n] , seg[n+n+1]);
    }

    T get(int l,int r,int n,int s,int e){
        pro(n,s,e);
        if(s > r || e < l || l > r)return oo;
        if(s >= l && e <= r){
            return seg[n];
        }
        return merge(get(l,r,n+n,s,(s+e)/2) , get(l,r,n+n+1,(s+e)/2+1,e));
    }

    void update(int l,int r,T val){
        update(l,r,val,1,1,n);
    }

    void update(int at,T val){
        update(at,at,val,1,1,n);
    }

    T get(int l,int r){
        return get(l,r,1,1,n);
    }

};

void solve(){
	int n,m;
	cin>>n>>m;

	vector<vector<int>> q(m);
	map<int,int> f;
	int cnt = 0;
	for(int i=0;i<m;i++){
		q[i].resize(3);
		for(int j=0;j<3;j++)cin>>q[i][j];
		if(f[q[i][1]] == 0)f[q[i][1]] = ++cnt;
		q[i][1] = f[q[i][1]];
	}

	vector<vector<pair<int,int>>> range(cnt + 1);
	vector<vector<int>> idx(cnt + 1);

	SegTree setIt(n);
	for(int i=0;i<m;i++){
		int l = max(1 , q[i][0] - q[i][2]);
		int r = min(n , q[i][0] + q[i][2]);
		range[q[i][1]].push_back({l,r});

		// cerr << l << ' ' << r << ' ' << q[i][1] << '\n';
		setIt.update(l , r , q[i][1]);

	}

	int ans = 0;
	for(int i=1;i<=n;i++){
		int val = setIt.get(i,i);
		if(val == 0)ans++;
		else{
			idx[val].push_back(i);
		}
	}

	SegTreeAdd tree(n);
	for(int i=1;i<=cnt;i++){

		for(pair<int,int> r : range[i]){
			tree.update(r.first , r.second , 1);
		}

		for(int x : idx[i]){
			if(tree.get(x,x) >= 2)ans++;
		}

		for(pair<int,int> r : range[i]){
			tree.update(r.first , r.second , -1);
		}

	}
	cout << ans << '\n';
}

int main(){
	fast
	int t;
	cin>>t;
	while(t--)solve();
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/