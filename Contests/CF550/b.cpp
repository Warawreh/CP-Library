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
	int n;
	cin>>n;
	vector<vector<int>> a(2);
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		a[x%2].push_back(x);
	}
	int take = n - min(n , min((int)a[0].size() , (int)a[1].size()) * 2 + 1);
	ll sum = 0;
	sort(all(a[0]));
	sort(all(a[1]));
	if(a[0].size() > a[1].size()){
		for(int i=0;i<take;i++)sum+=a[0][i];
	}else{
		for(int i=0;i<take;i++)sum+=a[1][i];
	}
	cout << sum << '\n';	
}