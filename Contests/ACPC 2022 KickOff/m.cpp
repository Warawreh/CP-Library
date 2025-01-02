#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int nax = 1e7 + 10;
int cost[nax];

int main(){
	fast
	freopen("shop.in","r",stdin);	
	cost[1] = 1;
	cost[2] = 2;
	for(int i=2;i<nax;i++){
		if(cost[i] == 0)cost[i] = i;
		cost[i] = min(cost[i] , i);
		for(int j=i;j<nax;j+=i){
			int v = j / i;
			if(v > i)break;
			if(cost[j] == 0)cost[j] = j;
			cost[j] = min(cost[j] , cost[v] + cost[i]);
		}
	}

	// for(int i=1;i<=12;i++)
	// 	cerr << cost[i] << ' ';
	// cerr << '\n';
	// return 0;

	int t;
	cin>>t;
	while(t--){
		int n,x;
		cin>>n>>x;
		vector<int> need(n);
		for(int i=0;i<n;i++){
			int a;
			cin>>a;
			need[i] = cost[a];
		}
		sort(all(need));
		int ans = 0;
		for(int i=0;i<n;i++){
			if(x - need[i] >= 0){
				x -= need[i];
				ans++;
			}else break;
		}
		cout << ans << '\n';
	}
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/