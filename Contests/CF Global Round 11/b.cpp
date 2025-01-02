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
		int ans = 0;
		vector<int> len;
		int lst = -1;
		int l = 0;
		for(int i=0;i<n;i++){
			if(s[i] == 'W'){
				if(i && s[i - 1] == 'W'){
					ans += 2;
					lst = i;
				}
				else{
					if(lst == -1)lst = i;
					else{
						len.push_back(i - lst - 1);
					}
					lst = i;
					ans++;
				}
			}else l++;
		}
		k = min(k , l);
		sort(all(len));
		for(int i=0;i<len.size();i++){
			if(!k)break;
			int take = min(len[i] , k);
			ans += take * 2;
			if(take == len[i]){
				ans++;
			}
			k -= take;
		}
		
		if(ans == 0 && k){
			k--;
			ans++;
		}
		ans += k * 2;
		cout << ans << '\n';
	}
}