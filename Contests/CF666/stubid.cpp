#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
vector<int> a;

int calc(vector<int> a , int lst){
	int win = false;
	for(int i=0;i<a.size();i++){
		if(a[i] == 0 || lst == i)continue;
		a[i]--;
		if(calc(a,i) == false)win = true;
		a[i]++;
	}
	return win;
}

int main(){
	fast
	int t;
	cin>>t;
	cin>>n;
	a.resize(n);
	for(int i=0;i<n;i++)cin>>a[i];
	cout << (calc(a,-1) ? "T" : "HL") << '\n';
}