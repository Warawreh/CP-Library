#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

map< pair<int,int> , bool > used ;
map< int , bool > vis ;

int main(){
    fast
    int n , m ; cin >> n >> m ;
    int l , r ; cin >> l >> r ;
    vector< vector<pair<int,ll>> > g( n );
    for( int i = 0 ; i < m ; i++ ){
    	int u,v,w;
    	cin>>u>>v>>w;
    	g[u].push_back({v,w+w});
    	g[v].push_back({u,w+w});
    }

    vector<ll> dist(n, (ll)1e18);
    priorty_queue<pair<ll,int>> q;
    q.push({0,0});
    dist[0] = 0;
    while(q.size()){
    	int u = q.top().second;
    	ll d = -q.top().first;

    	if(d > dist[u])continue;

    	for(auto &[v,w] : g[u]){
    		ll nd = d + w;
    		if(nd >= dist[v])continue;
    		dist[v] = nd;
    		q.push({-nd , v});
    	}
    }
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/