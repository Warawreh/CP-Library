#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


const int nax = 1e6 + 2;
ll phi[nax];

void calcPhi(ll n) {
    for (ll i = 0; i <= n; i++)
        phi[i] = i;

    for (ll i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (ll j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}

struct SegTree{
    typedef ll T;
    int n;
    vector<T> lazy,tms;
    vector<vector<ll>> seg;
    const T oo = 0;

    SegTree(int _n){
        n = _n;
        lazy = tms = vector<T>(4*n,0);
        seg = vector<vector<ll>>(4*n , vector<ll>(22));
    }

    vector<ll> merge(vector<ll> l, vector<ll> r){
    	vector<ll> res(22);
    	for(int i=0;i<22;i++)
    		res[i] = l[i] + r[i];
        return res;
    }

    void build(int n,int s,int e,vector<int> &a){
        if(s == e){
            seg[n][0] = a[s-1];
            for(int i=1;i<22;i++){
            	seg[n][i] = phi[seg[n][i-1]];
            }
            return;
        }
        build(n+n, s, (s+e)/2,a);
        build(n+n+1, (s+e)/2+1, e,a);
        seg[n] = merge(seg[n+n] , seg[n+n+1]);

    }

    void pro(int n,int s,int e){
    	if(lazy[n] != 0){
    		tms[n] = 0;
    		ll cur = lazy[n];
    		for(int i=0;i<22;i++){
    			seg[n][i] = cur * (e - s + 1);
    			cur = phi[cur];
    		}

    		if(s != e){
	            lazy[n+n] = lazy[n];
	            lazy[n+n+1] = lazy[n];
	        }
	        lazy[n] = 0;
    	}

    	if(tms[n] != 0){

    		for(int i=0;i<22;i++){
    			if(i + tms[n] < 22)seg[n][i] = seg[n][i+tms[n]];
    			else seg[n][i] = (e - s + 1);
    		}

    		if(s != e){
    			if(lazy[n+n]){
    				for(int i=0;i<tms[n];i++)lazy[n+n] = phi[lazy[n+n]];
    			}else tms[n+n] += tms[n];

    			if(lazy[n+n+1]){
    				for(int i=0;i<tms[n];i++)lazy[n+n+1] = phi[lazy[n+n+1]];
    			}else tms[n+n+1] += tms[n];
    		}

    		tms[n] = 0;
    	}
        

    }

    void update(int l,int r,T val,int n,int s,int e){
        pro(n,s,e);
        if(s > r || e < l || l > r)return;
        if(s >= l && e <= r){
        	if(val == -1)tms[n]++;
        	else lazy[n] = val;
        	pro(n,s,e);
            return;
        }

        update(l,r,val,n+n,s,(s+e)/2);
        update(l,r,val,n+n+1,(s+e)/2+1,e);

        seg[n] = merge(seg[n+n] , seg[n+n+1]);
    }

    ll get(int l,int r,int n,int s,int e){
        pro(n,s,e);
        if(s > r || e < l || l > r)return 0;
        if(s >= l && e <= r){
            return seg[n][0];
        }
        return get(l,r,n+n,s,(s+e)/2) + get(l,r,n+n+1,(s+e)/2+1,e);
    }

    void update(int l,int r,T val){
        update(l,r,val,1,1,n);
    }

    void update(int at,T val){
        update(at,at,val,1,1,n);
    }

    void build(vector<int> &a){
        build(1,1,n,a);
    }

    T get(int l,int r){
        return get(l,r,1,1,n);
    }

};

int main(){
    fast
   	calcPhi(1e6 + 1);

   	int n,q;
   	cin>>n>>q;
   	vector<int> a(n);
   	for(int i=0;i<n;i++)cin>>a[i];
   	SegTree tree(n);
	tree.build(a);

   	while(q--){
   		int t;
   		cin>>t;
   		if(t == 1){//tms++
   			int l,r;
   			cin>>l>>r;
   			tree.update(l,r,-1);
   		}else if(t == 2){
   			int l , r ,x;
   			cin>>l>>r>>x;
   			tree.update(l,r,x);
   		}else if(t == 3){
   			int l,r;
   			cin>>l>>r;
   			cout << tree.get(l,r) << '\n';
   		}
   	}
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/