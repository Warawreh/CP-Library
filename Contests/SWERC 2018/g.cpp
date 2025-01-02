#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1e9 + 7;
vector<ll> len,pre;
vector<vector<ll>> e;
map<pair<ll,ll> , ll> dp[2550];
map<pair<ll,ll> , bool> vis[2550];

ll calc(int i,ll l,ll r){
    if(l > r)return 0;
    if(i == 0){
        // cerr << i << ' ' << l << ' ' << r << '\n';
        // cerr << (pre[r] - (l ? pre[l-1] : 0LL) + mod)%mod << '\n';
        return (pre[r] - (l ? pre[l-1] : 0LL) + mod)%mod;
    }

    ll &ret = dp[i][{l,r}];
    if(vis[i][{l,r}])return ret; 
    vis[i][{l,r}] = 1;

    if(e[i].size() == 3){//sub
        ret = calc(e[i][0] , e[i][1] + l , e[i][1] + l + (r - l));
    }else{//add
        int left = e[i][0];
        int right = e[i][1];
        if(r < len[left])ret = calc(left , l , r);
        else if(l >= len[left])ret = calc(right , l - len[left] , r - len[left]);
        else{
            ret = (calc(left , l , len[left] - 1) + calc(right , 0 , r - len[left])) % mod;
        }
    }

    return ret;
}

int main(){
    fast
    int n;
    string s;
    cin>>n>>s;

    pre.resize(s.size());
    for(int i=0;i<s.size();i++){
        pre[i] = (int(s[i]) + (i ? pre[i-1] : 0LL))%mod;
    }

    len.resize(n);
    len[0] = s.size();
    e.resize(n);
    for(int i=1;i<n;i++){
        string o;
        cin>>o;
        if(o[0] == 'S'){
            ll id,l,r;
            cin>>id>>l>>r;
            r--;
            e[i] = {id , l , r};
            len[i] = r - l + 1;
        }else{
            ll id1,id2;
            cin>>id1>>id2;
            e[i] = {id1,id2};
            len[i] = len[id1] + len[id2];
        }
    }

    cout << calc(n-1,0,len[n-1] - 1) << '\n';
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/