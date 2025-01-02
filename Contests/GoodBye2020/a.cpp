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
		int n;
		cin>>n;
		vector<int> a(n);
		set<int> st;
		for(int i=0;i<n;i++){
			cin>>a[i];
			for(int j=0;j<i;j++){
				st.insert(abs(a[i] - a[j]));
			}
		}
		cout << st.size() << '\n';
	}
}