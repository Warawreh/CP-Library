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
    vector<pair<int,int>> e;
    int n;
    cin>>n;
    for(int i=0;i<n*(n-1)/2;i++){	
    	int u,v;
    	cin>>u>>v;
    	u--;v--;
    	e.push_back({u,v});
    }

    ll cur = 0;
	for(int i=0;i<n;i++){
    	int fr=1e9,to = -1;
		for(int l=0;l<e.size();l++){
			if(e[l].first == i || e[l].second == i){
				fr = min(fr , l);
				to = max(to , l);
			}
		}
		// cerr << i << ' '  << fr << ' ' << to << '\n';
    	cur += to - fr;
	}
	cout << cur << '\n';
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/