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
    ll r,c;
    int n;
    cin>>r>>c>>n;

    ll sum = 0,cnt = 0,cnt2=0,sum2=0;
    vector<int> mn(r,-1),mx(r,-1);
    vector<vector<int>> at(c);
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        at[y].push_back(x);

        if(y > mx[x]){
            if(mx[x] == -1){
                cnt++;
            }else{
                sum -= mx[x];
            }
            sum += y;
            mx[x] = y;
        }
    }
    // cerr << sum << '\n';
    ll ans = 1e18;
    for(int h=0;h<c;h++){
        ans = min(ans , sum - cnt * h + cnt2 * h - sum2);
        // cerr << x << ' ' << y << ' ' << sum << ' ' << cnt << '\n';
        for(int x : at[h]){
            if(mn[x] == -1){
                mn[x] = h;
                sum2 += h;
                cnt2++;
            }
            if(mx[x] == h){
                cnt--;
                sum -= h;
                mx[x] = -1;
            }
        }
    }
    cout << ans * 2 + r - 1 << '\n';
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/