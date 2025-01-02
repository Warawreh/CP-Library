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
	freopen("hotel.in","r",stdin);	

	for(int x=1332;x<=1332;x++){
		vector<int> hv(64);
		for(int i=x+1;i<=x+x;i++){
			hv[__builtin_popcountll(i)]++;
		}
		cerr << x << ": \n";
		cerr << hv[11] << '\n';
		// for(int i=1;i<10;i++)
		// 	cerr << hv[i] << ' ';
		cerr << '\n';
	}
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/