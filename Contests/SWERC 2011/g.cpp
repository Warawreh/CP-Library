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
	while(1){
		int n;
		cin>>n;
		if(n == 0)break;
		vector<int> pre(n);
		for(int i=0;i<n;i++){
			int a;
			cin>>a;
			pre[i] = a;
			if(i)pre[i] += pre[i-1];
		}
		vector<int> to(n);
		int at=n-1;
		for(int i=n-1;i>=0;i--){
			if(pre[i] < pre[at])at = i;
			to[i] = at;
		}

		int taken = 0;
		int ans = 0;
		int mn = 2e9;
		if(pre[to[0]] >= 0)ans++;

		for(int i=0;i<n - 1;i++){
			taken += pre[i] - (i ? pre[i-1] : 0LL);
			mn -= pre[i] - (i ? pre[i-1] : 0LL);
			mn = min(mn , pre[n-1]);
			if(mn >= 0 && pre[to[i+1]] - taken >= 0)ans++;
		}
		cout << ans << '\n';
	}
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/