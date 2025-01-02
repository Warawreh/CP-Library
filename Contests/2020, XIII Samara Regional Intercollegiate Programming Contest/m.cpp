#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(10);
	cout << fixed;
	int n;
	cin>>n;
	ll to=0;
	multiset<int> st;
	for(int i=0;i<n;i++){
		int t,d;
		cin>>t>>d;
		while(st.size() && to <= t){
			to += *st.begin();
			st.erase(st.begin());
		}
		if(to > t){
			st.insert(d);
		}else{
			to = t+d;
		}
	}
	while(st.size()){
		to += *st.begin();
		st.erase(st.begin());
	}
	cout << to << '\n';
}