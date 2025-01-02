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
		int n,m;
		cin>>n;
		vector<int> a(n);
		for(int i=0;i<n;i++)cin>>a[i];
		cin>>m;
		vector<int> b(m);
		for(int i=0;i<m;i++)cin>>b[i];
		sort(all(a));
		sort(all(b));
		if(n != m){
			cout << "NO\n";
			continue;
		}
		vector<int> x;
		bool good = true;
		vector<int> c;
		for(int i=0;i<n;i++){
			if(i && (a[i] == a[i-1] || b[i] == b[i - 1])){
				if(b[i] != b[i-1] || a[i] != a[i-1]){
					good = false;
				}
				continue;
			}
			// c.push_back(a[i] - b[i]);
		}
		// set<int> st;
		// for(int i=1;i<c.size();i++)st.insert(c[i] - c[i-1]);
		// if(st.size() > 1)good = false;
		cout << (good ? "YES\n" : "NO\n");
	}	
}