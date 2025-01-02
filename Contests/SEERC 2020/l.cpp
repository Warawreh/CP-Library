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
    int n;
    cin>>n;
    vector<pair<ll,ll>> p(n);
    for(int i=0;i<n;i++)cin>>p[i].first;
    for(int i=0;i<n;i++)cin>>p[i].second;

    sort(all(p),[](pair<ll,ll> a,pair<ll,ll> b){
        return a.first + a.second < b.first + b.second;
    });
    
    
    int ans=0;
    set<int> st;
    for(int i=0;i<n;i++)st.insert(i);

    for(int it=0;it<700;it++){
        int at = uniform_int_distribution<int>(0, n-1)(rng);
        auto cur = st.lower_bound(at);
        if(cur == st.end())cur--;
        int md = *cur;


        int ans1 = 0;
        {
            vector<ll> a,b;
            for(int i=0;i<md;i++)a.push_back(p[i].second);
            for(int i=md;i<n;i++)b.push_back(p[i].first);
            sort(all(a));
            sort(all(b));
            reverse(all(b));
            ll tot = 0;
            for(int i=0;i<min(a.size() , b.size());i++){
                tot += b[i];
                tot -= a[i];
                if(tot >= 0)ans1 = max(ans1 , i+1);
            }

        }

        ans = max(ans , ans1);


    }

    cout << ans << '\n';
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/