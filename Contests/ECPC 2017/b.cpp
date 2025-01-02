#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int nax = 75000 + 2;

struct SegTree{
    typedef ll T;
    int n;
    vector<T> seg,lazy;
    const T oo = 0;

    SegTree(int _n){
        n = _n;
        seg = lazy = vector<T>(4*n);
    }

    T merge(T l, T r){
        return l + r;
    }

    void pro(int n,int s,int e){
        seg[n] += lazy[n] * (e - s + 1);
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
	string s,t;
	cin>>s>>t;

	vector<bitset<nax>> c(26);
	vector<vector<bitset<nax>>> nxt(26);
	for(int i=0;i<26;i++)nxt[i].resize(26);
	for(int i=0;i<t.size();i++){
		c[t[i] - 'a'][t.size() - 1 - i] = 1;
		if(i + 1 < t.size()){
			nxt[t[i] - 'a'][t[i+1] - 'a'][t.size() - 1 - i] = 1;
		}
	}

	int r=0;
	bitset<nax> cur = 0;

	vector<vector<vector<int>>> e(s.size());

	for(int l=0;l<s.size();l++){
		r = max(r , l);
		if(l == r){
			if(c[s[l] - 'a'].count() == 0)continue;
			cur = c[s[l] - 'a'];
		}

		while(r + 1 < s.size()){
			if((nxt[s[r] - 'a'][s[r+1] - 'a'] & cur).count() == 0)break;
			cur &= nxt[s[r] - 'a'][s[r+1] - 'a'];
			cur >>= 1;
			r++;
		}

		e[l].push_back({r});
	}

	nxt.clear();
	c.clear();

	int q;
	cin>>q;
	for(int i=0;i<q;i++){
		int l,r;
		cin>>l>>r;
		l--;r--;
		e[l].push_back({r , i});
	}

	vector<ll> ans(q);
	SegTree tree(s.size());
	for(int i=s.size() - 1;i>=0;i--){

		for(auto cur : e[i]){
			if(cur.size() == 1){
				tree.update(i+1, cur[0] + 1,1);
			}else{
				ans[cur[1]] = tree.get(i+1 , cur[0] + 1);
			}
		}

	}

	for(int i=0;i<q;i++)
		cout << ans[i] << '\n';

}

int main(){
	fast
	freopen("curse.in","r",stdin);
	int t;
	cin>>t;
	for(int T=1;T<=t;T++){
		cout << "Case " << T << ":\n";
		solve();
	}
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/