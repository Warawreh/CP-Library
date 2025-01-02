#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ld PI = acos(-1);
struct p2d{
	ll x , y ;
	p2d operator-( p2d p ){ return { x - p.x , y - p.y }; }
};
int main(){
    fast
    int n;
    cin>>n;
    vector<pair<p2d,ll>> m(n);
    ll tot = 0;
    for(int i=0;i<n;i++){
    	cin>>m[i].first.x>>m[i].first.y>>m[i].second;
    	tot += m[i].second;
    }

    ll ans = 1e18;
    for(int i=0;i<n;i++){
    	vector<pair<ld,ll>> v;
		p2d &a = m[i].first;
    	for(int j=0;j<n;j++){
    		if( i == j ) continue ;
    		p2d &b = m[j].first;
    		p2d dif = a-b ;
    		ld ang = atan2( dif.y , dif.x );
    		if( ang < 0 ) ang += 2*PI ;
    		v.push_back({ang , j});
    	}
    	sort(all(v));
    	vector<ll> pre(n);
    	vector<ld> an;
    	// cerr << i << '\n';
    	for(int j=0;j<v.size();j++){
    		pre[j] = (i ? pre[j-1] : 0LL) + m[v[j].second].second;
    		// cerr << j << ' '  << v[j].first << ' ' << v[j].second <<' ' << pre[j] << '\n';
    		an.push_back(v[j].first);
    	}

    	// break;

    	for(int j=0;j<an.size();j++){
    		ld ang = an[j];
    		if( ang < 0 ) ang += 2 * PI ;
    		if(ang >= PI)ang -= PI;
    		ld to = ang + PI;

    		int l = lower_bound(all(an) , ang) - an.begin();
    		int r = upper_bound(all(an) , to) - an.begin() - 1;

    		ll cur = pre[r] - (l ? pre[l-1] : 0LL) - m[v[j].second].second;

    // 		if(abs(cur - (tot - cur - m[i].second - m[v[j].second].second)) == 2){
    // 			cerr << cur << ' ' << (tot - cur - m[i].second - m[v[j].second].second) << '\n';
    // 			cerr << m[i].first.x << ' '  << m[i].first.y << '\n';
    // 			cerr << m[v[j].second].first.x << ' '  << m[v[j].second].first.y << '\n';
				// cerr << i << ' ' << v[j].second << ' ' << abs(cur - (tot - cur - m[i].second - m[v[j].second].second)) << '\n';
    // 		}
    		ans = min(ans , abs(cur - (tot - cur - m[i].second - m[v[j].second].second)));
    	}

    }
    cout << ans << '\n';
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/