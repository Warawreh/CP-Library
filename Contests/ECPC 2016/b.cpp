#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll oo = 1e18;
inline ld S(ld a){return a*a;}

ld D(pair<ld,ld> a,pair<ld,ld> b){
   return (S(a.first - b.first) + S(a.second - b.second));
}

void solve(){
   ll n,L,W;
   cin>>n>>L>>W;

   vector<vector<ll>> s(n,vector<ll>(4));

   for(int i=0;i<n;i++){
      ll h,w,d,k;
      cin>>h>>w>>d>>k;
      s[i] = {d,d+h,(k == 0 ? 0LL : W - w), (k == 0 ? w : W)};
      assert(s[i][1] <= L);
   }

   vector<ld> dist(n , 1e18);
   priority_queue<pair<ld,int>> q;
   for(int i=0;i<n;i++){
      dist[i] = s[i][0];
      q.push({-dist[i] , i});
   }
   ld ans = L;

   while(q.size()){
      int u = q.top().second;
      ld d = -q.top().first;

      // cerr << u << ' ' << d << '\n';
      q.pop();
      if(d  > dist[u])continue;
      ans = min(ans , d + L - s[u][1]);

      for(int i=0;i<n;i++){
         if(i == u)continue;
         ld nd = d;
         if(s[i][0] >= s[u][1]){//Up


            ld cur = min(D({s[u][1] , s[u][3]} , {s[i][0], s[i][2]}) , D({s[u][1] , s[u][2]} , {s[i][0], s[i][3]}));
            cur = min(cur , min(D({s[u][1] , s[u][3]} , {s[i][0], s[i][3]}) , D({s[u][1] , s[u][2]} , {s[i][0], s[i][2]})));

            cur = sqrt(cur);

            if(s[u][2] <= s[i][2] && s[u][3] >= s[i][2])cur = min(cur , (ld)abs(s[i][0] - s[u][1]));
            if(s[u][2] <= s[i][3] && s[u][3] >= s[i][3])cur = min(cur , (ld)abs(s[i][0] - s[u][1]));

            nd += (cur);

         }else if(s[i][1] <= s[u][0]){//down

            ld cur = min(D({s[u][0] , s[u][3]} , {s[i][1], s[i][2]}) , D({s[u][0] , s[u][2]} , {s[i][1], s[i][3]}));
            cur = min(cur , min(D({s[u][0] , s[u][3]} , {s[i][1], s[i][3]}) , D({s[u][0] , s[u][2]} , {s[i][1], s[i][2]})));

            cur = sqrt(cur);
            if(s[u][2] <= s[i][2] && s[u][3] >= s[i][2])cur = min(cur , (ld)abs(s[i][1] - s[u][0]));
            if(s[u][2] <= s[i][3] && s[u][3] >= s[i][3])cur = min(cur , (ld)abs(s[i][1] - s[u][0]));

            nd += (cur);

         }else{//next

            ld cur = min(abs(s[u][2] - s[i][3]) , abs(s[u][3] - s[i][2]));
            nd += cur;

         }

         if(nd  >= dist[i])continue;
         dist[i] = nd;
         q.push({-dist[i] , i});

      }
   }

   cout << ans << '\n';
}

int main(){
   fast

   cout << setprecision(6) << fixed;
   freopen("street.in","r",stdin);
   int t;
   cin>>t;
   while(t--)solve();
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/