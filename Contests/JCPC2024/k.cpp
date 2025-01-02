#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int changeCost(char a,char b){
    int c1 = a - 'a';
    int c2 = b - 'a';
    if(c1 > c2)swap(c1, c2);
    int cost = c2 - c1;
    cost = min(cost, 26 - c2 + c1);

    return cost;
}

int main(){
    fast
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;

    vector<int> cost(n + 3, 0);
    for(int i=n-3;i>=0;i--){
        cost[i] = changeCost(s[i], 'd') + changeCost(s[i + 1], 'o') + changeCost(s[i + 2], 'z') + cost[i + 3];
    }

    while(q--){
        int l,r;
        cin>>l>>r;
        l--;r--;

        int ans = 1e9;

        int cnt = (r - l + 1)/3;

        for(int i=l;i<l+3;i++){
            if(r - i + 1 < 3)continue;
            int to = i + cnt * 3 - 1;
            if(to > r)continue;
            int cur = cost[i] - cost[to + 1];
            ans = min(ans, cur);
        }

        if(ans == 1e9)ans = -1;
        cout << ans << '\n';
    }
}
