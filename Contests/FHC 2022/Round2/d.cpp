#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct SegTree{
    typedef vector<ll> T;
    int n;
    vector<T> seg;
    const T oo = {0,0,0};

    SegTree(int _n){
        n = _n;
        seg = vector<T>(4*n,T(3,0));
    }

    T merge(T l, T r){
    	T res = T(3,0);
    	for(int i=0;i<3;i++)res[i] = l[i] + r[i];
        return res;
    }

    void update(int l,int r,int val,int n,int s,int e){
        if(s > r || e < l || l > r)return;
        if(s >= l && e <= r){
            seg[n] = T(3,0);
            seg[n][val] = 1;
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
	
	SegTree tree(n);
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		tree.update(i+1,a-1);
	}
	
	ll ans = 0;
	for(int i=0;i<m;i++){
		int x,y,z;
		cin>>x>>y>>z;	
		tree.update(x , y-1);

		vector<ll> left = tree.get(1,z);
		vector<ll> right = tree.get(z+1,n);
		if(right.size() == 0)right = vector<ll>(3,0);
		if(left.size() == 0)left = vector<ll>(3,0);
		assert(left.size() == 3);
		assert(right.size() == 3);

		ll s1 = left[0] + left[1] + left[1] + left[2] * 3;
		ll s2 = right[0] + right[1] + right[1] + right[2] * 3;

		if(abs(s1 - s2) % 2 == 1){
			ans += -1;
			continue;
		}

		if(s1 < s2){
			swap(s1,s2);
			swap(left,right);
		}

		ll cur = 0;
		ll dif = s1 - s2;
		assert(dif >= 0);
		ll swap31 = min({left[2] , right[0] , dif/4});
		dif -= swap31 * 4;
		left[2] -= swap31;
		left[0] += swap31;
		right[0] -= swap31;
		right[2] += swap31;
		cur += swap31;

		ll swap32 = min({left[2] , right[1] , dif/2});
		dif -= swap32 * 2;
		left[2] -= swap32;
		left[1] += swap32;
		right[1] -= swap32;
		right[2] += swap32;
		cur += swap32;

		ll swap21 = min({left[1] , right[0] , dif/2});
		dif -= swap21 * 2;
		left[1] -= swap21;
		left[0] += swap21;
		right[0] -= swap21;
		right[1] += swap21;
		cur += swap21;


		if(dif == 0)ans += cur;
		else ans--;
	}
	tree.seg.clear();
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