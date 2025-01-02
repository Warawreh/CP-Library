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
		vector<int> b,hv(200);
		for(int i=0;i<n;i++){
			cin>>a[i];
			if(!hv[a[i]])b.push_back(a[i]);
			hv[a[i]]++;
		}
		sort(all(b));
		for(int i=0;i<=100;i++){
			for(int x=2;x<=hv[i];x++)b.push_back(i);
		}

		for(int i=0;i<n;i++)cout << b[i] << ' ';
		cout << '\n';	
	}
}