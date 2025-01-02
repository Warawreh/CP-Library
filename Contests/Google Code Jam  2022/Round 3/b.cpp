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
    const T oo = 0;

    SegTree(int _n){
        n = _n;
        seg = lazy = vector<T>(4*n);
    }

    T merge(T l, T r){
        return l + r;
    }

    void update(int l,int r,T val,int n,int s,int e){
        // pro(n,s,e);
        if(s > r || e < l || l > r)return;
        if(s >= l && e <= r){
            lazy[n] += val;
            if(lazy[n])seg[n] = (e - s + 1);
            else{
            	if(s == e)
            		seg[n] = 0;
            	else seg[n] = seg[n+n] + seg[n+n+1];
            }
            return;
        }

        update(l,r,val,n+n,s,(s+e)/2);
        update(l,r,val,n+n+1,(s+e)/2+1,e);

        seg[n] = seg[n+n] + seg[n+n+1];
        if(lazy[n])seg[n] = (e - s + 1);
    }

    T get(int l,int r,int n,int s,int e,int val){
        if(s > r || e < l || l > r)return 0;

        if(lazy[n]){
        	val = 1;
        }

        if(s >= l && e <= r){
        	if(val)return (e - s + 1);
        	else return seg[n];
        }
        T a = get(l,r,n+n,s,(s+e)/2,val);
        T b = get(l,r,n+n+1,(s+e)/2+1,e,val);
        T res = a + b;

        return res;
    }

    void update(int l,int r,T val){
        update(l,r,val,1,1,n);
    }

    void update(int at,T val){
        update(at,at,val,1,1,n);
    }

    T get(int l,int r){
        return get(l,r,1,1,n,0);
    }

};

int T;

void solve(){
	int n,c;
	cin>>n>>c;
	vector<pair<int,int>> r(c);
	vector<int> p(n);
	for(int i=0;i<c;i++){
		cin>>r[i].first>>r[i].second;
	}
	for(int i=0;i<n;i++){
		cin>>p[i];
		p[i]--;
		p.push_back(p[i]);
	}

	vector<vector<int>> at(c);
	for(int i=0;i<n+n;i++)at[p[i]].push_back(i);

	ll ans = 0;
	int l = 0;
	int good = c;
	vector<int> hv(c,0);
	vector<int> atC(c,0);
	SegTree tree(n+n);

	for(int i=0;i<n + n;i++){

		int color = p[i];
		int need = r[color].first - 1;
		if(need > 0){
			if(atC[color] > 0){	
				int cur = atC[color] - 1;
				// if(i == 9)cerr << cur << ' ' << need << '\n';
				if(cur < need){
					tree.update(1,at[color][cur] + 1, -1);
				}else{
					tree.update(at[color][cur - need] + 2,at[color][cur] + 1,-1);
				}
			}

			int cur = atC[color];
			assert(at[color][cur] == i);
			if(cur < need){
				tree.update(1,at[color][cur] + 1 , 1);
			}else{
				tree.update(at[color][cur - need] + 2,at[color][cur] + 1,1);
			}
			int mx = r[color].second;
			if(cur >= mx){
				tree.update(1,at[color][cur - mx]  + 1, 1);
			}
		}

		atC[color]++;
		hv[color]++;

		while(l <= i && (hv[color] > r[color].second || i - l + 1 >= n)){
			hv[p[l]]--;
			l++;
		}
		// cerr << i << ": ";
		// for(int x=1;x<=n+n;x++)
		// 	cerr << tree.get(x,x);
		// cerr << '\n';
		// if(l >= n)break;
		if(i >= n){
			tree.update(i+1,1);
			// cerr << l << ' ' << i << ' ' << tree.get(l+1,i+1) << ' ' << (i - l + 1) - tree.get(l+1,i+1) << '\n';
			// for(int x=l+1;x<=i+1;x++)
			// 	cerr << tree.get(x,x);
			// cerr << '\n';

			// assert(((i - l + 1) - tree.get(l+1,i+1)) >= 0);
			ans += (i - l + 1) - tree.get(l+1,i+1);
			tree.update(i+1,-1);
		}
	}

	cout << ans << '\n';


}

int main(){
	fast
	int t;
	cin>>t;

	for(T=1;T<=t;T++){
		cout << "Case #" << T << ": ";
		solve();
	}
}

/*
3 3 4 5 3 1 4 2 3 2 3 3 4 5 3 1 4 2 3 2 
0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
*/