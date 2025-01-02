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
		int h,w;
		cin>>h>>w;
		vector<ll> st;
		for(int i=0;i<4;i++){	
			for(int j=0;j<4;j++){
				vector<ll> vals = {h,h,w,w};
				if((i & 1)){
					vals[2]--;
				}else{
					vals[0]--;
				}

				if((i & 2)){
					vals[3]--;
				}else{
					vals[0]--;
				}

				if((j & 1)){
					vals[2]--;
				}else{
					vals[1]--;
				}

				if((j & 2)){
					vals[3]--;
				}else{
					vals[1]--;
				}

				ll g = 0;
				for(ll x : vals)g = gcd(g , x);

				for(ll k=1;k*k<=g;k++){
					if(g % k == 0){
						st.push_back(k);
						st.push_back(g / k);
					}
				}

			}
		}

		sort(all(st));
		st.resize(unique(all(st)) - st.begin());

		cout << st.size();
		for(int i : st)
			cout << ' ' << i;
		cout << '\n';
	}
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/