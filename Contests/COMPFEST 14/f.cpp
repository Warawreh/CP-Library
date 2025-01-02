#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(){
	int n;
	scanf("%d",&n);
	vector<pair<int,int>> p(n);
	for(int i=0;i<n;i++){
		scanf("%d %d",&p[i].first , &p[i].second);
		p[i].first--;
		p[i].second--;
	}

	vector<int> ans(31,0);
	for(int k=0;k<30;k++){
		int cur = (1LL << k);

		int cnt = 0;
		vector<pair<int,int>> e;
		for(int i=0;i<n;i++){
			int l = p[i].first % cur;
			int r = l + (p[i].second - p[i].first) + 1;
			if(p[i].second - p[i].first + 1 >= cur){
				cnt++;
				continue;
			}


			if(r > cur){
				e.push_back({l,1});
				e.push_back({0,1});
				e.push_back({r - cur , -1});
			}else{
				e.push_back({l,1});
				e.push_back({r,-1});
			}
			// e[l]++;
			// e[r]--;
		}

		sort(all(e));
		int mx = cnt;
		for(auto &it : e){
			cnt += it.second;
			mx = max(mx , cnt);
		}
		ans[k] = mx;
	}

	int q;
	scanf("%d",&q);
	while(q--){
		int x;
		scanf("%d",&x);
		int at = 0;
		while(x % 2 == 0){
			x/=2;
			at++;
		}
		printf("%d\n", ans[at]);
	}
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/