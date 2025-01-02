#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int nax = 1e6 + 10;

bool nprime[nax];
pair<int,bool> p[nax];
int pre[nax];

void solve(int C){

	int n;
	cin>>n;
	printf("Case %d: ", C);
	int ans = n - pre[n];
	int a = __gcd(n,ans);
	printf("%d/%d\n", ans/a ,n/a);
}

int main(){
	cout.precision(10);
	cout << fixed;
	// freopen("input.txt" , "r" , stdin); // Remove Before Submit
	int t;
	cin>>t;
	int cnt=0;

	for(int i=2;i<nax;i++){
		for(int j=i+i;j<nax;j+=i){
			nprime[j] = 1;
			if(nprime[i])pre[j]=1;
		}
	}
	for(int i=1;i<nax;i++){
		pre[i] += pre[i-1];
	}

	while(t--){
		solve(++cnt);
	}
}