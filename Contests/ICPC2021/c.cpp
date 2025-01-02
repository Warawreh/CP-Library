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
    cout << setprecision(6) << fixed;
    ld f = 2.0/3;
    ld m;
    int n;
    cin>>n>>m;
    vector<ld> hv(n);
    for(int T=0;T<=100;T++){
    	if(m == 0)break;
    	for(int i=0;i<n;i++){
    		hv[i] += m * f;
    		m -= m * f;
    	}
    	cout << m << '\n';
	    for(int i=0;i<n;i++)
	    	cout << hv[i] << ' ';
	    cout << '\n' << '\n';
    }
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/