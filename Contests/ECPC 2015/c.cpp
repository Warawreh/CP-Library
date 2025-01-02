#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct DSU{

   vector<int> dsu,sz,rnk;

   void init(int n,int x){
      dsu = sz = rnk = vector<int> (n+x);
      iota(dsu.begin()+x,dsu.end(),x);
      fill(sz.begin(),sz.end(),1);
   }

   int find(int u){
      return u == dsu[u] ? u : dsu[u] = find(dsu[u]);
   }

   bool merge(int u,int v){
      u = find(u);
      v = find(v);
      if(u == v)return false;
      if(sz[u] < sz[v])swap(u,v);
      // if(rnk[u] > rnk[v])swap(u,v);
      sz[u] += sz[v];
      // rnk[v] = rnk[u] + 1;
      dsu[v] = u;
      return true;
   }   
};


void solve(){
    int n,q;
    cin>>n>>q;

    vector<vector<int>> Q(q);
    for(int i=0;i<q;i++){
        int t,u,v;
        cin>>t>>u>>v;
        u--;v--;
        Q[i] = {t,u,v,0,i,-1};
    }

    while(1){
        DSU d;
        d.init(n,0);
        vector<vector<int>> event(q);
        int cnt = 0;
        for(int i=0;i<q;i++){
            if(Q[i][0] == 1)continue;
            if(Q[i][3] > Q[i][4])continue;
            cnt++;
            int md = (Q[i][3] + Q[i][4])/2;
            event[md].push_back(i);
        }
        if(cnt == 0)break;

        for(int i=0;i<q;i++){
            if(Q[i][0] == 1){
                d.merge(Q[i][1] , Q[i][2]);
            }

            for(int id : event[i]){
                if(d.find(Q[id][1]) == d.find(Q[id][2])){
                    Q[id][4] = i-1;
                    Q[id][5] = i + 1;
                }else Q[id][3] = i+1;
            }
        }
    }

    for(int i=0;i<q;i++){
        if(Q[i][0] == 2)cout << Q[i][5] << '\n';
    }

}

int main(){
    fast
    int t;
    cin>>t;
    while(t--)solve();
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/