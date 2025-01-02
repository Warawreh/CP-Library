#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;

void solve(int C){
	int n;
	string s;
	cin>>n>>s;
	int ans = 0;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			int len = j-i+1;
			for(int l =i;l<=j;l++){
				ans += int(s[l]) * len;
				ans%=mod;
			}
		}
	}
	printf("Case %d: %d\n", C , ans);
}

int main(){
	freopen("input.txt" , "r" , stdin); // Remove Before Submit
	int t;
	cin>>t;
	int cnt=0;
	while(t--){
		solve(++cnt);
	}	
}