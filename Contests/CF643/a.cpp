#include <bits/stdc++.h>

using namespace std;

#define fast ios::sync_with_stdio(false);cin.tie(0);
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(){
	fast
	int t;
	cin>>t;
	while(t--){
		ll a,k;
		cin>>a>>k;
		k--;
		while(k--){
			set<int> st;
			ll tmp = a;
			while(tmp){
				st.insert(tmp%10);
				tmp/=10;
			}
			if(*st.begin() == 0)break;
			a += *st.begin() * *st.rbegin();
		}
		cout << a << '\n';
	}
}