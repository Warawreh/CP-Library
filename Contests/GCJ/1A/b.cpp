#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int> a;
vector<vector<int>> dp;
int sum = 0;

int calc(int i,int v){
	if(v > sum)return 0;
	if(i == a.size()){
		// cerr << v << ' ' << sum << '\n';
		if(v == sum)return 1;
		else return 0;
	}
	int &ret = dp[i][v];
	if(ret != -1)return ret;
	if(calc(i+1,(v+1)*a[i]) != 0)cerr << a[i] << ' ' << a[i] * calc(i+1,(v+1)*a[i]) << '\n';
	ret = max(calc(i + 1 , v) , a[i] * calc(i+1,(v+1)*a[i]));
	return ret;
}

void solve(){
	int m;
	cin>>m;
	a.clear();
	sum = 0;
	for(int i=0;i<m;i++){
		int p,c;
		cin>>p>>c;
		for(int j=0;j<c;j++){
			a.push_back(p);
			sum += p;
		}
	}
	dp = vector<vector<int>>(a.size() , vector<int> (500 * a.size(),-1));
	cout << max(0,calc(0,1)) << '\n';
}

int main(){
	fast
	int t;
	cin>>t;
	for(int T=1;T<=t;T++){
		cout << "Case #" << T << ": ";
		solve();
	}
}