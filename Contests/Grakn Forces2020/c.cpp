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
	int tt;
	cout << setprecision(12) << fixed;
	cin>>tt;
	while(tt--){
		int n,l;
		cin>>n>>l;
		vector<int> a(n+2);
		a[0] = 0;
		for(int i=1;i<=n;i++)cin>>a[i];
		a[n+1] = l;
		ld lo = 0,hi= l,ans=l;
		n+=2;
		for(int it=0;it<50;it++){
			ld md = (lo + hi) / 2;
			ld at_a = 0,at_b = l;
			{
				ld s = 1,tmp = md;
				for(int i=1;i<n;i++){
					ll dist = a[i] - a[i-1];
					ld time = dist / s;
					if(tmp >= time){
						tmp -= time;
						s++;
						at_a = a[i];
					}else{
						at_a += s * tmp;
						break;
					}
				}
			}
			reverse(all(a));

			{
				ld s = 1,tmp = md;
				for(int i=1;i<n;i++){
					ll dist = a[i-1] - a[i];
					ld time = dist / s;
					if(tmp >= time){
						tmp -= time;
						s++;
						at_b = a[i];
					}else{
						at_b -= s * tmp;
						break;
					}
				}
			}
			reverse(all(a));

			if(at_a >= at_b){
				hi = md;
				ans = md;
			}else{
				lo = md;
			}
		}
		cout << ans << '\n';
	}
}