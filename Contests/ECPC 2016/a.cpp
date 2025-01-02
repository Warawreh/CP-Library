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
   freopen("powers.in","r",stdin);
   int t;
   cin>>t;
   while(t--){
   	ll g;
   	cin>>g;
   	ll ans = 0;
   	for(int i=0;i<g;i++){
   		ll b,n;
   		cin>>b>>n;
   		if(b % 2 == 0){
   			n %= (b + 1);
   			if(n == b)ans ^= 2;
   			else ans ^= (n % 2);
   		}else{
   			ans ^= (n % 2);
   		}
   	}
   	if(ans == 0)cout << 2 << '\n';
   	else cout << 1 << '\n';
   }
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/