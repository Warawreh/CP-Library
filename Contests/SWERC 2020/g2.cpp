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
    int n,m;
    cin>>n>>m;
    vector<int> d(n);
    vector<vector<int>> g(n);
    vector<int> in(n);
    for(int i=1;i<n;i++){
    	for(int j=i;j<n;j+=i){
    		d[j]++;
    	}
    	int to = (i + d[i])%n;
    	g[i].push_back(to);
    	in[to]++;
    }
        
    int cur = 1;
    for(int i=1;i<=m;i++){
        cout << cur << ' ';
        int nxt = (cur + d[cur]);
        cur = nxt;
    }
    cout << '\n';
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/