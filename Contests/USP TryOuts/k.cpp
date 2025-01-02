#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


int main(){
    fast
    int n,b;
    cin>>n>>b;
    vector<ll> c;
    for(int i=0;i<n;i++){
    	ll x,y,t,v;
    	cin>>x>>y>>t>>v;
    	if(abs(x - y) <= t)continue;
    	if(x > y)continue;
    	if(t * b >= y){
    		c.push_back(v);
    	}
    }
    sort(all(c));
    reverse(all(c));


    ll ans = 0,mx = 0;
    for(int i=0;i<c.size();i++){
    	if((i + 1) * c[i] >= mx){
    		ans = c[i];
    		mx = (i + 1) * c[i];
    	}
    }
    cout << ans << '\n';
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/