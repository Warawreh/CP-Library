#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int nax = 1e5 + 10;
const int oo = 1e6;

int best;
int dp[nax][2][2];
int n;
vector<int> a;

void clean(){
	for(int i=0;i<nax;i++)for(int j=0;j<2;j++)dp[i][j][0] = dp[i][j][1] = -1e9;
}

int calc(int idx,int mx,int movn){
	if(idx == n){
		if(mx)return 0;
		else return -oo;
	}
	int &ret = dp[idx][mx][movn];
	if(ret != -1e9)return ret;
	ret = -oo;
	if(mx)ret = 0;
	if(a[idx] > best && movn)return ret;
	if(movn){
		int give = a[idx];
		if(a[idx] == best && !mx){
			give = 0;
			mx = 1;
		}
		ret = max(ret , calc(idx+1,mx , movn) + give);
	}else{
		assert(mx == 0);

		ret = max(ret , calc(idx+1,0,0));

		if(a[idx] <= best){
			int give = a[idx];
			if(a[idx] == best && !mx){
				give = 0;
				mx = 1;
			}
			ret = max(ret , calc(idx+1,mx , 1) + give);
		}
	}
	// if(best == 5){
	// 	cerr << idx << ' ' << mx << ' ' << movn << ' ' << ret << '\n';
	// }
	return ret;
}

int main(){
	fast
	cin>>n;
	a = vector<int>(n);
	for(int i=0;i<n;i++)cin>>a[i];
	int ans = 0;
	for(int i=-30;i<=30;i++){
		best = i;
		clean();
		ans = max(ans , calc(0,0,0));
	}
	cout << ans << '\n';
}