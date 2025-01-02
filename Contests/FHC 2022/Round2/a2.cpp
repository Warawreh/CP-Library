#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int nax = 1e6 + 10;
ll to[nax];
map<ll,int> rev;
map<ll,bool> used;

struct SegTree{
    typedef ll T;
    int n;
    vector<T> seg;
    const T oo = 0;

    SegTree(int _n){
        n = _n;
        seg = vector<T>(4*n);
    }

    T merge(T l, T r){
        return l + r;
    }

    void update(int l,int r,T val,int n,int s,int e){
        if(s > r || e < l || l > r)return;
        if(s >= l && e <= r){
            seg[n] = val;
            return;
        }

        update(l,r,val,n+n,s,(s+e)/2);
        update(l,r,val,n+n+1,(s+e)/2+1,e);

        seg[n] = merge(seg[n+n] , seg[n+n+1]);
    }

    T get(int l,int r,int n,int s,int e){
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
	int n;
	cin>>n;

	vector<ll> a(n);
	vector<set<int>> hv(nax);
	SegTree tree(n+1);

	for(int i=0;i<n;i++){
		cin>>a[i];
		hv[a[i]].insert(i);
		tree.update(i+1 , to[a[i]]);
	}

	ll q;
	cin>>q;
	ll ans = 0;
	while(q--){
		int t;
		cin>>t;

		if(t == 1){//update

			int id,y;
			cin>>id>>y;
			id--;
			hv[a[id]].erase(id);
			a[id] = y;
			tree.update(id+1,to[a[id]]);
			hv[a[id]].insert(id);

		}else{//query

			ll l,r;
			cin>>l>>r;
			if((r - l + 1) % 2 == 0)continue;
			if(l == r){
				ans++;
				continue;
			}
			l--;r--;

			bool can = false;
			{//left is bigger
				ll md = (l + r)/2;

				ll left = tree.get(l+1,md+1);
				ll right = tree.get(md+2,r+1);
				
				if(left != right){
					if(right <= left){
						ll need = rev[left - right];
						if(need){
							auto it = hv[need].lower_bound(l);
							if(it != hv[need].end()){
								if(*it <= md){
									can = true;
								}
							}
						}
					}
				}
			}
			{//right is bigger
				ll md = (l + r)/2 - 1;

				ll left = tree.get(l+1,md+1);
				ll right = tree.get(md+2,r+1);
				if(left != right){
					if(right >= left){
						ll need = rev[right - left];
						if(need){
							auto it = hv[need].lower_bound(md+1);
							if(it != hv[need].end()){
								if(*it <= r){
									can = true;
								}
							}
						}
					}
				}
			}

			ans += can;


		}
		
	}
	hv.clear();
	cout << ans << '\n';
}

int main(){
	fast

	for(int i=0;i<nax;i++){
		ll chose = uniform_int_distribution<ll>(1, 1e12)(rng);
		while(used[chose]){
			chose = uniform_int_distribution<ll>(1, 1e12)(rng);
		}
		used[chose] = 1;
		to[i] = chose;
		rev[to[i]] = i;
	}

	int t;
	cin>>t;
	for(int T=1;T<=t;T++){
		cout << "Case #" << T << ": ";
		solve();
	}
}	