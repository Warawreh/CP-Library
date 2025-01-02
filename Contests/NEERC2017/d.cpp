#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e6+10;
const int mod = 998244353;
typedef unsigned long long ull;

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//Functions:-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(10);
	cout << fixed;

	ull n;cin>>n;
	vector<ull> num;
	for(ull i=0;i<n;i++){
		ull x;cin>>x;
		if(x >= 128)
			num.push_back(x - 128);
		else{
			num.push_back(x);
			ull ans = 0;
			for(ull i = 0;i<num.size();i++)
				ans += (num[i]<<(7*i));
			cerr << ans << '\n';
			if(ans%2 == 0){
				ans = (ans>>1);
				cout<<ans<<endl;
			}else{
				ans /= 2;
				ans++;
				cout<< '-'<<ans<<endl;
			}
			num.clear();
		}
	}
	
}

//