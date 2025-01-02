#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef int T;
typedef tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;


#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct DSU{

   vector<int> dsu,sz;
   vector<indexed_set> st;
   void init(int n,int x){
      dsu = sz = vector<int> (n+x);
      iota(dsu.begin()+x,dsu.end(),x);
      fill(sz.begin(),sz.end(),1);
      st.clear();
      st.resize(n);
      for(int i=0;i<n;i++)st[i].insert(i);
   }

   int find(int u){
      return u == dsu[u] ? u : dsu[u] = find(dsu[u]);
   }

   bool merge(int u,int v){
      u = find(u);
      v = find(v);
      if(u == v)return false;
      if(sz[u] < sz[v])swap(u,v);
      for(auto &v : st[v])st[u].insert(v);
      st[v].clear();
      sz[u] += sz[v];
      dsu[v] = u;
      return true;
   }   
};


void solve(){
	int n,m;
	cin>>n>>m;
	vector<int> at(n);
	iota(all(at) , 0);
	ll ans = 0;

	vector<pair<int,int>> e;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		a--;b--;
		e.push_back({a,b});
	}

	vector<vector<ll>> game;
	for(int i=2;i<=n;i++){
		game.push_back({i , 0 , m - 1 , -1});
	}

	while(1){
		int cnt = 0;
		vector<vector<int>> event(m);
		for(int i=0;i<game.size();i++){
			if(game[i][1] > game[i][2]){
				continue;
			}
			cnt++;
			int md = (game[i][1] + game[i][2]) / 2;
			event[md].push_back(i);
		}
		if(!cnt)break;

		DSU dsu;
		dsu.init(n , 0);
		vector<int> at(n);
		iota(all(at) , 0);

		for(int i=0;i<m;i++){
			int a = e[i].first;
			int b = e[i].second;

			if(at[b] == -1 || at[a] == -1){
				at[b] = at[a];
				at[a] = -1;
			}else{
				dsu.merge(at[a] , at[b]);
				at[b] = dsu.find(at[b]);
				at[a] = -1;
			}


			for(int id : event[i]){
				int cur = 0;
				int k = game[id][0];
				while(1){
					int fr = cur * k;
					int to = (cur + 1) * k - 1;
					to = min(to , n-1);
					if(fr >= n){
						game[id][2] = i - 1;
						game[id][3] = i + 1;
						break;
					}
					indexed_set &st = dsu.st[dsu.find(fr)]; 
					int r = st.order_of_key(to);
					int l = st.order_of_key(fr);
					if(r < st.size() && fr == *st.find_by_order(l) && to == *st.find_by_order(r) && r - l + 1 == to - fr + 1){
						cur++;
					}else{
						game[id][1] = i+1;
						break;
					}
				}
				
			}
			
		}
	}

	for(int i=0;i<game.size();i++){
		ans += game[i][3];
	}

	cout << ans << '\n';
}

int main(){
	fast
	int t;
	cin>>t;
	for(int T=1;T<=t;T++){
		cerr << T << ',';
		cout << "Case #" << T << ": ";
		solve();
	}
}