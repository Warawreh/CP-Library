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
	int n,k,r;
	cin>>n>>k>>r;
	ll sum = 0;
	multiset<ll> st,b;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		st.insert(x);
	}
	for(int i=0;i<k;i++){
		sum += *st.begin();
		b.insert(*st.begin());
		st.erase(st.begin());
	}
	while(r--){
		ll cur = *b.begin();
		b.erase(b.begin());
		st.insert(sum);
		sum -= cur;
		sum += *st.begin();
		b.insert(*st.begin());
		st.erase(st.begin());
	}
	while(b.size()){
		st.insert(*b.begin());
		b.erase(b.begin());
	}
	for(ll it : st){
		cout << it << ' ';
	}
}