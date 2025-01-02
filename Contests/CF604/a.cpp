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
	int tt;
	cin>>tt;
	while(tt--){
		int n;
		cin>>n;
		set<int> st;
		map<int,int> mp;
		for(int i=0;i<n;i++){
			int a;
			cin>>a;
			st.insert(a);
			mp[a]++;
		}
		int hv = n;
		while(hv * 2 > n){
			int a = *st.begin();
			hv -= mp[a];
			st.erase(st.begin());
		}	
		int g=0,s=0,b=0;
		if(st.size()){
			int a = *st.rbegin();
			st.erase(a);
			g = mp[a];
			while(st.size() && s <= g){
				int a = *st.rbegin();
				st.erase(a);
				s += mp[a];
			}

			while(st.size()){
				int a = *st.rbegin();
				st.erase(a);
				b += mp[a];
			}
			if(g >= s || g >= b)g = s = b = 0;
		}
		cout << g << ' ' << s << ' ' << b << '\n';
	}
}