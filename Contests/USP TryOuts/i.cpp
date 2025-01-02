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
    	ll a,b;
    	cin>>a>>b;
    	int at = 0;
    	while(1){
    		if(b >= (ll)1e18)break;
    		ll need = (a - (b%a))%a;
    		if(to_string(need).size() <= at){
    			cout << b + need << '\n';
    			break;
    		}
    		if(b >= (ll)1e17)break;
    		b*= 10;
    		at++;
    	}

    }
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/