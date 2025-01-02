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
		string s;
		int m;
		cin>>s>>m;
		vector<pair<int,int>> o(m);
		for(int i=0;i<m;i++){
			cin>>o[i].first;
			o[i].second = i;
		}
		sort(all(s));
		reverse(all(s));
		vector<int> h(26);
		int n = s.size();
		for(int i=0;i<s.size();i++)h[s[i] - 'a']++;
		string ans(m,'1');
		
		for(int i=25;i>=0;i--){
			int z=0;
			for(int j=0;j<m;j++){
				if(ans[j] == '1')
					z+=o[j].first == 0;
			}
			if(z > h[i])continue;
			vector<int> w;
			for(int j=0;j<m;j++){
				if(o[j].first == 0 && ans[j] == '1'){
					ans[j] = char('a' + i);
					w.push_back(j);
				}
			}

			for(int j : w){
				for(int x=0;x<m;x++){
					if(o[x].first){
						o[x].first -= abs(x - j);
					}
					assert(o[x].first >= 0);
				}
			}

		}
		cout << ans << '\n';
	}
}