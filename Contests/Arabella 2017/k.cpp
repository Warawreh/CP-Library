#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int nax = 1e5 + 10;
bool vis[nax];
int at=0;

int main(){
	fast
	int t;
	cin>>t;
	while(t--){
		at++;
		int a,b,n;
		cin>>a>>b>>n;
		
		vector<int> s(10);
		for(ll x=1;;x++){
			if(x * x * a + x * b > n)break;
			int y = x*x*a + x*b;
			if(vis[y] == at)continue;
			vis[y] = at;
			vector<int> o(10);
			int mx = 0;
			while(y){
				o[y % 10]++;
				mx = max(mx , o[y % 10]);
				y /= 10;
			}
			for(int j=0;j<10;j++)if(o[j] == mx)s[j]++;
		}
		int mx = 0;
		for(int i=0;i<10;i++)mx = max(mx , s[i]);
		if(mx == 0)cout << -1 << '\n';
		else{
			for(int j=0;j<10;j++){
				if(s[j] == mx){
					cout << j << '\n';
					break;
				}
			}
		}
	}
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/