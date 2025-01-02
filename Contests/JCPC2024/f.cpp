#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
    fast
    int a,b,x;
    cin>>a>>b>>x;

    int ans = 1e9;
    int cur = 0;
    for(int k=30;k>=0;k--){
        int need = 2 - ((a >> k) & 1) - ((b >> k) & 1);
        if((x >> k) & 1){
            cur += need;
        }else{
            ans = min(ans, cur + need);
        }
    }
    ans = min(ans, cur);

    vector<pair<char, int>> steps;
    cur = 0;
    for(int k=30;k>=0;k--){
        int need = 2 - ((a >> k) & 1) - ((b >> k) & 1);
        if((x >> k) & 1){
            if(((b >> k) & 1) == 0)steps.push_back({'b',k});
            if(((a >> k) & 1) == 0)steps.push_back({'a',k});
            cur += need;
        }else{
            if(cur + need == ans){
                if(((b >> k) & 1) == 0)steps.push_back({'b',k});
                if(((a >> k) & 1) == 0)steps.push_back({'a',k});
                break;
            }
        }
    }

    cout << ans << '\n';
    for(auto a : steps){
        cout << a.first << ' ' << a.second << '\n';
    }
}
