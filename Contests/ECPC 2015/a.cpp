#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ld POW(ld a,ll b){
	if(!b)return 1;
	ld res = POW(a,b/2);
	res = (res * res);
	if(b % 2)res = (res * a);
	return res;
}

int main(){
    fast

    vector<ll> fact(11);
    fact[0] = 1;
    for(int i=1;i<11;i++){
    	fact[i] = fact[i-1] * i;
    }

    cout << setprecision(9) << fixed;
 	int t;
 	cin>>t;
 	while(t--){
 		string a;
 		cin>>a;
 		string b = a;
 		ll n = fact[a.size()];
 		ll at = 0;
 		reverse(all(a));
 		for(int i=1;i<a.size();i++){
 			int s=0;
 			for(int j=0;j<i;j++){
 				s += (a[j] < a[i]);
 			}
 			at += s * (fact[i]);
 		}
 		if(at == n - 1){
 			cout << 0.0 <<'\n';
 			continue;
 		}

 		ld cur = (POW(1 + 1.0/n , n - at - 2));
 		cur /= n;
 		// cur += 1.0/n;
 		cout << cur << '\n';
 	}   
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/