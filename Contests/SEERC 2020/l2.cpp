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
    vector<pair<ll,ll>> b(n);
    for(int i=0;i<n;i++)cin>>b[i].first>>b[i].second;
    sort(all(b) , [](pair<ll,ll> a,pair<ll,ll> b){
        return a.first + a.second < b.first + b.second;
    });
    
 
    ll tot = 0;
    multiset<ll> st;
    for(int i=0;i<n;i++){
        tot += b[i].second;
        st.insert(b[i].second);
        if(st.size() && tot > b[i].first + b[i].second){
            tot -= *st.rbegin();
            st.erase(st.find(*st.rbegin()));
        }

        // cerr << b[i].first << ' ' << b[i].second << ' ' << tot << '\n';

    }
    cout << st.size() << '\n';
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/