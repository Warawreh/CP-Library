#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int> prime;
vector<bool> is_composite;

void sieve (int n) {
	is_composite = vector<bool>(n+1);
	for(int i = 2;i <= n;i++){
		if(is_composite[i] == 0) prime.push_back (i);
		for(int j=0;j<prime.size() && i * prime[j] <= n;++j) {
			is_composite[i * prime[j]] = true;
			if (i % prime[j] == 0) break;
		}
	}
}

vector<vector<int>> up;

int main(){
    fast
    sieve(400);
    up.resize(1e5 + 10);

    for(int i=2;i<=1e5;i++){
 		int t = i;
 		for(int j : prime){
 			if(t % j == 0){
 				up[i].push_back(j);
 				while(t % j == 0)t /= j;
 			}
 		}
 		if(t > 1)up[i].push_back(t);
 	}   

    int n,q;
    cin>>n>>q;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];

    vector<vector<pair<int,int>>> event(q);
	for(int i=0;i<q;i++){
		int c,d;
		cin>>c>>d;
		event[i].push_back({c , d});
	}

	vector<vector<int>> que(n);
	for(int i=0;i<n;i++){
		que[i] = {0,q-1 , -1};
	}

	while(1){
		vector<vector<int>> e(q);
		vector<ll> move(1e5 + 2,0);
		int rem = 0;
		for(int i=0;i<n;i++){
			if(que[i][0] > que[i][1])continue;
			rem++;
			int md = (que[i][0] + que[i][1])/2;
			e[md].push_back(i+1);
		}
		if(rem == 0)break;
		for(int i=0;i<q;i++){

			for(auto &[c,d] : event[i]){

				vector<int> &pr = up[c];
				int sz = pr.size();
				for(int msk=1;msk<(1 << sz);msk++){
					ll cur = 1;
					for(int j=0;j<sz;j++){
						if((msk >> j) & 1){
							cur *= pr[j];
						}
					}
					move[cur] += d;
				}

			}

			for(auto &id : e[i]){
				int &need = a[id-1];
				vector<int> &pr = up[id];
				int sz = pr.size();
				ll tot = 0;
				for(int msk=1;msk<(1 << sz);msk++){
					ll cur = 1;
					int cnt = 0;
					for(int j=0;j<sz;j++){
						if((msk >> j) & 1){
							cur *= pr[j];
							cnt++;
						}
					}

					if(cnt % 2 == 1)tot += move[cur];
					else tot -= move[cur];
				}
				// if(i == 2)cerr << id << ' ' << need << '\n';

				if(tot >= need){
					que[id-1][1] = i-1;
					que[id-1][2] = i + 1;
				}else que[id-1][0] = i + 1;
			}			

		}
	}

	for(int i=0;i<n;i++){
		cout << que[i][2] << '\n';
	}
}
