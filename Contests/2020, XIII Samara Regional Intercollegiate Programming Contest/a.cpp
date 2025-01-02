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
	ll sum = 0;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		sum += x * ((n-i-1)%2 == 0 ? 1 : -1);
	}
	int q;
	cin>>q;
	while(q--){
		int l,r,val;
		cin>>l>>r>>val;
		if(l % 2 != r % 2)val = 0;
		else if((n - l)%2 == 1)val = -val;
		sum += val;
		cout << sum << '\n';
	}
}