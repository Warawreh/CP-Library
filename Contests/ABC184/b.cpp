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
	int n,x;
	string s;
	cin>>n>>x>>s;
	for(int i=0;i<n;i++){
		if(s[i] == 'o')x++;
		else x--;
		x = max(x , 0);
	}
	cout << x << '\n';
}