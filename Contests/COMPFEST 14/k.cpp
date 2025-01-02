#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct DSU{

   vector<int> dsu,sz,rnk,val;

   void init(int n,int x){
      dsu = sz = rnk = val = vector<int> (n+x);
      iota(dsu.begin()+x,dsu.end(),x);
      fill(sz.begin(),sz.end(),1);
   }

   int find(int u){
      return u == dsu[u] ? u : dsu[u] = find(dsu[u]);
   }

   bool merge(int u,int v,int nVal){
      u = find(u);
      v = find(v);
      if(u == v)return false;
      if(sz[u] < sz[v])swap(u,v);
      // if(rnk[u] > rnk[v])swap(u,v);
      sz[u] += sz[v];
      // rnk[v] = rnk[u] + 1;
      dsu[v] = u;
      val[u] = nVal;
      return true;
   }   
};

const int nax = 2e6;

int main(){
	fast

	DSU dsu;
	dsu.init(nax,0);
	int id = 0;

	int n;
	cin>>n;
	vector<int> curId(n),a(n);
	set<pair<int,int>> st;
	for(int i=0;i<n;i++){
		cin>>a[i];

		curId[i] = id;
		dsu.val[id] = a[i];
		st.insert({a[i] , id++});
	}

	int q;
	cin>>q;
	while(q--){
		int t;
		cin>>t;
		if(t == 1){//change val
			int i,h;
			cin>>i>>h;
			i--;

			if(st.find({a[i] , i}) != st.end()){
				st.erase(st.find({a[i] , i}));
			}

			a[i] = h;
			curId[i] = id;
			dsu.val[id] = a[i];
			st.insert({h , id});
			id++;
		}else if(t == 2){//Query
			int i;
			cin>>i;
			i--;
			cout << dsu.val[dsu.find(curId[i])] << '\n';
		}else if(t == 3){//ranges
			int l,r;
			cin>>l>>r;

			{
				int fr = l;
				int to = (l + r)/2;
				dsu.val[id] = fr-1;

				while(st.size()){
					auto it = st.lower_bound({fr , -1});
					if(it == st.end())break;
					if((*it).first > to)break;

					int nxtId = (*it).second;
					dsu.merge(id , nxtId , fr - 1);
					st.erase(it);
				}

				st.insert({fr - 1, id});
				id++;

			}

			{
				int fr = (l + r + 1)/2;
				int to = r;
				dsu.val[id] = to+1;

				while(st.size()){
					auto it = st.lower_bound({fr , -1});
					if(it == st.end())break;
					if((*it).first > to)break;

					int nxtId = (*it).second;
					dsu.merge(id , nxtId , to + 1);
					st.erase(it);
				}

				st.insert({to + 1, id});
				id++;
			}
		}
	}

}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/