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
	vector<int> a(n);
	map<int,int> f;
	for(int i=0;i<n;i++){
		cin>>a[i];
		f[a[i]]++;
	}
	vector<int> ans;
	for(int i : a){
		if(f[i] % 2 == 1)ans.push_back(i);
	}
	sort(all(ans));
	reverse(all(ans));
	for(int i : a){
		if(f[i] % 2!= 1)ans.push_back(i);
	}
	for(int i : ans)cout << i << ' ';
}