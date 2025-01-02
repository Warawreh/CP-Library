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
	vector<bool> good(33);
	for(int i=0;i<10;i++){
		int a;
		cin>>a;
		good[a] = true;
	}
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int lucky = 0;
		for(int j=0;j<6;j++){
			int a;
			cin>>a;
			lucky += good[a];
		}
		cout << (lucky < 3 ? "Unlucky" : "Lucky") << '\n';
	}
}