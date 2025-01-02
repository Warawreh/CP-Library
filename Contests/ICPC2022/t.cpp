#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int n;
vector<int> a;
const int nax = 1e6;

unordered_map<int, ll> dp[nax];
unordered_map<int, int> ggg[nax];

int gcd_2(int a,int b){
    if(ggg[a][b] != 0)return ggg[a][b];
    ggg[a][b] = ggg[b][a] = gcd(a,b);
    return ggg[a][b];
}

ll calc(int i,int g1, int g2){
    if(g1 < g2)swap(g1, g2);
    if(i == n){
        if(g1 == 0 || g2 == 0)return -1;
        return (g1 * 1LL * g2) / gcd_2(g1, g2);
    }
    ll &ret = dp[g1][g2];
    if(ret != 0)return ret;

    ret = max(calc(i + 1, (g1 == 0 ? a[i] : gcd_2(g1, a[i])), g2) , calc(i + 1, g1, (g2 == 0? a[i] : gcd_2(g2, a[i]))));
    return ret;
}

int main(){
    fast
    cin>>n;
    a.resize(n);
    for(int i=0;i<n;i++)cin>>a[i];

    vector<pair<int,int>> states;
    states.push_back({0,0});

    for(int i=0;i<n;i++){
        set<pair<int,int>> new_states;
        for(auto x:states){
            pair<int,int> temp = {x.first == 0 ? a[i] : gcd_2(x.first, a[i]), x.second};
            if(temp.first < temp.second)swap(temp.first, temp.second);

            new_states.insert(temp);

            temp = {x.first, x.second == 0 ? a[i] : gcd_2(x.second, a[i])};
            if(temp.first < temp.second)swap(temp.first, temp.second);

            new_states.insert(temp);
        }

        states.clear();
        for(auto x:new_states)states.push_back(x);
    }

    cerr << states.size() << '\n';

    ll ans = 0;
    for(auto x:states){
        if(x.first == 0 || x.second == 0)continue;
        ans = max(ans, (x.first * 1LL * x.second) / gcd_2(x.first, x.second));
    }
    
    cout<<ans<<endl;
}
