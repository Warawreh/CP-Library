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
    vector<T> seg;
    const T oo = 0;

    SegTree(int _n){
        n = _n;
        seg = vector<T>(4*n);
    }

    T merge(T l, T r){
    	return l+r;
    }

    void update(int l,int r,int val,int n,int s,int e){
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

    void update(int at,int val){
        update(at,at,val,1,1,n);
    }

    T get(int l,int r){
        return get(l,r,1,1,n);
    }

};

void solve(){
	int n,m;
	cin>>n>>m;
	
	SegTree s1(n),s2(n),p1(n),p2(n);
	vector<int> b(n);
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		b[i] = a;
		if(a == 1){
			s1.update(i+1 , 1);
			p1.update(i+1 , i);
		}else{
			s2.update(i+1 , 1);
			p2.update(i+1 , i);
		}
	}
	
	ll ans = 0;
	for(int i=0;i<m;i++){
		int x,y,z;
		cin>>x>>y>>z;	
		
		x--;
		if(b[x] == 1){
			s1.update(x+1,0);
			p1.update(x+1,0);
		}else{
			s2.update(x+1,0);
			p2.update(x+1,0);
		}
		b[x] = y;
		if(b[x] == 1){
			s1.update(x+1,1);
			p1.update(x+1,x);
		}else{
			s2.update(x+1,1);
			p2.update(x+1,x);
		}


		ll left = s1.get(1,z) + 2 * s2.get(1,z);
		ll right = s1.get(z+1,n) + 2 * s2.get(z+1,n);

		ll dif = abs(left - right);
		if(dif % 2 == 1){
			ans += -1;
			continue;
		}
		ll need = dif / 2;


		ll cur = 0;
		if(left > right){
			int mn = min(s2.get(1,z) , s1.get(z+1,n));
			if(mn < need){
				ans--;
				continue;
			}

			{
				int lo = 1,hi = z , to = z;
				while(lo <= hi){
					int md = (lo + hi)/2;

					if(s2.get(md , z) >= need){
						to = md;
						lo = md+1;
					}else hi = md-1;
				}

				cur += (z - 1) * need - p2.get(to , z);
			}

			{
				int lo = z+1,hi = n , to = n;
				while(lo <= hi){
					int md = (lo + hi)/2;

					if(s1.get(z+1 , md) >= need){
						to = md;
						hi = md-1;
					}else lo = md+1;
				}

				cur += p1.get(z+1 , to) - z * need;
			}


		}else if(right > left){

			int mn = min(s1.get(1,z) , s2.get(z+1,n));
			if(mn < need){
				ans--;
				continue;
			}

			{
				int lo = 1,hi = z , to = z;
				while(lo <= hi){
					int md = (lo + hi)/2;

					if(s1.get(md , z) >= need){
						to = md;
						lo = md+1;
					}else hi = md-1;
				}

				cur += (z - 1) * need - p1.get(to , z);
			}

			{
				int lo = z+1,hi = n , to = n;
				while(lo <= hi){
					int md = (lo + hi)/2;

					if(s2.get(z+1 , md) >= need){
						to = md;
						hi = md-1;
					}else lo = md+1;
				}

				cur += p2.get(z +1, to) - z * need;
			}

		}


		ans += cur + need;
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