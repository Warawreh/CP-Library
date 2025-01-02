#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct node{
	vector<ll> hv;
	ll ans;

	node(){
		hv = vector<ll>(4,0);
		// hv[0] = 1;
		ans = 0;
	}
}

struct SegTree{
    typedef node T;
    int n;
    vector<T> seg;

    SegTree(int _n){
        n = _n;
        seg = vector<T>(4*n);
    }

    T merge(T l, T r){

    	T res = node();
    	res.ans = l.ans + r.ans;

    	for(int i=0;i<4;i++){
    		for(int j=0;j<4;j++){
    			if((i - j + 4)%4 == 2 || (i - j + 4)%4 == 3)res.ans += r.hv[i] * l.hv[j];
    		}
    	}

    	for(int i=0;i<n;i++){
    		res.hv[i] = l.hv[i] + l.hv[r];
    	}

        return l + r;
    }

    void update(int l,int r,T val,int n,int s,int e){
        if(s > r || e < l || l > r)return;
        if(s >= l && e <= r){
            seg.hv[val % 4]++;
            if(val%4 == 2 || val%4 == 3)seg.ans++;
            return;
        }

        update(l,r,val,n+n,s,(s+e)/2);
        update(l,r,val,n+n+1,(s+e)/2+1,e);

        seg[n] = merge(seg[n+n] , seg[n+n+1]);
    }

    T get(int l,int r,int n,int s,int e){
        if(s > r || e < l || l > r)return node();
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
	int n,q;
	cin>>n>>q;
	vector<int> a;
	for(int i=0;i<n;i++){

	}
}

int main(){
	fast
	freopen("bad.in","r",stdin);	
	int t;
	cin>>t;
	while(t--)solve();
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/