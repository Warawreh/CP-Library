#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
	int n,m;
	cin>>n>>m;
	vector<int> asked(n);
	vector<vector<int>> av(m);
	vector<int> play(m);
	int mx = (m + 1)/2;
	for(int i=0;i<m;i++){
		int k;
		cin>>k;
		av[i].resize(k);
		for(int j=0;j<k;j++){
			cin>>av[i][j];
			av[i][j]--;
		}
		if(k == 1){
			asked[av[i][0]]++;
			play[i] = av[i][0] + 1;
		}
	}
	for(int i=0;i<n;i++){
		if(asked[i] > mx){
			cout << "NO\n";
			return;
		}
	}
	for(int i=0;i<m;i++){
		if(av[i].size() == 1)continue;
		bool f= false;
		for(int j=0;j<av[i].size();j++){
			if(asked[av[i][j]] + 1 <= mx){
				asked[av[i][j]]++;
				play[i] = av[i][j] + 1;
				f = 1;
				break;
			}
		}
		if(!f){
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
	for(int i : play)
		cout << i << ' ';
	cout << '\n';
}

int main(){
	fast
	int t;
	cin>>t;
	while(t--){
		solve();

	}
}