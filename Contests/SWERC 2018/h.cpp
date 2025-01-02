#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<vector<pair<int,int>>> g;
vector<vector<ll>> dist;

void dij(int st){
	priority_queue<pair<int,int>> q;
	q.push({0,st});
	dist[st][st] = 0;

	// cerr << st << '\n';
	while(q.size()){
		int u = q.top().second;
		int cst = -q.top().first;
		q.pop();
		// cerr<< u << ' ' << cst << '\n';
		if(cst > dist[st][u])continue;

		for(auto &[v,w] : g[u]){
			int ncst = cst + w;
			// cerr << u << ' ' << v << ' ' << w << ' ' << ncst << '\n';
			if(ncst >= dist[st][v])continue;
			dist[st][v] = ncst;
			q.push({-ncst , v});
		}
	}
	// cerr << '\n';
	// exit(0);
}

struct SegTree{
    typedef pair<ll,ll> T;
    int n;
    vector<T> seg;
    const T oo = {1e9 , 1e9};

    SegTree(int _n){
        n = _n;
        seg = vector<T>(4*n,oo);
    }

    T merge(T l, T r){
        return min(l , r);
    }

    void update(int l,int r,T val,int n,int s,int e){
        if(s > r || e < l || l > r)return;
        if(s >= l && e <= r){
            seg[n] = min(seg[n] , val);
            return;
        }

        update(l,r,val,n+n,s,(s+e)/2);
        update(l,r,val,n+n+1,(s+e)/2+1,e);

        seg[n] = merge(seg[n+n] , seg[n+n+1]);
    }

    T get(int l,int r,int n,int s,int e){
        if(s > r || e < l || l > r)return oo;
        if(s >= l && e <= r){
            return seg[n];
        }
        return merge(get(l,r,n+n,s,(s+e)/2) , get(l,r,n+n+1,(s+e)/2+1,e));
    }

    void update(int at,T val){
        update(at,at,val,1,1,n);
    }

    T get(int l,int r){
        return get(l,r,1,1,n);
    }

};

void comp(vector<ll> &c){
	vector<ll> b = c;
	sort(all(b));
	b.resize(unique(all(b)) - b.begin());
	for(int i=0;i<c.size();i++){
		c[i] = lower_bound(all(b) , c[i]) - b.begin();
	}
}

int main(){
    fast
 	int n,e;
 	cin>>n>>e;
 	g.resize(n);
 	dist = vector<vector<ll>>(3,vector<ll>(n , 1e9));
 	for(int i=0;i<e;i++){
 		int u,v,w;
 		cin>>u>>v>>w;
 		g[u].push_back({v,w});
 		g[v].push_back({u,w});
 	}

 	for(int i=0;i<3;i++){
 		dij(i);
 		comp(dist[i]);
 	}

 	vector<pair<pair<int,int>,pair<int,int>>> p;

 	for(int i=0;i<n;i++){
 		for(int x=0;x<3;x++)
 			assert(dist[x][i] < n);
 		p.push_back({{dist[0][i] , dist[1][i]} , {dist[2][i] , i}});
 	}
 	sort(all(p));

 	SegTree tree(n);
 	int ans = 0;
 	for(int i=0;i<p.size();i++){
 		int x = p[i].first.first + 1;
 		int y = p[i].first.second + 1;
 		int z = p[i].second.first + 1;

 		pair<int,int> v = tree.get(1 , y-1);
 		if(v <= make_pair(z , x))continue;
 		v = tree.get(y , y);
 		if(v < make_pair(z , x))continue;
 		// cerr << x << ' ' << y << ' ' << z << '\n';
 		tree.update(y , {z , x});
 		ans++;

 	}

 	cout << ans << '\n';
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/