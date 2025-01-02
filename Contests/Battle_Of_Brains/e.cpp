#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

void solve(int C){
	ll d,x;
	cin>>d>>x;
	ll sum = 0;
	ll have = 0;
	int ans = -1;
	for(ll k = d;k>=0;k--){
		sum += (1ll<<k);
		have += (1ll<<(k+1));
		if(sum == x){
			ans = d-k+1;
			break;
		}
		if(sum > x){
			ll need = sum - x;
			if((need & have) == need){
				ans = d-k+1;
				break;
			}
		}
	}
	if(x == 0)ans = 0;
	printf("Case %d: ", C);
	if(ans == -1)printf("NO\n");
	else printf("YES %d\n", ans);
}

int main(){
	cout.precision(10);
	cout << fixed;
	// freopen("input.txt" , "r" , stdin); // Remove Before Submit
	int t;
	cin>>t;
	int cnt=0;
	while(t--){
		solve(++cnt);
	}
}