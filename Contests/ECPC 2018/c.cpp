#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,m;
vector<int> a,b,c;
vector<vector<ll>> preC,sufC;

const ll oo = 1e18;
const int nax = 2020;
ll dp[nax][nax];

ll calc(ll i, ll j){
	if(i == n){	
		if(j == m)return 0;	
		return oo;
	}

	ll &ret = dp[i][j];
	if(ret != -oo)return ret;
	ret = oo;

	if(j < m){
		if(a[i] == b[j])ret = min(ret , calc(i+1 , j + 1));

		if(((j ? preC[j-1][a[i]] : 0) == 0) || (sufC[j][a[i]] == 0)){
			ret = min(ret , calc(i + 1 , j) + c[i]);
		}
	}

	if(j == m)ret = min(ret , calc(i + 1,j) + c[i]);

	return ret;
}

void solve(){
	scanf("%d %d" , &n,&m);
	
	a = c = vector<int> (n);
	b = vector<int> (m);

	for(int i=0;i<n;i++)scanf("%d" , &a[i]);
	for(int i=0;i<m;i++)scanf("%d" , &b[i]);
	for(int i=0;i<n;i++)scanf("%d" , &c[i]);

	{
		vector<int> f = a;
		sort(all(f));
		f.resize(unique(all(f)) - f.begin());

		for(int i=0;i<n;i++)a[i] = lower_bound(all(f) , a[i]) - f.begin();
		for(int i=0;i<m;i++){
			int at = lower_bound(all(f) , b[i]) - f.begin();
			if(f[at] != b[i]){
				printf("No\n");
				return;
			}
			b[i] = at;
		}

	}

	preC = sufC = vector<vector<ll>>(m,vector<ll>(n));

	for(int i=0;i<m;i++){
		preC[i][b[i]]++;
		if(i){
			for(int j=0;j<n;j++)
				preC[i][j] += preC[i-1][j];
		}
	}

	for(int i=m-1;i>=0;i--){
		sufC[i][b[i]]++;
		if(i+1 < m){
			for(int j=0;j<n;j++)
				sufC[i][j] += sufC[i+1][j];
		}
	}


	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++){
			dp[i][j] = -oo;
		}

	ll ans = calc(0,0);
	if(ans >= oo)printf("No\n");
	else printf("%lld\n",ans);
}

int main(){
	freopen("transform.in","r",stdin);	
	int t;
	scanf("%d" , &t);
	while(t--)solve();
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/