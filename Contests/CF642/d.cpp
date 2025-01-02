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
		cin>>n;
		vector<int> ans;
		int T = 1;
		ans = vector<int>(n,0);
		priority_queue<pair<int,int>> q;
		q.push({n,0});
		while(q.size()){
			int len = q.top().first;
			int l = -q.top().second;
			q.pop();
			if(!len)continue;
			int r = l + len - 1;
			int md = (l + r)/2;
			ans[md] = T++;
			if(len == 1){
				continue;
			}else if(len % 2 == 0){
				q.push({(len - 1)/2,-l});
				q.push({len/2,-(l+(len+1)/2)});
			}else if(len % 2 == 1){
				q.push({len/2,-l});
				q.push({len/2,-(l+(len+1)/2)});
			}
		}
		for(int i : ans)cout << i << ' ';
		cout << '\n';
	}
}