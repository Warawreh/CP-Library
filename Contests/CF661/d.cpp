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
		vector<int> type[2];
		vector<int> ans;
		int t = 0;
		for(int i=0;i<n;i++){
			int b = s[i] - '0';
			if(type[!b].empty()){
				type[b].push_back(++t);
				ans.push_back(t);
			}else{
				int r = type[!b].back();
				ans.push_back(r);
				type[!b].pop_back();
				type[b].push_back(r);
			}
		}
		cout << t << '\n';
		for(int i : ans)cout << i << ' ';
		cout << '\n';
	}
}