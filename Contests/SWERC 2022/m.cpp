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
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int r=0,w=0;
		for(int i=0;i<m;i++){
			int a,b;
			cin>>a>>b;
			r = max(r , a);
			w = max(w , b);
		}
		if(r + w > n){
			cout << "IMPOSSIBLE\n";
		}else{
			int rem = n - r - w;
			cout << string(r,'R') + string(w,'W') + string(rem,'R') << '\n';
		}
	}	
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/