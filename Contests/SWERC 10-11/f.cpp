#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,m;
vector<int> g;
const int nax = 22;

int main(){
	fast
	
	while(1){
		cin>>n>>m;
		if(n==0&&m==0)break;
		g.clear();
		g.resize(n);
		for(int i=0;i<m;i++){
			int u,v;
			cin>>u>>v;
			g[u] |= (1<<v);
			g[v] |= (1<<u);
		}

		vector<int> dp((1<<n),-1),fr((1<<n) , -1),frM((1<<n), -1);

		vector<int> q;
		int st = (1<<n) - 1;
		dp[st] = 0;
		q.push_back(st);
		int qh=0;
		for(qh=0;qh<q.size();qh++){
			int m = q[qh];
			for(int i=0;i<n;i++){
				int newM = 0;
		 
				for(int j=0;j<n;j++){
					if(j == i || ((m >> j) & 1) == 0)continue;
					newM |= g[j];
				}
				if(dp[newM] != -1)continue;
				dp[newM] = dp[m] + 1;
				fr[newM] = i;
				frM[newM] = m;
				q.push_back(newM);
			}
		}

		int res = dp[0];
		if(res == -1){
			cout << "Impossible\n";
		}
		else{
			vector<int> p;

			int at = 0;
			while(at != st){
				p.push_back(fr[at]);
				at = frM[at];
			}

			assert(m == n-1);
			cout << res << ":";
			for(int i=p.size() -1;i>=0;i--)
				cout << ' ' << p[i];
			cout << '\n';
		}
	}
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/