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
    int n,h,w,s;
    cin>>n>>w>>h>>s;
    int mn = 1e9;
    char c = 'a';

    for(int i=0;i<n;i++){
    	char cur;
    	cin>>cur;
    	string g;
    	for(int j=0;j<h;j++){
    		cin>>g;
    		int cst = (g[0] == '#') + (g.back() == '#');
    		for(int x=1;x<w;x++){
    			cst += (g[x] != g[x-1]);
    		}
    		if(cst == 0)continue;

    		int need = 0;
			need = (s + cst - 1) / cst;
	    	if(need < mn){
	    		mn = need;
	    		c = cur;
	    	}
    	}

    }
    cout << string(mn , c) << '\n';
}
