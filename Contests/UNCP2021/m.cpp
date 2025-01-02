#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct DSU{

   vector<int> dsu,sz,rnk,head;

   void init(int n,int x){
      head = dsu = sz = rnk = vector<int> (n+x);
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


int main(){
    fast
 	int n;
 	cin>>n;
 	vector<int> a(n);
 	for(int i=0;i<n;i++){
 		cin>>a[i];
 		a[i]--;
 	}

 	{

	 	vector<bool> vis(n,0);
		int u = 0;
		int cnt = 0;
		vis[u] = 1;
		while(1){
			cnt++;
			if(vis[a[u]]){
				break;
			}
			u = a[u];
			vis[u] = 1;
		}
		if(cnt == n){
			for(int i=0;i<n;i++)
				cout << a[i] + 1 << ' ';
			cout << '\n';
			return 0;
		}
 	}


 	int lo=0,hi=n-1,to=-1;
 	while(lo <= hi){
 		int md = (lo + hi)/2;

 		bool good = true;
 		vector<bool> vis(n);
 		vector<int> in(n);
 		for(int i=0;i<=md;i++){
 			if(in[a[i]])good = false;
 			in[a[i]]++;
 		}
 		int cnt = 0;
 		for(int i=0;i<=md;i++){
 			if(in[i] || vis[i])continue;
 			int u = i;
			vis[u] = 1;
 			while(u <= md){
 				cnt++;
 				u = a[u];
 				if(vis[u]){
 					good = false;
 					break;
 				}
 				vis[u] = 1;
 			}
 			
 		}
 		if(cnt != md + 1)good = false;


 		if(good){
 			lo = md+1;
 			to = md;
 		}else hi = md-1;
 	}
 	// cerr << to << '\n';
 	// return 0;

 	DSU d;
 	d.init(n,0);
 	vector<bool> vis(n,0);

 	set<int> st;
 	vector<int> in(n);
	for(int i=0;i<=to;i++){
		in[a[i]]++;
	}
 	for(int i=0;i<=to;i++){
		if(in[i] || vis[i])continue;
		st.insert(i);
		int u = i;
		vis[u] = 1;
		while(u <= to){
			d.merge(i , u);
			u = a[u];
			vis[u] = 1;
		}
		vis[u] = 1;
		d.merge(i , u);
		d.head[d.find(i)] = i;
		// cerr << i << '\n';
	}

	for(int i=to+1;i<n;i++){
		if(vis[i])continue;
		st.insert(i);
		d.head[i] = i;
		// cerr << i << '\n';
	}

	assert(st.size() == n - to - 1);
	// cerr << to << ' ' << st.size() << '\n';

	for(int i=to+1;i<n-1;i++){
		auto it = st.begin();
		// cerr << i << ' ' << *it << ' ' << d.head[d.find(i)] << ' ' << st.size() << ' ';
		int old = d.head[d.find(i)] ;
		if(*it == d.head[d.find(i)]){
			it++;
		}
		// cerr << *it << '\n';
		a[i] = *it;
		d.merge(i , *it);
		d.head[d.find(i)] = old;
		st.erase(it);
	}
	a[n-1] = *st.begin();
	for(int i=0;i<n;i++)
		cout << a[i] + 1 << ' ';
	cout << '\n';
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/