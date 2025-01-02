#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
   ll n,m,c;
   cin>>n>>m>>c;

   map<int,vector<pair<ll,ll>>> d1,d2;
   for(int i=0;i<m;i++){
      ll r,c,p;
      cin>>r>>c>>p;
      d1[r + c].push_back({c , p});
      d2[r - c].push_back({c , p});
   }

   int ans = 1;

   for(auto d : {d1,d2}){

      for(auto &current : d){
         sort(all(current.second));
         set<pair<ll,ll>> st;
         for(auto &[r,p] : current.second){
            auto it = st.upper_bound({r - p*p + 1 - c , 1e9});
            int len = 1;
            ll val = p*p + r;
            if(it != st.begin()){
               it--;
               // assert(it == st.begin());
               len = (*it).second + 1;
            }
            st.insert({val , len});

            it = st.lower_bound({val , len});
            if(it != st.begin()){
               it--;
               if((*it).second >= len)st.erase({val , len});
            }

            while(1){
               it = st.upper_bound({val , len});
               if(it == st.end())break;
               if((*it).second < len)st.erase(it);
               else break;
            }

            ans = max(ans , len);
         }
      }
   }

   cout << ans << '\n';

}

int main(){
   fast
   freopen("bishops.in","r",stdin);
   int t;
   cin>>t;
   while(t--)solve();
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/