#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int cnt = 0;
int a,b,k;

void prt(int i){
	if(i == 0){
		// cerr << a << ',';
		// cerr << "BAD " << a << ' ' << b << ' ' << b - a << ' ' << k  << '\n';
		cout << 0 << '\n';
	}else{
		cout << 1 << '\n';
		// cerr << a << ' ' << b << ' ' << k  << '\n';
	}
}

ll S(ll a){return a * a;}

void solve(){
	cin>>k>>a>>b;
	// k = 2;

	if(a == 0 && b == 0){
		prt(0);
		return;
	}
	if(a == 0 || b == 0 || abs(a - b) <= k){
		prt(1);
		return;
	}
	if(a > b)swap(a,b);
	ll ord = (b - a) / (k + 1);
	// cerr << ord << '\n';
	if((b - a) % (k + 1) != 0){
		prt(1);
		return;
	}

	ld val = 0;
	/*if(k < r.size()){
		val = r[k];
	}else*/{

		ll fr = 1;
		unordered_map<ll , bool> bad;
		ll add = (k + 1);
		ll cnt = 0;
		ld sum = 0;

		// while(1){
		// 	if(++cnt >= 1000)break;
		// 	sum += ((fr + (ld)0) / cnt);
		// 	// cerr << fr + add << '\n';
		// 	bad[fr + add] = 1;
		// 	fr++;
		// 	while(bad[fr])fr++;
		// 	add += (k + 1);
		// }

		ld lo = (k + 2) ,hi = (k + 3)  , s = 1e9;
		for(int IT=0;IT <= 50;IT++){
			ld md = (hi + lo) / 2;

			ld r = md / (md - 1);
			ll l = r * ord;
			ll right = md * ord;
			cerr << r << ' ' << l << ' ' << right << '\n';
			if(l == a && right == b){
				prt(0);
				return;
			}
			if(right < b){
				lo = md;
			}else hi = md;
		}
		prt(1);
		return;
		// ll l = r * ord;

		// cerr << ord << ' ' << l << ' ' << r << '\n';

		// if(a == l ){
		// 	prt(0);
		// }else prt(1);
	}


}

int main(){
    fast
	int t;
	cin>>t;
	while(t--)solve();    
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/

/*
BAD 2 6 1
BAD 4 10 1
BAD 5 13 1
BAD 7 17 1
BAD 8 20 1
BAD 9 23 1
BAD 11 27 1
BAD 12 30 1

BAD 3 12 2
BAD 5 17 2
BAD 6 21 2
BAD 7 25 2
BAD 9 30 2

BAD 4 20 3
BAD 6 26 3

BAD 5 30 4

*/