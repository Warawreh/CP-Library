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
	vector<ll> ans;
	for(int i=0;i<n;i++){
		ll a;
		cin>>a;
		ans.push_back(a);
		while(ans.size() > 1){
			if(ans.back() < 0){
				ll b = ans.back();
				ans.pop_back();
				ans.back()+=b;
			}else break;
		}
		
	}
	while(ans.size() > 1 && ans.back() == 0)ans.pop_back();
	for(ll a : ans)cout << a << ' ';
}