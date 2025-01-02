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
		int n,k;
		string s;
		cin>>n>>k>>s;
		int l=0,r=0;
		int ans = 0,hv=0;
		for(;r<k;r++){
			if(s[r] == '1')hv++;
		}
		for(int i=0;i<n;i++){
			if(r < n){
				if(s[r] == '1')hv++;
				r++;
			}
			if(hv == 0 && s[i] == '0'){
				ans++;
				s[i] = '1';
				hv++;
			}
			if(i-k == l){
				if(s[l] == '1')hv--;
				l++;
			}
		}
		cout << ans << '\n';
	}
}