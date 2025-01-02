#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e6+10;
const int mod = 998244353;

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//Functions:-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
int main(){
ios::sync_with_stdio(false);
cin.tie(0);
cout.precision(10);
cout << fixed;
	freopen("game.in" , "r" , stdin );
	int q;cin>>q;
	while(q--){
		int n;cin>>n;
		ll s = 1e18,sum = 0;
		for(int i = 0;i<n;i++){
			ll x;cin>>x;
			sum+=x;
			s = min(s,x);
		}
		cout<<sum + (s * (n - 2))<<endl;
	}
}