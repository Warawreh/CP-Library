#include <bits/stdc++.h>

using namespace std;

#define debug(x) '[' << #x << " is: " << x << "] "
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(10);
	cout << fixed;
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("d_quite_big.in","r",stdin);
		// freopen("d_quite_big.out","w",stdout);
	#endif
	int m,n;
	cin>>m>>n;
	ll sum=0;
	vector<int> a(n);
	int l=0,dif=1e9;
	pair<int,int> ans;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
		while(l<i && sum > m){
			sum-=a[l++];
		}	
		if(m-sum < dif){
			dif = m-sum;
			ans = {l,i};
		}
	}
	cout << ans.second-ans.first+1 << '\n';
	for(int i =ans.first;i<=ans.second;i++)cout << i << ' ';
	cout << '\n';
}