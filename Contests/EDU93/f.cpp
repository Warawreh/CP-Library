#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<vector<int>> pre;
int n;

int solve(int b,int i){
	int lo=i,hi=n-1,to=i;
	while(lo <= hi){
		int md = (lo + hi)/2;
		// if(b == 0 && i == 2){
			// cerr << md << ' ' << pre[!b][md] - (i ? pre[!b][i-1] : 0) << '\n';
		// }
		if(pre[!b][md] - (i ? pre[!b][i-1] : 0) == 0){
			lo = md+1;
			to = md;
		}else hi = md-1;
	}
	return to;
}
int main(){
	fast
	string s;
	cin>>n>>s;
	pre.resize(2,vector<int>(n));
	for(int i=0;i<n;i++){
		if(s[i] != '?')pre[s[i] - '0'][i] = 1;
		if(i){
			pre[0][i] += pre[0][i-1];
			pre[1][i] += pre[1][i-1];
		}
	}
	vector<int> ans(n+1),res(n+1);
	for(int i=0;i<n;i++){
		// cerr << i << ' ';
		if(s[i] == '?'){
			ans[1]++;
			continue;
			int to = solve(0,i);
			// ans[to - i + 1]++;
			// cerr << to << ' ';
			int x = to;
			to = solve(1,i);
			// ans[to - i + 1]++;
			x = max(x , to);
			ans[x - i + 1]++;

		}else{
			int to = solve(s[i] - '0',i);
			ans[to - i + 1]++;
			cerr << to-i+1 << '\n';
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j+=i){
			res[i] += ans[j];
		}
	}
	for(int i=0;i<n;i++)cout << res[i+1] << ' ';
	cout << '\n';
}