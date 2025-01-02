#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

void solve(){
    ll n;
    cin >> n;
    set<pair<ll,pair<ll,ll>>> ps;
    for (ll i = 0; i < n; ++i){
        ll x, y;
        cin >> x >> y;
        ps.insert({x, {y, i}});
    }
    set<pair<ll,pair<ll,ll>>> s;

    vector<ll> sum(n,0);
    ll px = -1, py = -1;
    ll co = 1;

    for(auto x : ps){
        if(px == -1){
            px = x.first;
            py = x.second.first;
            s.insert({x.first, {x.second.first, 0}});
            continue;
        }
        s.insert({x.first, {x.second.first, co}});
        sum[co] = sum[co - 1] + max(abs(x.first -  px), abs(x.second.first -  py));
        
        co++;
        px = x.first;
        py = x.second.first;  
    }
    ll q;
    cin >> q;
    while(q--){
        ll x, y;
        cin >> x >> y;
        auto lo = s.upper_bound({x, {y,1e5+1}});
        if(lo == s.end()){
            cout << 1000000001 - x << endl;
        }else{
            ll idx = (*lo).second.second;
            ll dx = (*lo).first, dy = (*lo).second.first;
            ll st = max(abs(x - dx), abs(y -  dy));
            ll md = sum[n - 1] - sum[idx];
            ll fi = 1e9+1 - (*s.rbegin()).first;
            // cerr << st << " " << md << " " << fi << endl;
            cout << st + md + fi << endl;
        }
    }

}

int main(){
    fast
    int t;
    cin >> t;
    while(t--) solve();
}
