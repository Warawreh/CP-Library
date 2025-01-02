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
	int t;
	cin>>t;
	while(t--){
		int n;
		string s;
		cin>>n>>s;
		int ans = n;
		{
			int cur = 0;
			int len = 0;
			for(int i=0;i<n;i++){
				if((s[i] - '0') != i % 2){
					len++;
				}else{
					if(len)cur++;
					len=0;
				}
			}
			if(len)cur++;
			ans = min(ans , cur);
		}

		{
			int cur = 0;
			int len = 0;
			for(int i=0;i<n;i++){
				if((s[i] - '0') == i % 2){
					len++;
				}else{
					if(len)cur++;
					len=0;
				}
			}
			if(len)cur++;
			
			ans = min(ans , cur);
		}

		
		cout << ans << '\n';
	}
}