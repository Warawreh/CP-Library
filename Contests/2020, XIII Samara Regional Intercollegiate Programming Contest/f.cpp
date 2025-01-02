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
	cout << n/2 + 1 << '\n';
	for(int i=1;i<=n;i+=2){
		cout << i << ' ';
	}
	if(n%2 == 0)cout << n;
	cout << '\n';
}