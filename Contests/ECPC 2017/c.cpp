#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int SHIFT = 1e5;
const int nax = SHIFT + 1;

struct parabola{
	ll a,b,c,id;
	parabola(){id = -1;a = b = c = -1e6;}
	void read(){
		cin>>a>>b>>c;
	}
	ll getHead(){
		return (-b / (2*a));
	}

	ll val(ll x){
		x -= nax;
		return a * x * x + b * x + c;
	}
};

struct SegTree{
    typedef parabola T;
    int n;
    vector<pair<T,T>> seg;

    SegTree(int _n){
        n = _n;
        seg = vector<pair<T,T>>(4*n);
    }

    bool check(ll a,ll b){return (a>=b?1:0);}
    void update(int l,int r,T val,int n,int s,int e){
        if(s > r || e < l || l > r)return;


        if(l <= s && e <= r){
        	bool mid,left,right;
			if(val.a == 0){
				if(seg[n].second.id == -1)seg[n].second = val;

	    		int md = (s + e)/2;

				mid = check(val.val(md) , seg[n].second.val(md));
				left = check(val.val(s) , seg[n].second.val(s));
				if(mid)swap(seg[n].second , val);

				if(s == e)return;
				else if(left != mid)update(l,r,val,n+n,s,(s+e)/2);
				else update(l,r,val,n+n+1,(s+e)/2+1,e);
			}else{
				if(seg[n].first.id == -1)seg[n].first = val;

	    		int md = (s + e)/2;

				mid = check(val.val(md) , seg[n].first.val(md));
				left = check(val.val(s) , seg[n].first.val(s));
				right = check(val.val(e) , seg[n].first.val(e));
				if(mid)swap(seg[n].first , val);

				if(s == e)return;
				else if(left != mid && left != right)update(l,r,val,n+n,s,(s+e)/2);
				else update(l,r,val,n+n+1,(s+e)/2+1,e);
			}

    		

        }else{
	        if(s == e)return;
	        update(l,r,val,n+n,s,(s+e)/2);
	        update(l,r,val,n+n+1,(s+e)/2+1,e);
        }

    }

    pair<ll,ll> get(int at,int n,int s,int e){
        if(s > at || e < at)return {(ll)-1e18,0LL};
        if(s == e){
        	pair<ll,ll> res = max(make_pair(seg[n].first.val(at) , seg[n].first.id) , make_pair(seg[n].second.val(at) , seg[n].second.id) );
		    if(res.second == -1)res.first = -1e18;
        	return res;
        }
        pair<ll,ll> res = max(make_pair(seg[n].first.val(at) , seg[n].first.id) , make_pair(seg[n].second.val(at) , seg[n].second.id) );
        if(res.second == -1)res.first = -1e18;
        return max({res, get(at,n+n,s,(s+e)/2) , get(at,n+n+1,(s+e)/2+1,e)});
    }

    void update(int l,int r,T val){
        update(l + nax,r + nax,val,1,1,n);
    }


    pair<ll,ll> get(int at){
        return get(at + nax,1,1,n);
    }

};

void solve(){
	int n;
	cin>>n;

	SegTree tree(SHIFT + SHIFT + 2);
	ll constant = -1e18,atC = -1;
	for(int i=0;i<n;i++){
		parabola cur;
		cur.id = i;
		cur.read();
		if(cur.a == 0){
			if(cur.b == 0){
				if(cur.c > constant){
					constant = cur.c;
					atC = i;
				}
			}else{
				tree.update(-SHIFT,SHIFT,cur);
			}
		}else{
			int md = cur.getHead();
			tree.update(-SHIFT,md,cur);
			tree.update(md + 1, SHIFT , cur);
		}

	}

	int q;
	cin>>q;
	while(q--){
		int at;
		cin>>at;
		pair<ll,ll> res = tree.get(at);
		if(constant > res.first){
			res = {constant , atC};
		}
		cout << res.second << ' ' << res.first << '\n';
	}
}

int main(){
	fast
	freopen("parabolas.in","r",stdin);
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