#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(4);
	cout << fixed;
	// freopen("input.txt" , "r" , stdin); // Remove Before Submit
	int q;
	cin>>q;
	int cnt=0;
	while(q--){
		cnt++;
		ld x,y,z;
		cin>>x>>y;
		z = x/y;
		ld a = pow(z,1/3.0),b =pow(3.0/(4.0*acos(-1))*z,1/3.0);
		cout << "Case " << cnt << ": "<<min(6*a*a,b*b*4*acos(-1))<<endl;
	}
}